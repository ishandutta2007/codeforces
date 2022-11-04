#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

#define sz(x) (int) (x).size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

void run();

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    run();
    return 0;
}

const int N = (int) 1e5 + 123;
const int L = (int) sqrt(N);

int n;
int a[N];
int dp[N][L];

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int k = 1; k < min(L, n + 1); k++) {
        for (int i = n; i >= 1; i--) {
            int to = i + a[i] + k;
            if (to > n) {
                dp[i][k] = 1;
            } else {
                dp[i][k] = dp[to][k] + 1;
            }
        }
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int p, k;
        cin >> p >> k;
        if (k >= L) {
            int res = 0;
            while (p <= n) {
                p += a[p] + k;
                res++;
            }
            cout << res << "\n";
        } else {
            cout << dp[p][k] << "\n";
        }
    }
}