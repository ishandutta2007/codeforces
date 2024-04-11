#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
using namespace std;
const int N=2e5+9;
const ll mod=998244353;
vector<pii> g[4];
struct node{
	int c,pos,id;
}_[N];
ll pre[N],pre2[N],pre3[N],sum2[N];
int sum[N],vis[N]; 
bool cmp(node a,node b){
	return a.c<b.c;
}
bool cmp2(node a,node b){
	return a.id<b.id;
}
void Set(int p,int val){
	for(int i=p;i<N;i+=lb(i))sum[i]+=val;
}
int Get(int p){
	int res=0;
	for(int i=p;i;i^=lb(i))res+=sum[i];
	return res;
}
void Set2(int p,ll val){
	for(int i=p;i<N;i+=lb(i))sum2[i]+=val;
}
ll Get2(int p){
	ll res=0;
	for(int i=p;i;i^=lb(i))res+=sum2[i];
	return res;
}
ll find(int x){
	if(!x)return 0;
	int l=1,r=N;
	while(l<r){
		int m=l+r>>1;
		if(Get(m)<x)l=m+1;
		else r=m;
	} 
	if(l==N)return (ll)1e18;
	return Get2(l);
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n+1)scanf("%d",&_[i].c),_[i].id=i;
	sort(_+1,_+1+n,cmp);
	rep(i,1,n+1)_[i].pos=i;
	sort(_+1,_+1+n,cmp2);
	int a,b;
	scanf("%d",&a);
	rep(i,0,a){
		int x;
		scanf("%d",&x);
		vis[x]+=1;
	}
	scanf("%d",&b);
	rep(i,0,b){
		int x;
		scanf("%d",&x);
		vis[x]+=2;
	}
	rep(i,1,n+1)g[vis[i]].pb({_[i].c,_[i].pos});
	rep(i,0,4)sort(all(g[i]));
	if(m<k||a<k||b<k){
		cout<<-1;
		return 0;
	}
	int comom=max(0,2*k-m);
	if(g[3].size()<comom){
		cout<<-1;
		return 0;
	}
	rep(i,0,g[0].size()){
		Set(g[0][i].se,1);
		Set2(g[0][i].se,g[0][i].fi);
	}
	rep(i,k,g[3].size()){
		Set(g[3][i].se,1);
		Set2(g[3][i].se,g[3][i].fi); 
	}
	int last=k-comom;
	rep(i,last,g[1].size()){
		Set(g[1][i].se,1);
		Set2(g[1][i].se,g[1][i].fi);
	}
	rep(i,last,g[2].size()){
		Set(g[2][i].se,1);
		Set2(g[2][i].se,g[2][i].fi);
	}
	rep(i,0,g[1].size())pre[i+1]=pre[i]+g[1][i].fi;
	rep(i,0,g[2].size())pre2[i+1]=pre2[i]+g[2][i].fi;
	rep(i,0,g[3].size())pre3[i+1]=pre3[i]+g[3][i].fi;
	ll ans=1e18;
	rep(i,comom,min(k,(int)g[3].size())+1){
		int last=k-i;
		if(last>g[1].size()||last>g[2].size()){
			if(last<=g[1].size()){
				Set(g[1][last-1].se,1);
				Set2(g[1][last-1].se,g[1][last-1].fi);
			}
			if(last<=g[2].size()){
				Set(g[2][last-1].se,1);
				Set2(g[2][last-1].se,g[2][last-1].fi);
			}
			continue;
		}
		ll res=pre3[i]+pre[last]+pre2[last];
		res+=find(m-2*last-i);
		ans=min(res,ans);
		if(last){
			Set(g[1][last-1].se,1);
			Set2(g[1][last-1].se,g[1][last-1].fi);
			Set(g[2][last-1].se,1);
			Set2(g[2][last-1].se,g[2][last-1].fi);
		}
	}
	printf("%lld",ans);
}