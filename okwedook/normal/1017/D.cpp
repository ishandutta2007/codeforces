#pragma GCC optimize("O3","unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(NULL))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

template<class T1, class T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<class T1, class T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<class T1> inline void sort(T1 &arr) { sort(all(arr)); }
template<class T1> inline void rsort(T1 &arr) { sort(rall(arr)); }
template<class T1> inline void reverse(T1 &arr) { reverse(all(arr)); }
template<class T1> inline void shuffle(T1 &arr) { 
    for (int i = -int(arr.size()); i < int(arr.size()); ++i)
        swap(arr[rand() % arr.size()], arr[rand() % arr.size()]);
}
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

int to_i(string s) {
    ll ans = 0;
    for (int i = 0; i < s.size(); ++i) 
        ans = (ans << 1) + (s[i] - '0');
    return ans;
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n, m, q;
    cin >> n >> m >> q;
    int N = 1 << n;
    int cnt[N][N];
    int mask[N];
    int mapcnt[N];
    pii cost[N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cnt[i][j] = 0;
    for (int i = 0; i < N; ++i) mapcnt[i] = mask[i] = 0;
    for (int i = 0; i < N; ++i) cost[i] = mp(0, 0);
    vector<int> w(n);
    for (auto &i : w) cin >> i;
    for (int i = 0; i < (1 << n); ++i) {
        cost[i].s = i;
        for (int j = 0; j < n; ++j)
            if (((i >> (n - j - 1)) & 1)) cost[i].f += w[j];
    }
    sort(cost, cost + N);
    for (int i = 0; i < N; ++i)
        mask[cost[i].s] = i;
    /*for (auto i : mask) cout << i << ' ';
    cout << '\n';*/

    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        mapcnt[to_i(s)]++;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cnt[i][mask[j]] = mapcnt[i ^ j ^ (N - 1)];
        }
        for (int j = 1; j < N; ++j)
            cnt[i][j] += cnt[i][j - 1];
    }
    /*for (int i = 0; i < N; ++i, cout << '\n') {
        for (int j = 0; j < N; ++j)
            cout << cnt[i][j] << ' ';
    }*/
    for (int i = 0; i < q; ++i) {
        string s;
        int k;
        cin >> s >> k;
        int ind = to_i(s);
        int l = -1, r = N;
        while (r - l > 1) {
            ll mid = r + l >> 1;
            if (cost[mid].f <= k) l = mid;
            else r = mid;
        }
        if (l < 0) cout << 0;
        else cout << cnt[ind][l];
        cout << '\n';
    }
    return 0;
}