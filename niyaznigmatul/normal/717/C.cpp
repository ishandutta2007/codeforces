#include <bits/stdc++.h>

#if (_WIN32 || __WIN32__)
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

using std::istream; using std::ostream; using std::fixed; using std::greater;
using std::tuple; using std::tie; using std::make_pair; using std::multiset;
using std::nth_element; using std::min_element; using std::max_element;
using std::vector; using std::set; using std::map; using std::string;
using std::fill; using std::copy; using std::sort; using std::unique;
using std::unordered_set; using std::unordered_map; using std::pair;
using std::next_permutation; using std::reverse; using std::rotate;
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::lower_bound; using std::upper_bound; using std::deque;
using std::min; using std::max; using std::swap; using std::abs;
using std::priority_queue; using std::queue; using std::bitset;
using std::make_tuple; using std::iota;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;

ll rnd(ll x, ll y) { static auto gen = std::bind(std::uniform_int_distribution<ll>(), std::mt19937(960172)); return gen() % (y - x + 1) + x; }
ll gcd(ll a, ll b) { while (b > 0) { ll t = a % b; a = b; b = t; } return a; }
template<typename T> T sqr(T const& a) { return a * a; }

int const INF = 100 + (int) 1e9;
ll const INFL = 100 + (ll) 1e18;
ld const PI = 3.1415926535897932384626433832795028;


int const mod = 10007;


void solve() {
    
    int n;
    scanf("%d", &n);
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    
    sort(a.begin(), a.end());
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans + (ll) a[i] * a[n - 1 - i]) % mod;
    }
    
    printf("%d\n", ans);
}



int main() {

    cout.precision(15);
    cout << fixed;
    cerr.precision(6);
    cerr << fixed;
    
    solve();

#ifdef LOCAL
    cerr << "time: " << (ll) clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
#endif
}