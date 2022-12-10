//sobskdrbhvk
//remember the flying, the bird dies ):(
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

const int maxn = 2e5 + 85 - 69;
LL c[maxn],
   v[maxn],
   g[maxn],
   sum[maxn];
LL n, k, s, t;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> s >> t;
	for(int i = 0; i < n; i++)
		cin >> c[i] >> v[i];
	for(int i = 0; i < k; i++)
		cin >> g[i];
	sort(g, g + k);
	g[k] = s - g[k - 1];
	for(int i = k - 1; i > 0; i--)
		g[i] = g[i] - g[i - 1];
	k++;
	sort(g, g + k);
	LL ans = 1000LL * 1000 * 1000;
	ans *= ans;
	LL inf = ans;
	for(int i = 0; i < k; i++)
		sum[i + 1] = sum[i] + g[i];
	for(int i = 0; i < n; i++){
		int id = upper_bound(g, g + k, v[i] / 2) - g;
		LL tim = sum[id];
		tim += 3LL * (sum[k] - sum[id]) - 1LL * (k - id) * v[i];
		if(g[k - 1] > v[i]) continue;
		if(tim <= t)
			smin(ans, c[i]);
	}
	if(ans == inf)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}