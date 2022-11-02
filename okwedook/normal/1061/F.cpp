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
#define mod 1000000007
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

bool ask(ll a, ll b, ll c) {
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    string ans;
    cin >> ans;
    return ans == "Yes";
}

mt19937 gen;

int rand(int n) {
    uniform_int_distribution<int> uni(1, n);
    return uni(gen);
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n, k;
    cin >> n >> k;
    ll curr = 1, d = 1, t = 1;
    while (curr < n) curr += t *= k, ++d;
    gen.seed(946850948598402958608549860381);
    vector<int> was;
    vector<int> cnt(n + 1);
    for (int i = 0; i < 60; ++i) {
        int a = rand(n), c = rand(n);
        was.resize(0);
        for (int b = 1; b <= n; ++b) {
            if (ask(a, b, c))
                was.pb(b);
        }
        if (sz(was) != 2 * d - 1) continue;
        for (int i = 0; i < sz(was); ++i)
            for (int j = 0; j < sz(was); ++j)
                if (j != i)
                    cnt[was[i]] += ask(a, was[i], was[j]);
        break;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (cnt[i] == d - 1)
            ans = i;
    cout << "! " << ans << endl;
    return 0;
}