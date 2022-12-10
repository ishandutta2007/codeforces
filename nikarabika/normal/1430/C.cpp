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
    set<int, greater<int>> s;
    vector<pii> vec;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    for (int i = 1; i < n; i++) {
        int x = *s.begin();
        s.erase(s.begin());
        int y = *s.begin();
        s.erase(s.begin());
        vec.PB({x, y});
        s.insert((x + y + 1) / 2);
    }
    cout << *s.begin() << '\n';
    for (auto p : vec)
        cout << p.L << ' ' << p.R << '\n';
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