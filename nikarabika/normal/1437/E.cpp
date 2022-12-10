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

const int INF = 1000 * 1000 * 1000 + 10;

int lis(int a[], int n, int st, int en) {
    multiset<int> s;
    for (int i = 0; i < n; i++) if (st <= a[i] and a[i] <= en) {
        if (s.upper_bound(a[i]) != s.end())
            s.erase(s.upper_bound(a[i]));
        s.insert(a[i]);
    }
    return s.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n], b[k];
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i] -= i;
    for (int i = 0; i < k; i++) {
        cin >> b[i], b[i]--;
        if (i and a[b[i - 1]] > a[b[i]])
            return cout << -1 << '\n', 0;
    }
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        int mn = i > 0 ? a[b[i - 1]] : -INF;
        int mx = i < k ? a[b[i]] : INF;
        int st = i > 0 ? b[i - 1] + 1 : 0;
        int en = i < k ? b[i] : n;
        if (st < en)
            ans += en - st - lis(&a[st], en - st, mn, mx);
    }
    cout << ans << '\n';
	return 0;
}