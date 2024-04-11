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

vector<pair<pll, ll>> start[101];
vector<ll> exam(101);

int main() {
    FAST; FIXED; RANDOM;
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        ll s, d, c;
        cin >> s >> d >> c;
        start[s].pb(mp(mp(d, c), i + 1));
        exam[d] = i + 1;
    }
    vector<ll> ans;
    vector<pair<pll, ll>> curr;
    for (int day = 1; day <= n; ++day) {
        for (auto i : start[day]) curr.pb(i);
        if (exam[day]) {
            for (auto i : curr) {
                if (i.s == exam[day]) {
                    cout << -1;
                    return 0;
                }
            }
            ans.pb(m + 1);
        } else {
            rsort(curr);
            if (sz(curr)) curr[sz(curr) - 1].f.s--, ans.pb(curr.back().s);
            else ans.pb(0);
            while (sz(curr) && curr.back().f.s == 0) curr.popb();
        }
    }
    for (auto i : ans) cout << i << ' ';
    return 0;
}