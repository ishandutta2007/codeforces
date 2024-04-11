#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
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

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<typename T1> inline void shuffle(T1 &arr) { 
    for (int i = -int(arr.size()); i < arr.size(); ++i) {
        int f = ((rand() << 16) + rand()) % arr.size(), s = ((rand() << 16) + rand()) % arr.size();
        swap(arr[f], arr[s]);
    }
}
template<typename T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

signed main() {
    FAST;
    ll n;
    cin >> n;
    vector<set<pll>> can(n);
    for (int i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        vector<ll> arr(k);
        ll summ = 0;
        for (auto &i : arr) cin >> i, summ += i;
        for (int j = 0; j < k; ++j) can[i].insert(mp(summ - arr[j], j));
    }
    map<ll, pll> now;
    for (int i = 0; i < n; ++i) {
        for (auto j : can[i])
            if (now.count(j.f)) {
                cout << "YES\n";
                cout << now[j.f].f + 1 << ' ' << now[j.f].s + 1 << '\n';
                cout << i + 1 << ' ' << j.s + 1 << '\n';
                return 0;
            } 
        for (auto j : can[i]) now[j.f] = mp(i, j.s);
    }
    cout << "NO";
    return 0;
}