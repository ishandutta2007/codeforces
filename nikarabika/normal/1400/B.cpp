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
    LL p, f, cnts, cntw, s, w;
    cin >> p >> f >> cnts >> cntw >> s >> w;
    if (s > w)
        swap(s, w), swap(cnts, cntw);
    LL ans = 0;
    for (int i = 0; i <= cnts; i++) if (i * s <= p) {
        LL j = min(cnts - i, f / s);
        LL remi = p - i * s;
        LL remj = f - j * s;
        LL wi = min(cntw, remi / w);
        LL wj = min(cntw - wi, remj / w);
        LL cur = i + j + wi + wj;
        if (cur > ans)
            ans = cur;
    }
    cout << ans << '\n';
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