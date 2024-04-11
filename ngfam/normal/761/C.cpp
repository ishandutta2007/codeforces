#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int f[N][10], n, m;
char s[N][N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%s", s[i] + 1);
	}

	memset(f, 60, sizeof f);
	f[0][0] = 0;

	for(int i = 1; i <= n; ++i){
		for(int mask = 0; mask < 8; ++mask){
			for(int j = 1; j <= m; ++j){
				int steps = min(j - 1, m - j + 1);
				int newmask = mask;
				if(s[i][j] >= 'a' && s[i][j] <= 'z'){
					newmask |= 1;		
				}
			  if(s[i][j] == '&' || s[i][j] == '*' || s[i][j] == '#'){
			  	newmask |= 2;	
			  }
			  if(s[i][j] >= '0' && s[i][j] <= '9'){
			  	newmask |= 4;
			  }
			  f[i][newmask] = min(f[i][newmask], f[i - 1][mask] + steps);
			}
		}
	}

	cout << f[n][7];

	return 0;
}