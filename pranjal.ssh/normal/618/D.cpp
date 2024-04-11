#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define tr(x,it) for(auto it = (x).begin();it!=(x).end();++it)
#define ntr(x,it) for(auto it = (x).rbegin();it!=(x).rend();++it)
#define ufy(v) sort(all(v));(v).erase(unique(all((v))),(v).end())
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define ia1(a,n) FOR(i,1,n)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}
inline int neg(int x,int m=INF){x=-x;return norm(x);}

#define N 200010

vi g[N];
int F[N],H[N];

void dfs(int u,int p=-1){
	
	tr(g[u],it)
	{
		if(*it==p)continue;
		dfs(*it,u),
		F[u]+=F[*it];
	}
	F[u]++;
	vii v;
	tr(g[u],it)
	{
		if(*it==p)continue;
		v.pb({-F[*it]+H[*it],*it});
	}
	sort(all(v));
	if(sz(v)==0)
	{
		F[u]=1;
		H[u]=1;
	}
	else if(sz(v)==1)
	{
		F[u]=min({F[u],H[v[0].S],F[v[0].S]+1});
		H[u]=H[v[0].S];
	}
	else
	{
		int x=0;
		x=H[v[0].S]+H[v[1].S];
		FOR(i,2,sz(v)-1)
		x+=F[v[i].S];
		F[u]=min(F[u],x-1);
		H[u]=H[v[0].S]+(x-H[v[0].S]-H[v[1].S])+F[v[1].S];
		F[u]=min(F[u],H[u]);
	}
	
}
int main()
{
    boost;
    int n,x,y;
    cin>>n>>x>>y;
    if(n==2)
    {
    	cout<<x;
    	return 0;
    }
    
    FOR(i,0,n-2){
    	int u,v;cin>>u>>v;g[u-1].pb(v-1),g[v-1].pb(u-1);
    }
    
    dfs(0);
    int yo=F[0];
 	
    ll ans=(yo-1)*1LL*y+x*1LL*(n-1-(yo-1));
    int bc=0;
    FOR(i,0,n-1)
    bc+=(sz(g[i])==1);
    if(bc!=n-1)
    ans=min(ans,(n-1)*1LL*y);
    else
    ans=min(ans,(n-2)*1LL*y+x);
    cout<<ans;
	return 0;
}