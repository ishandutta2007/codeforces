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

const int maxn = 2e5 + 7;

const ll inf = 1e17 + 7;
int n;
pair<pii,pii> arr[maxn];
bool visited[maxn];

/*int dist(int i, int j)
{
    pair<pii,int> x = arr[i];
    pair<pii,int> y = arr[j];
    int dis = 0;
    int c = x.F.F-y.F.F;
    c = c*c;
    dis+=c;
    c = x.F.S-y.F.S;
    c = c*c;
    dis+=c;
    c = x.S-y.S;
    c = c*c;
    dis+=c;
    return dis;
}  

void solve(int v)
{
    int mini = inf;
    int idx = -1;
    int c;
    for(int i=0;i<n;i++)
    {
        if(i==v || visited[i]==true)
            continue;
        c = dist(i,v);
        if(c<mini)
        {
            mini = c;
            idx = i;
        }
    }
    cout<<v+1<<" "<<idx+1<<endl;
    visited[v] = true;
    visited[idx] = true;
}*/

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    cin>>n;
    int x,y,z;
    for(int i=1;i<=n;i++)
    {   
        cin>>x>>y>>z;
        arr[i] = {{x,y},{z,i}};
    }
    sort(arr+1,arr+n+1);
    memset(visited,false,sizeof(visited));
    
    int prev = 1;
    for(int i=2;i<=n;i++)
    {
        if(visited[i]==true)
            continue;
        if(arr[i].F.F == arr[prev].F.F && arr[i].F.S == arr[prev].F.S)
        {
            cout<<arr[i].S.S<<" "<<arr[prev].S.S<<endl;
            visited[i] = true;
            visited[prev] = true;
            i++;
        }
        prev = i;
    }
    
    prev = n;
    for(int i=1;i<=n;i++)
    {
    	if(visited[i]==false)
    	{
    		prev = i;
    		break;
    	}
    }
    for(int i=prev+1;i<=n;i++)
    {
        if(visited[i]==true)
            continue;
        if(arr[i].F.F == arr[prev].F.F)
        {
            cout<<arr[i].S.S<<" "<<arr[prev].S.S<<endl;
            visited[i] = true;
            visited[prev] = true;
            i++;
            while(i<=n && visited[i]==true)
            	i++;
        }
        prev = i;
    }

    vector<int> res;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==true)
            continue;
        res.pb(arr[i].S.S);
    }

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
        i++;
        cout<<res[i]<<endl;
    }

    return 0;
    
    
}