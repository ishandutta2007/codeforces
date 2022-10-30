#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e15 + 7;
const int N = (1 << 10), mod = 998244353;

int dp1[N], dp2[N];
int comm[10];

void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

void run() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int v1, v2; cin >> v1 >> v2;
        comm[v1] |= (1 << v2);
        comm[v2] |= (1 << v1);
    }
    dp1[0] = 1;
    for (int len = 0; len < n; ++len) {
        for (int mask = 0; mask < N; ++mask) {
            if (dp1[mask]) {
                for (int c = 0; c < 10; ++c) {
                    int tmsk = mask & comm[c] | (1 << c);
                    if ((tmsk & ((1 << c)-1)) == 0) {
                        add(dp2[tmsk], dp1[mask]);
                    }
                }
            }
        }
        fill(dp1, dp1+N, 0);
        swap(dp1, dp2);
    }
    cout << accumulate(dp1, dp1+N, 0ll) % mod;
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}