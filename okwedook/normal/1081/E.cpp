#pragma GCC optimize("O3", "unroll-loops")
 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <complex>
#include <random>
#include <bitset>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <sstream>
#include <functional>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define eps 1e-9
#define mod 998244353
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline void checkmin(T &x, U y) { if (x > y) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (x < y) x = y; }

bool checksq(ll n) {
    ll a = sqrt(n);
    return a * a == n;
}

ll upsq(ll n) {
    ll a = sqrt(n);
    return a + (a * a <= n);
}

vector<ll> x;
vector<set<ll>> whatcan;
ll n;

ll getsum(ll a1, ll n) {
    return (a1 + n - 1) * n;
}

bool add(int i, ll curr = 0) {
    if (i == n) return true;
    if (whatcan[i + 1].upper_bound(curr) == whatcan[i + 1].end() || clock() >= 1950) return false;
    for (auto j : whatcan[i + 1]) 
        if (j > curr) {
            x[i] = j - curr;
            if (add(i + 2, curr + x[i] + x[i + 1])) return true;
        }
    return false;
}

signed main() {
    FAST; FIXED; RANDOM;
    cin >> n;
    x.resize(n);
    whatcan = vector<set<ll>> (n);
    for (int i = 1; i < n; i += 2) {
        cin >> x[i];
        int ptr;
        for (int j = 1; j * j <= x[i]; ++j) {
            ll l = 0, r = x[i] + 1;
            while (r - l > 1) {
                ll m = r + l >> 1;
                if (getsum(m, j) > x[i]) r = m;
                else l = m;
            }
            l -= (l + 1) % 2;
            if (getsum(l, j) == x[i]) whatcan[i].insert(getsum(1, l / 2));
        }
    }
    if (add(0)) {
        cout << "Yes\n";
        for (auto i : x) cout << i << ' ';
    } else cout << "No\n";
    return 0;
}