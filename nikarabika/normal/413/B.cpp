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

const int maxn = 2e4, maxm = 10;
int a[maxn][maxm];
int ans[maxn],
	chans[maxm];
int n, m, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < k; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		ans[fi]--;
		chans[se]++;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			ans[i] += chans[j] * a[i][j];
		cout << ans[i] << ' ';
	}
	return 0;
}