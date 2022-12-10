//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

void solve(void){
	LL n, m, x, y, xx, yy;
	cin >> n >> m >> x >> y >> xx >> yy;
	if(x > xx)
		swap(x, xx), swap(y, yy);
	if(y > yy)
		y = m + 1 - y, yy = m + 1 - yy;
	LL px1, px2, py1, py2;
	px1 = n - (xx - x);
	py1 = m - (yy - y);
	px2 = xx - x + 1;
	py2 = yy - y + 1;
	LL ans = n * m - px1 * py1 - (n + 1 - px2) * (m + 1 - py2);
	if(px1 >= px2 and py1 >= py2)
		ans += (px1 - px2 + 1) * (py1 - py2 + 1);
	cout << ans << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}