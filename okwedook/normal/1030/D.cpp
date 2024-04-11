#pragma GCC optimize("Ofast", "unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(NULL))
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
#define checkmin(x, y) if (x > y) x = y
#define checkmax(x, y) if (x < y) x = y
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); } 

ll simple(ll &a, ll &b) {
    ll g = __gcd(a, b);
    a /= g;
    b /= g;
    return g;
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n, m, k;
    cin >> n >> m >> k;
    ll g1 = simple(n, k);
    ll g2 = simple(m, k);
    if (k == 2) {
        cout << "YES\n";
        cout << 0 << ' ' << 0 << '\n';
        cout << n << ' ' << 0 << '\n';
        cout << 0 << ' ' << m;
    } else if (k == 1) {
        if (g1 == 1 && g2 == 1) cout << "NO";
        else {
            if (g1 > 1) n *= 2;
            else m *= 2;
            cout << "YES\n";
            cout << 0 << ' ' << 0 << '\n';
            cout << n << ' ' << 0 << '\n';
            cout << 0 << ' ' << m;
        }
    } else cout << "NO";
    return 0;
}