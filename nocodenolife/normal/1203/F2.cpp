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
 
#define i32 int32_t
 
#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 
 
#define all(v) (v).begin(),(v).end()
 
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
 
ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
} 
 
const ll mod = 12345;
 
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

ll dp[60005][105];
ll answer;

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
 
    IOS; 
    ll n;
    ll rating;
    cin>>n>>rating;
    ll ans =0;
    vector<pair<int,int>> pos;
    vector<pair<int,int>> neg;
    ll a,b;
    for(ll i=0;i<n;i++)
    {
        cin>>a>>b;
        if(b>=0)
            pos.pb({a,b});
        else
        {
            a = max(a,abs(b));
            a+=b;
            neg.pb({a,b});
        }
    }
    
    sort(all(pos));
    sort(all(neg));
    reverse(all(neg));
    
    for(ll i=0;i<pos.size();i++)
    {
        if(rating<pos[i].F)
            break;
        ans++;
        rating+= pos[i].S;
    }
    answer = ans;
    //cout<<rating<<endl;
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<=rating;i++)
        dp[i][0]=ans;
    
    for(ll i=0;i<neg.size();i++)
    {
        for(ll j=0;j<=rating;j++)
        {
            if(dp[j][i]==-1)
                continue;
            dp[j][i+1] = max(dp[j][i+1],dp[j][i]);
            if(neg[i].first-neg[i].second > j)
                continue;
            a = j + neg[i].second;
            //cout<<a<<endl;
            dp[a][i+1] = max(dp[a][i+1],dp[j][i]+1);
            answer = max(answer,dp[a][i+1]);
        }
    }
    
    cout<<answer<<endl;
    
}