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

const int maxn = 1000;
char a[maxn][maxn];
int row[maxn][maxn], col[maxn][maxn];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
//	cout << endl;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < m; j++)
			row[i][j] = (a[i][j] == '.' and a[i][j + 1] == '.');
	for(int i = 1; i < n; i++)
		for(int j = 1; j <= m; j++)
			col[i][j] = (a[i][j] == '.' and a[i + 1][j] == '.');
	for(int i = n; i >= 1; i--)
		for(int j = m - 1; j >= 1; j--)
			row[i][j] += row[i + 1][j] + row[i][j + 1] - row[i + 1][j + 1];
	for(int i = n - 1; i >= 1; i--)
		for(int j = m; j >= 1; j--)
			col[i][j] += col[i + 1][j] + col[i][j + 1] - col[i + 1][j + 1];
/*	for(int i = 1; i <= n; i++, cout << endl)
		for(int j = 1; j < m; j++)
			cout << row[i][j] << ' ';
	cout << endl;
	for(int i = 1; i < n; i++, cout << endl)
		for(int j = 1; j <= m; j++)
			cout << col[i][j] << ' ';
*/	int q;
	cin >> q;
	while(q--){
		int r1, r2, c1, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int ans = row[r1][c1] - row[r1][c2] - row[r2 + 1][c1] + row[r2 + 1][c2];
		ans += col[r1][c1] - col[r1][c2 + 1] - col[r2][c1] + col[r2][c2 + 1];
		cout << ans << '\n';
	}
	return 0;
}