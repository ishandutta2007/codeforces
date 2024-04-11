#include <bits/stdc++.h>

using namespace std;

const int N = 555;

char s[N][N];

int n, m, f[N][N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; ++i){
		scanf("%s", s[i] + 1);	
	}

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
		 	f[i][j]  = f[i - 1][j] + (s[i][j] == '.' && s[i - 1][j] == '.');
		 	f[i][j] += f[i][j - 1] + (s[i][j] == '.' && s[i][j - 1] == '.');
		 	f[i][j] -= f[i - 1][j - 1];
		}
	}

	int q; scanf("%d", &q);

	while(q--){
		int x, y, u, v;
		scanf("%d%d%d%d", &x, &y, &u, &v);

		int result = f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1];

		for(int i = x; i <= u; ++i){
			result -= (s[i][y] == '.' && s[i][y - 1] == '.');
		}
		for(int i = y; i <= v; ++i){
			result -= (s[x][i] == '.' && s[x - 1][i] == '.');
		}
		printf("%d\n", result);
	}
}