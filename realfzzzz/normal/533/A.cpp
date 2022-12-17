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
const int maxn=5e5+5;
int n,k,h[maxn],s[maxn];
vector<int> g[maxn];
int fa[maxn],mn[maxn],mn2[maxn];
vector<int> q[maxn];
const int inf=2e9;
void dfs(int u){
	if(u==1){
		mn[1]=1;
		mn2[1]=inf;
	}
	else if(h[u]<h[mn[fa[u]]]){
		mn2[u]=h[mn[fa[u]]];
		mn[u]=u;
	}
	else{
		mn[u]=mn[fa[u]];
		mn2[u]=min(mn2[fa[u]],h[u]);
	}
	q[mn[u]].push_back(u);
	for(int v:g[u]){
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs(v);
	}
}
struct node{
	int l,r;
	node* ch[2];
	int mn,add=0;
	void pushup(){
		mn=min(ch[0]->mn,ch[1]->mn);
	}
	node(int l,int r):l(l),r(r),mn(l){
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
	int query(int x){
		if(l==r) return mn;
		pushdown();
		if(x<=ch[0]->r) return ch[0]->query(x);
		else return ch[1]->query(x);
	}
}*rt;
void modify(int x,bool t){
	int p=upper_bound(s+1,s+k+1,x)-s-1;
	if(p) rt->modify(1,p,t?1:-1);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) h[i]=readint();
	for(int i=1;i<n;i++){
		int a,b;
		a=readint();
		b=readint();
		g[a].push_back(b);
		g[b].push_back(a);
	}
	k=readint();
	for(int i=1;i<=k;i++) s[i]=readint();
	sort(s+1,s+k+1);
	dfs(1);
	rt=new node(1,k);
	for(int i=1;i<=n;i++) modify(h[mn[i]],1);
	int res=-1;
	for(int i=k;i>0;i--) if(rt->query(i)<k+1){
		res=s[i];
		break;
	}
	if(res<0){
		printf("0\n");
		return 0;
	}
	int ans=inf;
	for(int i=1;i<=n;i++) if(h[i]<res){
		for(int j:q[i]){
			modify(h[i],0);
			modify(min(mn2[j],res),1);
		}
		if(rt->mn>=k+1) ans=min(ans,res-h[i]);
		for(int j:q[i]){
			modify(min(mn2[j],res),0);
			modify(h[i],1);
		}
	}
	printf("%d\n",ans<inf?ans:-1);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}