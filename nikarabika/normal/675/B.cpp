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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b, c, d;
	LL ans = 0;
	cin >> n >> a >> b >> c >> d;
	for(int i = 1; i <= n; i++){
		int s = a + b + i;
		int v1 = 0;
		int v2 = s - (a + c + i);
		int v3 = s - (b + d + i);
		int v4 = s - (c + d + i);
		int nan = min(min(v1, v2), min(v3, v4));
		int xan = max(max(v1, v2), max(v3, v4));
		xan += abs(nan) + 1;
		ans += 1LL * max(0, n + 1 - xan);
	}
	cout << ans << endl;
	return 0;
}