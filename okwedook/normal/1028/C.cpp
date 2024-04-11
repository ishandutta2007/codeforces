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

vector<ll> xopen, xclose, yopen, yclose;

int main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    vector<pair<pll, pll>> arr(n);
    for (auto &i : arr) {
        cin >> i.f.f >> i.f.s >> i.s.f >> i.s.s;
        xopen.pb(i.f.f);
        yopen.pb(i.f.s);
        xclose.pb(i.s.f);
        yclose.pb(i.s.s);
    }
    sort(xopen);
    sort(xclose);
    sort(yopen);
    sort(yclose);
    for (auto i : arr) {
        int xo = n - 1, xc = 0, yo = n - 1, yc = 0;
        if (xopen[xo] == i.f.f) --xo;
        if (xclose[xc] == i.s.f) ++xc;
        if (yopen[yo] == i.f.s) --yo;
        if (yclose[yc] == i.s.s) ++yc;
        if (xopen[xo] <= xclose[xc] && yopen[yo] <= yclose[yc]) {
            cout << xopen[xo] << ' ' << yopen[yo];
            return 0;
        }
    }
    return 0;
}