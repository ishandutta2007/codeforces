//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pii> pars[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            for (int k = 0; k <= j; k++)
                if (a[j] + a[k] == a[i])
                    pars[i].PB(pii(j, k));
    int ans = 10000;
    bool dp[1 << n] = {false};
    dp[1] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
        if (!dp[mask]) continue;
        int id = 32 - __builtin_clz(mask);
        if (id == n) {
            smin(ans, __builtin_popcount(mask));
            continue;
        }
        for (auto par: pars[id])
            if (((mask >> par.L) & 1) and ((mask >> par.R) & 1)) {
                int nmask = mask | (1 << id);
                dp[nmask] = 1;
                for (int i = 0; i < id; i++)
                    if (((mask >> i) & 1))
                        dp[nmask ^ (1 << i)] = true;
            }
    }
    cout << (ans < 100 ? ans : -1) << '\n';
	return 0;
}