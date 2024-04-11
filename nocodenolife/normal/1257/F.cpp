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

const int maxn = 1e2 + 7;

const ll inf = 1e9 + 7;

int n;
int arr[maxn];

map<vector<int>,int> hash1;


i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<int> x,y;
    int u,v;
    for(int i=0;i<(1<<15);i++)
    {
        x.clear();
        //y = __builtin_popcount((arr[0]&((1<<15)-1))^i);
        for(int j=0;j<n;j++)
        {
            u = __builtin_popcount((arr[j]&((1<<15)-1))^i);
            //u -= y;
            x.pb(u);
        }
        hash1[x] = i;
    }

    for(int i=0;i<(1<<15);i++)
    {
        x.clear();
        for(int j=0;j<n;j++)
            x.pb(__builtin_popcount((arr[j]>>15)^i));
        for(int j=0;j<=30;j++)
        {
            y.clear();
            for(auto h:x)
                y.pb(j-h);
            if(hash1.count(y))
            {
                cout<<(hash1[y]|(i<<15))<<endl;
                return 0;
            }
        }
        /*if(hash1.find(y)!=hash1.end())
        {
            //cout<<i<<endl;
            //cout<<y.F<<" "<<y.S<<endl;
            //cout<<hash1[y]<<endl;
            cout<<(i>>15)+hash1[y]<<endl;
            return 0;
        }*/
    }
    cout<<-1<<endl;
    return 0;
}