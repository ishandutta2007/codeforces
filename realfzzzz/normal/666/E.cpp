#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
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
const int maxn=5e5+5,maxm=5e4+5;
int n,m,q;
char s[maxn],t[maxm];
typedef pair<int,int> pii;
struct node{
	int l,r;
	node* ch[2];
	pii v;
	void pushup(){
		v=pii(0,-l);
		if(ch[0]) v=max(v,ch[0]->v);
		if(ch[1]) v=max(v,ch[1]->v);
	}
	node(int l,int r):l(l),r(r),v(pii(0,-l)){
		ch[0]=ch[1]=0;
	}
	void modify(int x){
		if(l==r) v.first++;
		else{
			int mid=l+(r-l)/2;
			if(x<=mid){
				if(!ch[0]) ch[0]=new node(l,mid);
				ch[0]->modify(x);
			}
			else{
				if(!ch[1]) ch[1]=new node(mid+1,r);
				ch[1]->modify(x);
			}
			pushup();
		}
	}
	pii query(int ql,int qr){
		if(ql<=l&&qr>=r) return v;
		else{
			pii ans(0,-ql);
			if(ch[0]&&ql<=ch[0]->r) ans=max(ans,ch[0]->query(ql,qr));
			if(ch[1]&&qr>=ch[1]->l) ans=max(ans,ch[1]->query(ql,qr));
			return ans;
		}
	}
};
node* merge(node* a,node* b){
	if(!a) return b;
	if(!b) return a;
	node* x=new node(a->l,a->r);
	if(x->l==x->r){
		x->v.first=a->v.first+b->v.first;
		x->v.second=-x->l;
	}
	else{
		x->ch[0]=merge(a->ch[0],b->ch[0]);
		x->ch[1]=merge(a->ch[1],b->ch[1]);
		x->pushup();
	}
	return x;
}
int sz,last,len[maxm*4],link[maxm*4];
map<char,int> nxt[maxm*4];
vector<int> ch[maxm*4];
void init(){
	sz=1;
	last=0;
	len[0]=0;
	link[0]=-1;
}
int extend(char c){
	int cur=sz++;
	len[cur]=len[last]+1;
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
			while(p>=0&&nxt[p][c]==q){
				nxt[p][c]=clone;
				p=link[p];
			}
			link[q]=link[cur]=clone;
		}
	}
	return last=cur;
}
node* rt[maxm*4];
int cur[maxn],mx[maxn];
int size[maxm*4],hson[maxm*4];
void dfs1(int u){
	size[u]=1;
	hson[u]=-1;
	for(int i=0;i<(int)ch[u].size();i++){
		int v=ch[u][i];
		dfs1(v);
		rt[u]=merge(rt[u],rt[v]);
		size[u]+=size[v];
		if(hson[u]<0||size[v]>size[hson[u]]) hson[u]=v;
	}
}
int pos[maxm*4],top[maxm*4];
vector<int> f;
void dfs2(int u){
	pos[u]=f.size();
	f.push_back(u);
	if(hson[u]>=0){
		top[hson[u]]=top[u];
		dfs2(hson[u]);
	}
	for(int i=0;i<(int)ch[u].size();i++){
		int v=ch[u][i];
		if(v==hson[u]) continue;
		top[v]=v;
		dfs2(v);
	}
}
int find(int u,int x){
	while(top[u]){
		if(len[link[top[u]]]<x) break;
		u=link[top[u]];
	}
	int l=pos[top[u]],r=pos[u];
	while(l<r){
		int mid=l+(r-l)/2;
		if(len[f[mid]]>=x) r=mid;
		else l=mid+1;
	}
	return f[r];
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	m=readint();
	init();
	for(int i=1;i<=m;i++){
		scanf("%s",t);
		int l=strlen(t);
		for(int j=0;j<l;j++){
			int cur=extend(t[j]);
			rt[cur]=new node(1,m);
			rt[cur]->modify(i);
		}
		extend('#');
	}
	int u=0,l=0;
	for(int i=1;i<=n;i++){
		while(u>=0&&!nxt[u].count(s[i])){
			u=link[u];
			if(u>=0) l=len[u];
		}
		if(u<0){
			cur[i]=u=0;
			mx[i]=l=0;
			continue;
		}
		cur[i]=u=nxt[u][s[i]];
		mx[i]=++l;
	}
	for(int i=1;i<sz;i++) ch[link[i]].push_back(i);
	dfs1(0);
	dfs2(0);
	q=readint();
	while(q--){
		int pl,pr,l,r;
		l=readint();
		r=readint();
		pl=readint();
		pr=readint();
		if(pr-pl+1>mx[pr]){
			printf("%d %d\n",l,0);
			continue;
		}
		pii ans=rt[find(cur[pr],pr-pl+1)]->query(l,r);
		printf("%d %d\n",-ans.second,ans.first);
	}
	return 0;
}