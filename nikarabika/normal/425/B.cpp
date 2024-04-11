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

const int maxn = 100 + 85 - 69;
int a[maxn][maxn],
	b[maxn][maxn],
	n, m, k;

void solve1(void){
	int ans = 11;
	for(int mask = 0; mask < (1 << m); mask++){
		int cnt = 0;
		for(int i = 0; i < n; i++){
			int mask2 = 0;
			for(int j = 0; j < m; j++)
				mask2 = mask2 * 2 + a[i][j];
			cnt += min(__builtin_popcount(mask ^ mask2), m - __builtin_popcount(mask ^ mask2));
		}
		smin(ans, cnt);
	}
	if(ans <= k)
		cout << ans;
	else
		cout << -1;
	return;
}

void solve2(void){
	int ans = 11;
	for(int i = 0; i < n; i++){
		int cnt = 0;
		for(int ii = 0; ii < n; ii++){
			int cntmp = 0;
			for(int j = 0; j < m; j++)
				cntmp += a[i][j] ^ a[ii][j];
			cnt += min(cntmp, m - cntmp);
		}
		smin(ans, cnt);
	}
	if(ans <= k)
		cout << ans;
	else
		cout << -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	if(max(n, m) <= 10){
		solve1();
		return 0;
	}
	if(n <= 10){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				b[j][i] = a[i][j];
		swap(n, m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				a[i][j] = b[i][j];
	}
	solve2();
	return 0;
}