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
#define ld double
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define eps 1e-5
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define checkmin(x, y) if (x > y) x = y
#define checkmax(x, y) if (x < y) x = y
#define sort(a) sort(all(a))
#define rsort(a) sort(rall(a))
#define reverse(a) reverse(all(a))
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])

vector<pair<ld, ld>> arr;
ld p;

bool check(ld x) {
    ld sx = x;
    x *= p;
    for (auto i : arr) {
        ld k = (i.f * sx - i.s);
        checkmax(k, 0);
        x -= k;
        if (x < 0) return false;
    }
    return true;
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    arr.resize(n);
    cin >> p;
    for (auto &i : arr) cin >> i.f >> i.s;
    check(2);
    ld l = 0, r = 1e12;
    ll cnt = 80;
    while (r - l > eps && cnt--) {
        ld m = (r + l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    if (l > 1e11) cout << -1;
    else cout << l;
    return 0; 
}