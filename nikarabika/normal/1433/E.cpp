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
    LL comb[n + 1][n + 1];
    memset(comb, 0, sizeof comb);
    comb[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= n; j++)
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
    LL ans = comb[n - 1][n / 2];
    n /= 2;
    LL Fn;
    if (n <= 2)
        Fn = 1;
    else {
        Fn = 1;
        for (int i = n - 1; i >= 1; i--)
            Fn *= i;
    }
    cout << ans * Fn * Fn << '\n';
	return 0;
}