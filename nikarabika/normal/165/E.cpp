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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int maxn = 1e6 + 85 - 69, maxl = 22;
const int maxval = (1 << maxl) - 1;
int ans[maxval + 1], a[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(ans, -1, sizeof ans);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		ans[a[i]] = a[i];
	}
	for(int mask = 0; mask <= maxval; mask++)
		for(int i = 0; i < maxl; i++)
			if((mask >> i) & 1)
				smax(ans[mask], ans[mask ^ (1 << i)]);
	
	for(int i = 0; i < n; i++)
		cout << ans[maxval - a[i]] << ' ';
	cout << '\n';
	return 0;
}