#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int mod = 1e9 + 7;

int n;
int a[N];
int pre[N];
long long nCk[N][N];
long long f[2][N][N][N][N];

void add(long long &u, long long v){
	u += v;
	if(u >= mod) u -= mod;
}

long long mul(long long u, long long v){
	u *= v;
	return u % mod;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);

	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		pre[i] = pre[i - 1] + a[i];
	}

	nCk[0][0] = 1;

	for(int i = 1; i <= n; ++i){
		nCk[i][0] = 1;
		for(int j = 1; j <= i; ++j){
			nCk[i][j] = nCk[i - 1][j - 1] + nCk[i - 1][j];
			nCk[i][j] %= mod;
		}
	}

	if(a[1] == 2){
		if(a[2] == 2){
			f[0][1][0][1][0] = 1;
		}
		else{
			f[0][1][0][0][1] = 1;
		}
	}
	else{
		if(a[2] == 2){
			f[0][0][1][1][0] = 1;
		}
		else{
			f[0][0][1][0][1] = 1;
		}
	}

	int flag = 0;

	for(int i = 3; i <= n; ++i){
		flag = 1 - flag;
		memset(f[flag], 0, sizeof f[flag]);

		for(int x = 0; x <= i - 1; ++x){
			for(int y = 0; y <= i - 1 - x; ++y){
				for(int u = 0; u <= i - 1 - x - y; ++u){
					for(int v = 0; v <= i - 1 - x - y - u; ++v){
						long long value = f[1 - flag][x][y][u][v];					


						if(value == 0) continue;



						if(x + y > 0){
							if(x > 0){
								if(a[i] == 3){
									add(f[flag][x - 1][y][u][v + 1], value * x % mod);
									if(u > 0) add(f[flag][x - 1][y][u][v], value * x * u % mod);
									if(v > 0) add(f[flag][x - 1][y][u + 2][v - 1], value * x * v % mod);	
									if(u >= 2) add(f[flag][x - 1][y][u - 2][v], value * mul(nCk[u][2], x) % mod);
									if(v >= 2) add(f[flag][x - 1][y][u + 2][v - 2], value * mul(nCk[v][2], x) % mod);
									if(u > 0 && v > 0) add(f[flag][x - 1][y][u][v - 1], value * x * u * v % mod);
								}
								else{
									add(f[flag][x - 1][y][u + 1][v], value * x % mod);
									if(u > 0) add(f[flag][x - 1][y][u - 1][v], value * x * u % mod);
									if(v > 0) add(f[flag][x - 1][y][u + 1][v - 1], value * x * v % mod);	
								}
							}
							if(y > 0){
								if(a[i] == 3){
									add(f[flag][x + 1][y - 1][u][v + 1], value * y % mod);
									if(u > 0) add(f[flag][x + 1][y - 1][u][v], value * y * u % mod);
									if(v > 0) add(f[flag][x + 1][y - 1][u + 2][v - 1], value * y * v % mod);	
									if(u >= 2) add(f[flag][x + 1][y - 1][u - 2][v], value * mul(nCk[u][2], y) % mod);
									if(v >= 2) add(f[flag][x + 1][y - 1][u + 2][v - 2], value * mul(nCk[v][2], y) % mod);
									if(u > 0 && v > 0) add(f[flag][x + 1][y - 1][u][v - 1], value * y * u * v % mod);
								}
								else{
									add(f[flag][x + 1][y - 1][u + 1][v], value * y % mod);
									if(u > 0) add(f[flag][x + 1][y - 1][u - 1][v], value * y * u % mod);
									if(v > 0) add(f[flag][x + 1][y - 1][u + 1][v - 1], value * y * v % mod);	
								}	
							}
						}
						else{
							if(a[i] == 3){
								if(u > 0) add(f[flag][u - 1][v][0][1], value * u % mod);
								if(v > 0) add(f[flag][u + 1][v - 1][0][1], value * v % mod);
							}
							else{
								if(u > 0) add(f[flag][u - 1][v][1][0], value * u % mod);
								if(v > 0) add(f[flag][u + 1][v - 1][1][0], value * v % mod);	
							}
						}
					}
				}
			}
		}
	}

	cout << f[flag][0][0][0][0];

	return 0;
}