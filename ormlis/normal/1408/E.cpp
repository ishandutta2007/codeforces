#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 15;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int dsu[maxN];

void init_dsu() {
    range(i, maxN) {
        dsu[i] = i;
    }
}

int get_dsu (int a) {
    return (dsu[a] == a) ? a : dsu[a] = get_dsu(dsu[a]);
}

bool Unio(int a, int b) {
    a = get_dsu(a);
    b = get_dsu(b);
    if (rand() % 2) {
        swap(a, b);
    }
    dsu[a] = b;
    return a != b;
}


void solve() {
    init_dsu();
    int m, n; cin >> m >> n;
    vector<int> a(m), b(n);
    range(i, m) cin >> a[i];
    range(i, n) cin >> b[i];
    vector<ar<int, 3>> edges;
    ll ans = 0;
    range(i, m) {
        int s; cin >> s;
        range(_, s) {
            int j; cin >> j;
            edges.push_back({a[i] + b[j-1], i, j + m});
            ans += edges.back()[0];
        }
    }
    sort(rall(edges));
    for(auto &edge: edges) {
        ans -= 1ll * edge[0] * Unio(edge[1], edge[2]);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}