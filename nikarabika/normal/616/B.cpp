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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	int ans = 1;
	for(int j = 0; j < n; j++){
		int Min = 1000LL * 1000 * 1000;
		for(int i = 0; i < m; i++)
			smin(Min, a[j][i]);
		smax(ans, Min);
	}
	cout << ans << endl;
	return 0;
}