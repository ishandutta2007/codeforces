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

bool graph[7005][7005];
ll degree[7005];
ll skill[7005];
bitset<60> questions[7005];
ll n;
ll ans;

bool find(ll i, ll j)
{
    if(i==j)
        return false;
    questions[j].flip();
    
        //cout<<questions[i]<<" "<<questions[j]<<endl;
    if((questions[i]&questions[j]).any())
    {
        questions[j].flip();
        //cout<<i<<" "<<j<<endl;
        return true;
    }
    questions[j].flip();
    return false;
}

void createGraph()
{
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(find(i,j))
            {
                graph[i][j] = true;
                degree[i]++;
            }
        }
    }
}

bool reduce()
{
    if(ans<=1)
        return false;
    ll val = -1;
    for(ll i=0;i<n;i++)
    {
        if(degree[i]==ans-1)
        {
            val = i;
            break;
        }
    }
    if(val==-1)
        return false;
    degree[val] = -1;
    ans--;
    for(ll i=0;i<n;i++)
    {
        if(graph[i][val])
        {
            degree[i]--;
        }
    }
    return true;
}
 
i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
 
    IOS;
    memset(degree,0,sizeof(degree));
    memset(graph,false,sizeof(graph));
    cin>>n;
    ans = n;
    ll x;
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        questions[i] = x;
    }
    for(ll i=0;i<n;i++)
        cin>>skill[i];
    createGraph();
    
    while(reduce());
    
    if(ans<=1)
    {
        cout<<"0"<<endl;
    }
    else
    {
        ans = 0;
        for(ll i=0;i<n;i++)
        {
            if(degree[i]>-1)
            {
                //cout<<i<<endl;
                ans+= skill[i];
            }
        }
        cout<<ans<<endl;
    }
    
}