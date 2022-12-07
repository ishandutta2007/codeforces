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

const int maxn = 1e6 + 7;

const ll inf = 1e9 + 7;
int n,k,odd,even;

void solve()
{
    cin>>n>>k;
    odd = 0;
    even = 0;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x%2==0)
            even++;
        else
            odd++;
    }

    //Stannis = 0, stannis starts and stannis wants odd
    int numMoves = n-k;
    if(numMoves==0)
    {
        if(odd%2==0)
        {
            cout<<"Daenerys"<<endl;
        } else{
            cout<<"Stannis"<<endl;
        }
        return;
    }

    int sta;
    if(numMoves%2==0) {
        //Last player to move is Daenerys
        if (k % 2 == 0) {
            //Stannis cant win, as Daenaryes can force even -> last move, if even then take even, if odd take odd
            cout << "Daenerys" << endl;
            return;
        }
        else
        {
            //Stannis must burn all the even cities
            sta = numMoves/2;
            if(sta<even)
            {
                cout << "Daenerys" << endl;
            } else{
                cout<<"Stannis"<<endl;
            }
            return;
        }
    }
    else{
        //Stannis takes last move
        if(k%2==1)
        {
            //odd left cities, even if all even burned, not okay, daenarys must birn all odd
            sta = (numMoves-1)/2;
            if(sta<odd)
            {
                cout<<"Stannis"<<endl;
            } else{
                cout << "Daenerys" << endl;
            }
            return;
        } else{
            //even cities left, if all even or all odd then Daenrys wins
            sta = (numMoves-1)/2;
            if(sta<odd && sta<even)
            {
                cout<<"Stannis"<<endl;
            } else{
                cout << "Daenerys" << endl;
            }
        }
    }
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