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
    int n, sum;
    cin >> n >> sum;
    int l[n], r[n], ans[n];
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        sum -= l[i];
    }
    if (sum < 0)
        return cout << "NO\n", 0;
    for (int i = 0; i < n; i++) {
        int cur = min(r[i] - l[i], sum);
        sum -= cur;
        ans[i] = l[i] + cur;
    }
    if (sum > 0)
        return cout << "NO\n", 0;
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}