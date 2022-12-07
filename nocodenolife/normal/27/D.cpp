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
 
vector<ll> graph[100005];
ll visited[100005];
bool value;
 
bool checkIntersect(ll st1,ll en1,ll st2, ll en2 )
{
    if(st1==st2 || st1==en2 || en1==st2 || en2==en1)
        return false;
    if(st1<st2)
    {
        if(en1<st2)
            return false;
        if(en2<=en1)
            return false;
        else
            return true;
    }
    else
        return checkIntersect(st2,en2,st1,en1);
}
 
void dfs(ll val)
{
    ll u;
    for(ll i=0;i<graph[val].size();i++)
    {
        u = graph[val][i];
        if(visited[u]==0)
        {
            visited[u] = 3 - visited[val];
            dfs(u);
        }
        if(visited[u]==visited[val])
            value = true;
    }
    return;
}
 
void checkOdd()
{
    for(ll i=0;i<100005;i++)
    {
        if(visited[i]!=0)
            continue;
        
        visited[i] = 1;
        dfs(i);
    }
}
 
i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
 
    IOS;
    memset(visited,0,sizeof(visited));
    
    ll n,m;
    cin>>n>>m;
    
    ll start[m+2];
    ll end[m+2];
    
    ll a,b,c;
    for(ll i=1;i<=m;i++)
    {
        cin>>a>>b;
        start[i] = min(a,b);
        end[i] =  max(a,b);
    }
    
    for(ll i=1;i<=m;i++)
    {
        for(ll j=i+1;j<=m;j++)
        {
            if(checkIntersect(start[i],end[i],start[j],end[j]))
            {
                //cout<<i<<" "<<j<<endl;
                //cout<<start[i]<<" "<<end[i]<<" "<<start[j]<<" "<<end[j]<<endl;
                graph[i].pb(j);
                graph[j].pb(i);
            }
        }
    }
    
    
    value = false;
    checkOdd();
    
    if(value)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    
    for(ll i=1;i<=m;i++)
    {
        if(visited[i]==1)
            cout<<"i";
        else
            cout<<"o";
    }
    cout<<endl;
}