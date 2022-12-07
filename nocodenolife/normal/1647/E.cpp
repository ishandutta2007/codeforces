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
#include <cstring>
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
 
const int maxn = 1e5 + 7;
 
const ll inf = 1e9 + 7;
 
int n;
int next_pos[maxn][50];
int final_seating[maxn];
int num_rounds;
int incoming_count[maxn];
int final_pos[maxn];
int ans[maxn];

void binaryLiftingSetup(){
    for (int step = 1; step < 45; step++)
    {
        for (int i = 1; i <= n; i++)
        {
            next_pos[i][step] = next_pos[next_pos[i][step-1]][step-1];
        }    
    }
}

int setBitNumber(int n)
{
    int ans = 0;
    while (n > 1) {
        ans++;
        n/=2;
    }
    return ans;
}

int findFinalPosition(int rounds, int cur_pos ) {
    if (rounds == 0) {
        return cur_pos;
    }
    int step = setBitNumber(rounds);
    return findFinalPosition(rounds - (1<<step), next_pos[cur_pos][step]);
}


void solve()
{
    cin>>n;
    memset(incoming_count, 0, sizeof(incoming_count));
    for (int i = 1; i <= n; i++)
    {
        cin>>next_pos[i][0];
        incoming_count[next_pos[i][0]]++;
    }

    int max_pos = 0;
    for (int i = 1; i <=n; i++)
    {
        cin>>final_seating[i];
        max_pos = max(max_pos, final_seating[i]);
    }
    int num_reduced = 0;
    for (int i =1; i <= n; i++)
    {
        if (incoming_count[i] == 0) {
            num_reduced++;
        }
    }
    
    num_rounds = (max_pos - n)/num_reduced;

    binaryLiftingSetup();
    set<int> numsLeft;

    for (int i = 1; i <= n; i++)
    {
        numsLeft.insert(i);
        final_pos[i] = findFinalPosition(num_rounds,i);
    }    

    memset(ans,0,sizeof(ans));
    int num;
    for (int i = 1; i <= n; i++)
    {
        num = final_seating[final_pos[i]];
        if (numsLeft.find(num) != numsLeft.end()){
            ans[i] = num;
            numsLeft.erase(num);
        }
    }
    int v;
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] != 0) {
            cout<<ans[i]<<" ";
            continue;
        }
        num = final_seating[final_pos[i]];
        v = *numsLeft.lower_bound(num);
        cout<<v<<" ";
        numsLeft.erase(v);
    }

    cout<<endl;
    
}
 
i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
 
    PRELUDE;
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}