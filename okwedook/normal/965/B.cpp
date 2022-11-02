#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf pop_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-8
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf (1 << 31) - 1
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2>inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

int main() {
    FAST;
    ll n, k;
    cin >> n >> k;
    vector<string> arr(n);
    vector<vector<ll>> cnt(n, vector<ll>(n));
    for (auto &i : arr) cin >> i;
    //cout << 1 << endl;
    for (int i = 0; i <= n - k; ++i)
        for (int j = 0; j < n; ++j) {
            bool flag = true;
            for (int p = i; p < i + k; ++p)
                flag = flag && (arr[p][j] == '.');
            if (flag)
                for (int p = i; p < i + k; ++p)
                    ++cnt[p][j];
        }
    if (k > 1) {
        for (int j = 0; j <= n - k; ++j)
            for (int i = 0; i < n; ++i) {
                bool flag = true;
                for (int p = j; p < j + k; ++p)
                    flag = flag && (arr[i][p] == '.');
                if (flag)
                    for (int p = j; p < j + k; ++p)
                        ++cnt[i][p];
            }
    }
    ll x = 0, y = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (cnt[i][j] > cnt[x][y]) {
                x = i;
                y = j;
            }
        }
    cout << x + 1 << ' ' << y + 1;
    return 0;
}