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

vector<vector<int>> pref;

vector<int> get(int r) {
    if (r < 0) return vector<int>(4, 0);
    return pref[r];
}

vector<int> get(int l, int r) {
    vector<int> ans = get(r), ans1 = get(l - 1);
    for (int i = 0; i < 4; ++i) ans[i] -= ans1[i];
    return ans;
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll x, y;
    cin >> x >> y;
    if ((abs(x) + abs(y)) % 2 != n % 2 || abs(x) + abs(y) > n) {
        cout << -1;
        return 0;
    }
    ll ansx = 0, ansy = 0;
    for (auto &i : s)
        if (i == 'U') ++ansy, i = 0;
    for (auto &i : s)
        if (i == 'D') --ansy, i = 1;
    for (auto &i : s)
        if (i == 'L') --ansx, i = 2;
    for (auto &i : s)
        if (i == 'R') ++ansx, i = 3;
    if (ansx == x && ansy == y) {
        cout << 0;
        return 0;
    }
    pref = vector<vector<int>> (n, vector<int>(4));
    vector<int> curr(4, 0);
    for (int i = 0; i < n; ++i)
        curr[s[i]]++, pref[i] = curr;
    int ans = 2 * n;
    for (int i = 0; i < n; ++i) {
        int l = -1, r = i + 1;
        while (r - l > 1) {
            int m = r + l >> 1;
            vector<int> check = get(m, i);
            int newx = ansx + check[2] - check[3];
            int newy = ansy + check[1] - check[0];
            if (abs(x - newx) + abs(y - newy) <= i - m + 1) l = m;
            else r = m;
        }
        if (l != -1) checkmin(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}