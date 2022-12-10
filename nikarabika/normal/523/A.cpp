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

const int maxn = 100 + 10;
char a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];
int n,m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	swap(n, m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	swap(n, m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			b[i][j] = a[m - j - 1][i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			c[i][j] = b[i][m - j - 1];
	for(int i = 0; i < 2 * n; i++, cout << '\n')
		for(int j = 0; j < 2 * m; j++)
			cout << c[i / 2][j / 2];
	return 0;
}