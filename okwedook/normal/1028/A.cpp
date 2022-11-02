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

int summ[200][200];

ll get(int y1, int x1, int y2, int x2) {
    return summ[y2][x2] - summ[x2][y1 - 1] - summ[y2][x1 - 1] + summ[y1 - 1][x1 - 1];
}

int main() {
    FAST; FIXED; RANDOM;
    ll n, m;
    cin >> n >> m;
    pll mx = mp(inf, -1), my = mp(inf, -1);
    for (int i = 1; i <= n; ++i) {
        ll curr = 0;
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            if (c == 'B') {
                checkmin(mx.f, j);
                checkmax(mx.s, j);
                checkmin(my.f, i);
                checkmax(my.s, i);
            }
        }
    }
    ll k = mx.s - mx.f;
    cout << my.f + k / 2 << ' ' << mx.f + k / 2;
    return 0;
}