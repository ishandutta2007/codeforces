//#define DEBUG
#include <algorithm>
#include <bitset>
#include <chrono>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
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
 
int arr[7] = {2, 325, 9375, 28178, 450775, 9780504, 179526502};
// primes upto 37

int power1(int x, int y, int p)
{
    int res = 1;      
    x = x % p; 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;

        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
bool miillerTest(int d, int n, int idx)
{
    int a = 2 + ((arr[idx]-2) % (n - 4));
    int x = power1(a, d, n);

    if (x == 1  || x == n-1)
       return true;
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    return false;
}

bool isPrime(int n)
{
    if (n==1) return true;
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (int i = 0; i < 7; i++)
         if (!miillerTest(d, n,i))
              return false;

    return true;
}

void solve()
{
    int x, d;
    cin>>x>>d;
    int power = 0;
    while (x%d == 0) {
        x/=d;
        power++;
    }

    if (power == 1) {
        cout<<"NO"<<endl;
        return;
    }

    if (isPrime(d) || power == 2) {
        if (isPrime(x)) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
        return;
    }

    if (power == 3) {
        if (isPrime(x)) {
            if (x*x == d) {
                cout<<"NO"<<endl;
                return;
            }
        } 
        cout<<"YES"<<endl;
        return;
    }

    cout<<"YES"<<endl;
}
 
i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
 
    PRELUDE;
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}