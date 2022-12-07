#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
 
#define F first
#define S second 
#define pb push_back
#define endl "\n"

#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }

#ifdef DEBUG
    #define dbg(s) {s;}
#endif

#ifndef DEBUG
    #define dbg(s)
#endif

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int grand(int x) { // from [0, x-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

#define int ll
#define i32 int32_t

#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 

#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int getInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}


ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
} 

const ll mod = 1e9 + 7;

ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 1e6 + 7;

const ll inf = 1e9 + 7;

ll n,k;
ll dp[maxn];
ll dp2[maxn];
bool visited[maxn];
vector<pair<ll,ll>> graph[maxn];
ll ret;
void dfs(ll ver)
{
    ll u,v,w,x;
	ll ans = 0;
	vector<pair<ll,ll>> st;
	ll b,c;
	for(ll i=0;i<graph[ver].size();i++)
	{
		u = graph[ver][i].F;
		if(visited[u])
			continue;
		visited[u] = true;
		dfs(u);
		b = dp[u];
		c = dp2[u];
		//cout<<ver<<" "<<u<<endl;
		st.pb({c+graph[ver][i].S,b});
	}
	
	vector<ll> re;
	for(ll i=0;i<st.size();i++)
	{
		ans+=st[i].S;
		re.pb(st[i].F - st[i].S);
	}
	
	sort(all(re));
	ll idx = re.size();
	idx--;
	ll f = k-1;
	while(f>0 && idx>=0)
	{
	    if(re[idx]<0)
	        break;
		ans+=re[idx];
		//cout<<idx<<endl;
		idx--;
		f--;
	}
	//cout<<ans<<" "<<ver<<endl;
	
	ll answer = ans;
	f++;
	if(idx>=0)
	{
	    if(re[idx]>0)
		    answer+=re[idx];
	}
	
	//cout<<ver<<" "<<answer<<" "<<ans<<endl;
	//dp[ver].F = answer;
	//dp[ver] = make_pair(answer,ans);
	ret  = max(answer,ret);
	ret = max(ans,ret);
	dp[ver] = answer;
	dp2[ver] = ans;
	//cout<<answer<<endl;
}

void solve()
{
    ll u,v,w,x;
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
    {
        graph[i].clear();
        visited[i] = false;
    }
    
    for(ll i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        graph[u].pb({v,w});
        graph[v].pb({u,w});
    }
    ret =0;
    visited[1] = true;
    dfs(1);
    //for(ll i=1;i<=n;i++)
    	//cout<<i<<" "<<dp[i].F<<" "<<dp[i].S<<endl;
    cout<<ret<<endl;
}


i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    int q;
    cin>>q;
    while(q>0)
    {
        solve();
        q--;
    }
    
}