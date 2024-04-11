#include<algorithm>
#include<map>
#include<vector>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n;
char s[maxn];
struct node{
	int l,r;
	node* ch[2];
	int sum;
	node(int l,int r):l(l),r(r),sum(0){
		ch[0]=ch[1]=0;
	}
	void modify(int x,int k){
		sum+=k;
		if(l<r){
			int mid=l+(r-l)/2;
			if(x<=mid){
				if(!ch[0]) ch[0]=new node(l,mid);
				ch[0]->modify(x,k);
			}
			else{
				if(!ch[1]) ch[1]=new node(mid+1,r);
				ch[1]->modify(x,k);
			}
		}
	}
	int query(int ql,int qr){
		if(ql<=l&&qr>=r) return sum;
		else{
			int ans=0;
			if(ch[0]&&ql<=ch[0]->r) ans+=ch[0]->query(ql,qr);
			if(ch[1]&&qr>=ch[1]->l) ans+=ch[1]->query(ql,qr);
			return ans;
		}
	}
};
node* merge(node* a,node* b){
	if(!a) return b;
	if(!b) return a;
	node* x=new node(a->l,a->r);
	x->sum=a->sum+b->sum;
	x->ch[0]=merge(a->ch[0],b->ch[0]);
	x->ch[1]=merge(a->ch[1],b->ch[1]);
	return x;
}
node* rt[maxn*2];
int sz,last,link[maxn*2],len[maxn*2],pos[maxn*2];
map<char,int> nxt[maxn*2];
vector<int> ch[maxn*2];
void init(){
	sz=1;
	last=0;
	link[0]=-1;
	len[0]=0;
	rt[0]=new node(0,n);
	rt[0]->modify(0,1);
	pos[0]=0;
}
void extend(char c){
	int cur=sz++;
	len[cur]=len[last]+1;
	rt[cur]=new node(0,n);
	rt[cur]->modify(len[cur],1);
	pos[cur]=len[cur];
	int p=last;
	while(p>=0&&!nxt[p].count(c)){
		nxt[p][c]=cur;
		p=link[p];
	}
	if(p<0) link[cur]=0;
	else{
		int q=nxt[p][c];
		if(len[p]+1==len[q]) link[cur]=q;
		else{
			int clone=sz++;
			len[clone]=len[p]+1;
			link[clone]=link[q];
			nxt[clone]=nxt[q];
			rt[clone]=0;
			pos[clone]=0;
			while(p>=0&&nxt[p][c]==q){
				nxt[p][c]=clone;
				p=link[p];
			}
			link[q]=link[cur]=clone;
		}
	}
	last=cur;
}
void dfs1(int u){
	for(int i=0;i<ch[u].size();i++){
		int v=ch[u][i];
		dfs1(v);
		rt[u]=merge(rt[u],rt[v]);
		pos[u]=max(pos[u],pos[v]);
	}
}
int d[maxn*2],c[maxn*2];
void dfs2(int u){
	if(u==0){
		d[u]=0;
		c[u]=0;
	}
	else{
		int v=c[link[u]];
		if(rt[v]->query(pos[u]-len[u]+len[v],pos[u])>=2){
			d[u]=d[link[u]]+1;
			c[u]=u;
		}
		else{
			d[u]=d[link[u]];
			c[u]=v;
		}
	}
	for(int i=0;i<ch[u].size();i++) dfs2(ch[u][i]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	scanf("%s",s);
	init();
	for(int i=0;i<n;i++)  extend(s[i]);
	for(int i=1;i<sz;i++) ch[link[i]].push_back(i);
	dfs1(0);
	dfs2(0);
	int ans=0;
	for(int i=0;i<sz;i++) ans=max(ans,d[i]);
	printf("%d\n",ans);
	return 0;
}