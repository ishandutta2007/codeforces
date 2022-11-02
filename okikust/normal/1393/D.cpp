#pragma GCC optimize("O3")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 2010


int main() {
	char a[N][N];
	bool b[N][N];
	int c[N][N];
	int xx[(N*N)];
	int yy[(N*N)];
	f(i, N) {
		f(j, N) {
			a[i][j] = 0;
			b[i][j] = false;
			c[i][j] = 0;
		}
	}
	int n, m, k;
	int x, y, z;
	int s, ans;
	int itr;
	bool v = true;
	scanf("%d %d", &n, &m);
	ans = n * m;
	f(i, n) {
		scanf("%s", a[i]);
	}
	for (int i = 1; i < (n - 1); i++) {
		for (int j = 1; j < (m - 1); j++) {
			x = 0;
			f(ii, 3) {
				f(jj, 3) {
					if ((abs(ii - 1) + abs(jj - 1)) < 2) {
						if (a[i][j] == a[i + ii - 1][j + jj - 1])x++;
					}
				}
			}
			if (x == 5)b[i][j] = true;
		}
	}

	f(i, n) {
		f(j, m) {
			if (!b[i][j]) {
				xx[itr] = i;
				yy[itr] = j;
				itr++;
			}
		}
	}
	f(i, n*m) {
		ans += c[xx[i]][yy[i]];
		f(ii, 3) {
			f(jj, 3) {
				if ((abs(ii - 1) + abs(jj - 1)) < 2) {
					if (b[xx[i] + ii - 1][yy[i] + jj - 1]) {
						c[xx[i] + ii - 1][yy[i] + jj - 1] = c[xx[i]][yy[i]] + 1;
						b[xx[i] + ii - 1][yy[i] + jj - 1] = false;
						xx[itr] = xx[i] + ii - 1;
						yy[itr] = yy[i] + jj - 1;
						itr++;
					}
				}
			}
		}
	}
	printf("%d\n", ans);


	return 0;
}