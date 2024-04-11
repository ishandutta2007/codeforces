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
    ll k, n, s, p;
    cin >> k >> n >> s >> p;
    ll one = (n + s - 1) / s;
    //x * p / one >= k;
    ll l = -1, r = 1e9;
    while (r - l > 1) {
        ll m = r + l >> 1;
        if (m * p / one >= k) r = m;
        else l = m;
    }
    cout << r;
    return 0;
}