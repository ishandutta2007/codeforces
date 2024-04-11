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
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<x<<' ';cout<<#x<<endl;}
using namespace std;
const int N=4e5+9;
const ll mod=998244353;
const ll Inf=1e18;
ll s[N],p[N];
vector<pair<ll,ll>> g;
pair<ll,ll> stk[N];
int t,T;
ll down(ll a,ll b){
	return a/b;
}
ll up(ll a,ll b){
	return (a+b-1)/b;
}
void solve(){
	ll n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	rep(i,1,m+1)scanf("%lld",&p[i]);
	p[++m]=n;
	rep(i,1,m+1)s[i]=p[i]-p[i-1];
	ll MIN=Inf,MAX=0,l=1,r=Inf,K=k+m;
	while(l<r){
		ll sum=0,mid=l+r>>1;
		rep(i,1,m+1)sum+=down(s[i],mid);
		if(sum>=K)l=mid+1;
		else r=mid;
	}
	MIN=l-1;
	l=1,r=Inf;
	while(l<r){
		ll sum=0,mid=l+r>>1;
		rep(i,1,m+1)sum+=up(s[i],mid);
		if(sum<=K)r=mid;
		else l=mid+1;
	}
	MAX=l;
	ll ans=MAX-MIN;
	//cout<<MIN<<' '<<MAX<<"?\n";
	g.clear();
	rep(i,1,m+1){
		ll L=up(s[i],MAX),R=down(s[i],MIN);
		if(L<=R)continue;
	//	cout<<s[i]<<' '<<L<<' '<<R<<"???\n";
		g.pb({MIN-down(s[i],L),(R?up(s[i],R):Inf)-MAX});
	}
//	cout<<"MAX\n";
	if(g.size()==0){
		printf("%lld\n",ans);
		return;
	}
	sort(all(g));
	int c=0;
	rep(i,0,g.size()){
		while(c&&stk[c].se<g[i].se)--c;
		stk[++c]=g[i];
	//	cout<<stk[c].fi<<' '<<stk[c].se<<"check\n"; 
	}
	ll add=min(stk[1].se,stk[c].fi);
	rep(i,1,c){
		add=min(add,stk[i].fi+stk[i+1].se);
	}
	ans+=add;
	printf("%lld\n",ans);
}
int main(){
//	freopen("text.in","r",stdin);
	scanf("%d",&t);
	rep(i,0,t)solve();
}
/*
1
999999919598926 10 97493823659451
964836345611046 979206333313129 980926506738996 984611885561437 987164792245589 992008347528156 996667984099828 997709103875296 998325293108002 999793892409416 
*/