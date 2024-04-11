//#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define BSET(a, p) ((a) | (1ll << (p)))
#define BCHK(a, p) ((a) & (1ll << (p)))
#define BXOR(a, p) ((a) ^ (1ll << (p)));
#define BREM(a, p) (BCHK(a, p)?(BXOR(a, p)):(a))
#define BSHO(a, N) (bitset<N>(a))

#define fi first
#define sc second 
#define pb push_back


#ifdef DEBUG
    #define dbg(s) {s;}
    #define PRELUDE
#endif

#ifndef DEBUG 
    #define PRELUDE { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
    #define dbg(s)
    #define endl "\n"
#endif

#define int ll
#define i32 int32_t

#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 
// Ordered set docs:
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

// To remove randomization use 0 below:
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int ri(int x) { // from [0, n-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

inline ld rf() { // from [0, 1]
    return uniform_real_distribution<ld>(0, 1)(rng);
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

char mat[70][70];
int r,c;
int tot,coun;
int rows[70];
int cols[70];

bool checkAns1()
{
    if(rows[1]==c)
        return true;
    if(rows[r]==c)
        return true;
    if(cols[1]==r)
        return true;
    if(cols[c]==r)
        return true;
    return false;
}

bool checkAns2()
{
    for(int i=1;i<=r;i++)
    {
        if(rows[i]==c)
            return true;
    }
    for(int i=1;i<=c;i++)
    {
        if(cols[i]==r)
            return true;
    }

    if(mat[1][1]=='A')
        return true;
    if(mat[1][c]=='A')
        return true;
    if(mat[r][1]=='A')
        return true;
    if(mat[r][c]=='A')
        return true;
    return false;
}

bool checkAns4()
{
    if(rows[1]==0 && rows[r]==0 && cols[1]==0 && cols[c]==0)
        return true;
    return false;
}
void solve()
{
    cin>>r>>c;
    tot = 0;
    coun = 0;
    
    memset(rows,0,sizeof(rows));
    memset(cols,0,sizeof(cols));
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cin>>mat[i][j];
            tot++;
            if(mat[i][j]=='A')
            {
                coun++;
                rows[i]++;
                cols[j]++;
            }
        }
    }

    if(coun==0)
    {
        cout<<"MORTAL"<<endl;
        return;
    }
    if(coun==tot)
    {
        cout<<"0"<<endl;
        return;
    }

    if(checkAns1())
    {
        cout<<"1"<<endl;
        return;
    }

    if(checkAns2())
    {
        cout<<"2"<<endl;
        return;
    }
    
    if(checkAns4())
    {
        cout<<"4"<<endl;
        return;
    }

    cout<<"3"<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    PRELUDE;
    int t;
    cin>>t;

    while(t--)
        solve();

}