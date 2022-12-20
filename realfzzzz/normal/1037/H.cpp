#include<bits/stdc++.h>
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
const int maxn=1e5+5,maxq=2e5+5;
int n,q;
char s[maxq];
int sz=1,last=0,len[maxn*2],link[maxn*2],nxt[maxn*2][26];
vector<int> ch[maxn*2];
void extend(int c){
	int cur=sz++;
	len[cur]=len[last]+1;
	int p=last;
	while(p>=0&&!nxt[p][c]){
		nxt[p][c]=cur;
		p=link[p];
	}
	if(p>=0){
		int q=nxt[p][c];
		if(len[p]+1==len[q]) link[cur]=q;
		else{
			int clone=sz++;
			link[clone]=link[q];
			memcpy(nxt[clone],nxt[q],sizeof(nxt[0]));
			len[clone]=len[p]+1;
			while(p>=0&&nxt[p][c]==q){
				nxt[p][c]=clone;
				p=link[p];
			}
			link[cur]=link[q]=clone;
		}
	}
	last=cur;
}
int cur[maxn];
struct node{
	int l,r;
	node* ch[2];
	bool s;
	node(int l,int r):l(l),r(r),s(0){
		ch[0]=ch[1]=0;
	}
	void insert(int x){
		s=1;
		if(l==r) return;
		int mid=l+(r-l)/2;
		if(x<=mid){
			if(!ch[0]) ch[0]=new node(l,mid);
			ch[0]->insert(x);
		}
		else{
			if(!ch[1]) ch[1]=new node(mid+1,r);
			ch[1]->insert(x);
		}
	}
	bool query(int ql,int qr){
		if(ql<=l&&qr>=r) return s;
		int mid=l+(r-l)/2;
		bool ans=0;
		if(ql<=mid&&ch[0]) ans|=ch[0]->query(ql,qr);
		if(qr>mid&&ch[1]) ans|=ch[1]->query(ql,qr);
		return ans;
	}
};
node* merge(node* a,node* b){
	if(!a) return b;
	if(!b) return a;
	node* x=new node(a->l,a->r);
	x->s=a->s||b->s;
	x->ch[0]=merge(a->ch[0],b->ch[0]);
	x->ch[1]=merge(a->ch[1],b->ch[1]);
	return x;
}
node* rt[maxn*2];
void dfs(int u){
	for(int v:ch[u]){
		dfs(v);
		rt[u]=merge(rt[u],rt[v]);
	}
}
int c[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	link[0]=-1;
	for(int i=1;i<=n;i++){
		extend(s[i]-'a');
		cur[i]=last;
	}
	for(int i=1;i<sz;i++) ch[link[i]].push_back(i);
	for(int i=1;i<=n;i++){
		rt[cur[i]]=new node(1,n);
		rt[cur[i]]->insert(i);
	}
	dfs(0);
	int q=readint();
	while(q--){
		int l,r;
		l=readint();
		r=readint();
		scanf("%s",s+1);
		int lt=strlen(s+1),now=1;
		for(;now<=lt;now++){
			if(!nxt[c[now-1]][s[now]-'a']) break;
			c[now]=nxt[c[now-1]][s[now]-'a'];
			if(l+now-1>r||!rt[c[now]]->query(l+now-1,r)) break;
		}
		bool ok=0;
		for(;!ok&&now>0;now--) for(int i=now<=lt?s[now]-'a'+1:0;i<26;i++){
			if(!nxt[c[now-1]][i]) continue;
			int u=nxt[c[now-1]][i];
			if(l+now-1>r||!rt[u]->query(l+now-1,r)) continue;
			for(int j=1;j<now;j++) printf("%c",s[j]);
			printf("%c\n",i+'a');
			ok=1;
			break;
		}
		if(!ok) printf("-1\n");
	}
	return 0;
}