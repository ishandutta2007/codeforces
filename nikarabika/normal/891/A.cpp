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
    int ones = 0;
    bool has = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ones += a[i] == 1;
        if (i and __gcd(a[i], a[i - 1]) == 1)
            has = true;
    }
    if (ones)
        cout << n - ones << '\n';
    else if (has)
        cout << n << '\n';
    else {
        int ans = 1000 * 1000 * 100;
        for (int i = 0; i < n; i++) {
            int g = 0;
            for (int j = i; j < n; j++) {
                g = __gcd(g, a[j]);
                if (g == 1)
                    smin(ans, n - 1 + (j - i));
            }
        }
        if (ans == 1000 * 1000 * 100)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
	return 0;
}