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
const int maxn=3e5+5;
int n;
vector<int> ch1[maxn],ch2[maxn];
int fa1[maxn],fa2[maxn],size[maxn],hson[maxn];
void dfs1(int u){
	size[u]=1;
	hson[u]=0;
	for(int v:ch2[u]){
		dfs1(v);
		size[u]+=size[v];
		if(size[v]>size[hson[u]]) hson[u]=v;
	}
}
int cnt,pos[maxn],top[maxn];
void dfs2(int u){
	pos[u]=cnt++;
	if(!hson[u]) return;
	top[hson[u]]=top[u];
	dfs2(hson[u]);
	for(int v:ch2[u]){
		if(v==hson[u]) continue;
		top[v]=v;
		dfs2(v);
	}
}
struct node{
	int l,r;
	node* ch[2];
	int mn=n,cnt,add=0;
	void pushup(){
		if(ch[0]->mn<ch[1]->mn){
			mn=ch[0]->mn;
			cnt=ch[0]->cnt;
		}
		else if(ch[1]->mn<ch[0]->mn){
			mn=ch[1]->mn;
			cnt=ch[1]->cnt;
		}
		else{
			mn=ch[0]->mn;
			cnt=ch[0]->cnt+ch[1]->cnt;
		}
	}
	node(int l,int r):l(l),r(r),cnt(r-l+1){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void pushtag(int k){
		mn+=k;
		add+=k;
	}
	void pushdown(){
		ch[0]->pushtag(add);
		ch[1]->pushtag(add);
		add=0;
	}
	void modify(int ql,int qr,int k){
		if(ql<=l&&qr>=r){
			pushtag(k);
			return;
		}
		pushdown();
		if(ql<=ch[0]->r) ch[0]->modify(ql,qr,k);
		if(qr>=ch[1]->l) ch[1]->modify(ql,qr,k);
		pushup();
	}
	~node(){
		if(l==r) return;
		delete ch[0];
		delete ch[1];
	}
}*rt;
void modify(int x,int k){
	while(x){
		rt->modify(pos[top[x]],pos[x],k);
		x=fa2[top[x]];
	}
}
int ans;
void dfs(int u){
	rt->modify(pos[u],pos[u],-n);
	modify(fa2[u],1);
	ans=max(ans,rt->cnt);
	for(int v:ch1[u]) dfs(v);
	rt->modify(pos[u],pos[u],n);
	modify(fa2[u],-1);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++){
			vector<int>().swap(ch1[i]);
			vector<int>().swap(ch2[i]);
		}
		for(int i=2;i<=n;i++) ch1[fa1[i]=readint()].push_back(i);
		for(int i=2;i<=n;i++) ch2[fa2[i]=readint()].push_back(i);
		dfs1(1);
		top[1]=1;
		cnt=0;
		dfs2(1);
		rt=new node(0,n-1);
		ans=0;
		dfs(1);
		printf("%d\n",ans);
		delete rt;
	}
	return 0;
}