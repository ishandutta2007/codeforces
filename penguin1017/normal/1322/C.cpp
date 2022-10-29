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
const int N=2e6+9;
const ll mod=998244353;
pair<ll,ll> a[N];
ll has[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		rep(i,1,n+1)scanf("%lld",&a[i].se),has[i]=((ll)rand()<<40)+((ll)rand()<<20)+rand(),a[i].fi=0;
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			a[v].fi^=has[u];
		}
		sort(a+1,a+1+n);
		ll ans=0,s=a[1].se; 
		rep(i,2,n+2){
			if(i==n+1||a[i].fi!=a[i-1].fi){
				if(a[i-1].fi)ans=__gcd(ans,s);
				s=0; 
			}
			s+=a[i].se;
		}
		printf("%lld\n",ans);
	}
}