#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n,m;
char s[maxn];
vector<int> g[maxn];
int cnt=0,pos[maxn],sz[maxn];
void dfs(int u){
	pos[u]=cnt++;
	sz[u]=1;
	for(int v:g[u]){
		dfs(v);
		sz[u]+=sz[v];
	}
}
struct node{
	int l,r;
	node* ch[2];
	int mn=0,cnt,add=0;
	void pushup(){
		if(ch[0]->mn<ch[1]->mn){
			mn=ch[0]->mn;
			cnt=ch[0]->cnt;
		}
		else if(ch[0]->mn>ch[1]->mn){
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
		if(ql>r||qr<l) return;
		if(ql<=l&&qr>=r){
			pushtag(k);
			return;
		}
		pushdown();
		ch[0]->modify(ql,qr,k);
		ch[1]->modify(ql,qr,k);
		pushup();
	}
}*rt;
struct evt{
	int l,r,tp;
};
vector<evt> q[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	vector<pair<int,int>> vec;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++){
			int u=m*(i-1)+j,fa=0;
			if(s[j]=='U'&&i<n-1) fa=u+m*2;
			else if(s[j]=='D'&&i>2) fa=u-m*2;
			else if(s[j]=='L'&&j<m-1) fa=u+2;
			else if(s[j]=='R'&&j>2) fa=u-2;
			g[fa].push_back(u);
			if((i+j)%2==0){
				if(s[j]=='U') vec.push_back({u,u+m});
				else if(s[j]=='D') vec.push_back({u,u-m});
				else if(s[j]=='L') vec.push_back({u,u+1});
				else if(s[j]=='R') vec.push_back({u,u-1});
			}
		}
	}
	dfs(0);
	for(auto x:vec){
		int u=x.first,v=x.second;
		q[pos[u]].push_back({pos[v],pos[v]+sz[v]-1,1});
		q[pos[u]+sz[u]].push_back({pos[v],pos[v]+sz[v]-1,-1});
	}
	rt=new node(1,n*m);
	ll ans=1ll*n*n*m*m;
	for(int i=1;i<=n*m;i++){
		for(evt x:q[i]) rt->modify(x.l,x.r,x.tp);
		if(!rt->mn) ans-=rt->cnt;
	}
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}