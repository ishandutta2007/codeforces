//#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define BSET(a, p) ((a) | (1ll << (p)))
#define BCHK(a, p) ((a) & (1ll << (p)))
#define BXOR(a, p) ((a) ^ (1ll << (p)))
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
    x = x%mod;
    ex = ex % (mod-1);
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
int n,k;
map<int,int> bits;

void solve()
{
    cin>>n>>k;
    bits.clear();
    int idx = 0;
    int coun = 0;
    while(n>0)
    {
        if(n%2==1)
        {
            bits[idx] = 1;
            //cout<<idx<<endl;
            coun++;
        }
        n/=2;
        idx++;
    }

    if(coun>k)
    {
        cout<<"No"<<endl;
        return;
    }
    int lef = k - coun;
    //cout<<lef<<endl;
    for(int i=100;i>=-100;i--)
    {
        if(bits[i]==0)
            continue;
        //cout<<i<<" "<<bits[i]<<endl;
        if(lef==0)
            break;
        if(bits[i]>lef)
        {
//            bits[i] -= lef;
//            bits[i-1] += lef*2;
//            lef = 0;
            break;
        } else{
            bits[i-1] += bits[i]*2;
            lef-=bits[i];
            bits[i] = 0;
        }
    }

    int st = 100;
    for(int i=-100;i<100;i++)
    {
        if(bits[i]>0)
        {
            st = i;
            break;
        }
    }

    for(int i=st;i>=-100000;i--)
    {
        if(bits[i]==0)
            continue;
        //cout<<i<<" "<<bits[i]<<endl;
        if(lef==0)
            break;
        bits[i-1] += 2;
        bits[i]--;
        lef--;
    }


    cout<<"Yes"<<endl;
    int s =0;
    int z =0;
    for(int i=100;i>=-100000;i--)
    {
        if(bits[i]==0)
            continue;
        z+= bits[i]*(1ll<<i);
        s+=bits[i];
//        cout<<i<<" "<<bits[i]<<endl;
        for(int j=0;j<bits[i];j++)
        {
            cout<<i<<" ";
        }
    }
//    cout<<z<<endl;
//    cout<<s<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    PRELUDE;
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}