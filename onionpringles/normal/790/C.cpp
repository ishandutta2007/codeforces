#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <complex>
#include <iterator>
#include <random>
#include <time.h>
#include <tuple>
#include <functional>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)
#define FE(i,n) for(int i = 0; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 77;
int a[N][N][N][2]; //0: end with V, 1: end with else
vector<int> V[3];
char buf[N];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	scanf("%s", buf);
	F(i, n) {
		if (buf[i] == 'V')V[0].push_back(i);
		else if (buf[i] == 'K')V[1].push_back(i);
		else V[2].push_back(i);
	}
	FE(i, n)FE(j, n)FE(k, n)F(t, 2)a[i][j][k][t] = inf;
	a[0][0][0][1] = 0;
	FF(i, n) {
		FE(j, i) {
			FE(k, i - j) {
				if (j > (int)V[0].size() || k > (int)V[1].size())continue;
				if (i - j - k > (int)V[2].size())continue;
				int el = i - j - k;
				if (j) {
					int pos = V[0][j - 1];
					int fr = 0, bc = 0;
					F(t, k) {
						if (V[1][t] < pos)fr++;
						else bc++;
					}
					F(t, el) {
						if (V[2][t] < pos) fr++;
						else bc++;
					}
					a[i][j][k][0] = min(a[i][j][k][0], a[i - 1][j - 1][k][0] + pos + bc - i + 1);
					a[i][j][k][0] = min(a[i][j][k][0], a[i - 1][j - 1][k][1] + pos + bc - i + 1);
				}
				if (k) {
					if (i == 2 && j == 0 && k == 1) {
						int x = 2;
					}
					int pos = V[1][k - 1];
					int fr = 0, bc = 0;
					F(t, j) {
						if (V[0][t] < pos)fr++;
						else bc++;
					}
					F(t, el) {
						if (V[2][t] < pos) fr++;
						else bc++;
					}
					a[i][j][k][1] = min(a[i][j][k][1], a[i - 1][j][k - 1][1] + pos + bc - i + 1);
				}
				if (el) {
					int pos = V[2][el - 1];
					int fr = 0, bc = 0;
					F(t, j) {
						if (V[0][t] < pos)fr++;
						else bc++;
					}
					F(t, k) {
						if (V[1][t] < pos)fr++;
						else bc++;
					}
					a[i][j][k][1] = min(a[i][j][k][1], a[i - 1][j][k][0] + pos + bc - i + 1);
					a[i][j][k][1] = min(a[i][j][k][1], a[i - 1][j][k][1] + pos + bc - i + 1);
				}
			}
		}
	}
	/*FE(i, n)FE(j, n)FE(k, n)F(t, 2) {
		printf("%d %d %d %d %d\n", i, j, k, t, a[i][j][k][t]);
	}*/
	int X = V[0].size();
	int Y = V[1].size();
	printf("%d\n", min(a[n][X][Y][0], a[n][X][Y][1]));
	return 0;
}