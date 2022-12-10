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

const int maxn = 5000 + 10;
LL dp[maxn][maxn];
LL a[maxn];
vector<LL> all;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        all.PB(a[i]);
    }
    all.PB(0);
    sort(all(all));
    all.resize(unique(all(all)) - all.begin());
    for (int i = 0; i < n; i++)
        a[i] = lower_bound(all(all), a[i]) - all.begin();
    memset(dp, 63, sizeof dp);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (LL j = 0; j < sz(all); j++) {
            smin(dp[i + 1][a[i]], dp[i][j] + max(0LL, all[a[i]] - all[j]));
            smin(dp[i + 1][min(a[i], j)], dp[i][j] + 1);
        }
    }

    cout << *min_element(dp[n], dp[n] + sz(all)) << '\n';
	return 0;
}