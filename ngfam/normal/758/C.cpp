#include <bits/stdc++.h>

using namespace std;

const int N = 111;

int n, m, x, y;
long long k, f[N][N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	cin >> n >> m >> k >> x >> y;	

	if(n == 1){
		for(int i = 1; i <= m; ++i){
			f[1][i] += k / m;
		}
		k %= m;

		cout << f[1][1] + (k > 0) << " " << f[1][m] << " " << f[x][y] + (k >= y);
		return 0;
	}

	long long each = m * ((n - 2) * 2 + 2);
	long long times = k / each;

//	return 0;

	k -= each * times;

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			f[i][j] = times;
			if(i != 1 && i != n) f[i][j] += times;
		}		
	}

	int dir = 1;
	int curx = 1, cury = 0;

	while(k > 0){
		++cury;
		if(cury > m){
			curx += dir;
			if(curx == n){
				dir = -1;
			}
			cury = 1;
		}
		++f[curx][cury];
		--k;	
	}

	long long minvalues = f[1][1], maxvalues = f[1][1];

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			minvalues = min(minvalues, f[i][j]);
			maxvalues = max(maxvalues, f[i][j]);
		}
	}

	cout << maxvalues << " " << minvalues << " " << f[x][y];

	return 0;
}