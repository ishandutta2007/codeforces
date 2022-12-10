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

int solve() {
    int n;
    cin >> n;
    vector<int> all;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        all.PB(a[i]);
    }
    sort(all(all));
    all.resize(unique(all(all)) - all.begin());
    vector<int> vec[sz(all)];
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(all), a[i]) - all.begin();
        vec[a[i]].PB(i + 1);
    }
    if (sz(all) == 1)
        return cout << "NO" << '\n', 0;
    cout << "YES\n";
    for (int i = 1; i < sz(all); i++)
        for (auto u: vec[i])
            cout << vec[0][0] << ' ' << u << '\n';
    for (int j = 1; j < sz(vec[0]); j++)
        cout << vec[0][j] << ' ' << vec[1][0] << '\n';
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}