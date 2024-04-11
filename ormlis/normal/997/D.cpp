#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 5e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

const int maxF = 2e5 + 5;
int fact[maxF];
int rfact[maxF];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxF - 1] = rev(fact[maxF - 1]);
    for (int i = maxF - 1; i >= 1; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

int C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

vector<int> calc(int n, vector<pair<int, int>> edges, int k) {
    vector<int> ans(k + 1);
    vector<vector<int>> C(n + 1, vector<int>(k + 1));
    vector<vector<int>> B(n + 1, vector<int> (k + 1));
    vector<vector<int>> A(edges.size(), vector<int>(k + 1));
    range(i, n) C[i + 1][0] = 1;
    for (int d = 2; d <= k; d += 2) {
        range(i, (int) edges.size()) {
            auto[v, u] = edges[i];
            // A[i][k] cycle from u in k steps with don`t go to edge i
            if (d == 2) A[i][0] = 1;
            for (int was = 0; was < d - 2; was += 2) {
                A[i][d - 2] = add(A[i][d - 2], mul(A[i][d - 4 - was], sub(B[u][was], A[i ^ 1][was])));
            }
            B[v][d - 2] = add(B[v][d - 2], A[i][d - 2]);
            for (int was = 2; was <= d; was += 2) {
                C[v][d] = add(C[v][d], mul(A[i][was - 2], C[v][d - was]));
            }
        }
    }
    range(i, n + 1) range(j, k + 1) ans[j] = add(ans[j], C[i][j]);
    return ans;
}

void solve() {
    int n1, n2, k;
    cin >> n1 >> n2 >> k;
    vector<pair<int, int>> edges1, edges2;
    range(i, n1 - 1) {
        int u, v;
        cin >> u >> v;
        edges1.emplace_back(u, v);
        edges1.emplace_back(v, u);
    }
    range(i, n2 - 1) {
        int u, v;
        cin >> u >> v;
        edges2.emplace_back(u, v);
        edges2.emplace_back(v, u);
    }
    auto res1 = calc(n1, edges1, k);
    auto res2 = calc(n2, edges2, k);
    int result = 0;
    range(i, k + 1) {
        int j = k - i;
        result = add(result, mul(C(k, i), mul(res1[i], res2[j])));
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    init();
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}