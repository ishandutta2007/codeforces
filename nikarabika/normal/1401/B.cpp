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
    int x1, x2, y1, y2, z1, z2;
    cin >> x1 >> y1 >> z1
        >> x2 >> y2 >> z2;
    int ans = min(z1, y2);
    y2 -= ans;
    z1 -= ans;
    int tmp = min(y1, x2);
    y1 -= tmp;
    tmp = min(y1, y2);
    y1 -= tmp;
    ans -= y1;
    cout << ans * 2 << '\n';
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