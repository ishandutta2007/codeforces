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

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

int chk[301][301];
int d[2][301][301][8];
pair<int,int> di[8] = 
{
	{0,1},
	{0, -1},
	{1,0},
	{-1,0},
	{1,1},
	{1,-1},
	{-1,-1},
	{-1, 1}
};
int nxt[16] = {
	4,7,
	5,6,
	4,5,
	6,7,
	0,2,
	1,2,
	1,3,
	0,3
};
int sx = 150, sy = 150;
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	#endif
	int n; ni(n);
	int cur = 0;
	d[0][sx][sy][0] = 1;
	F(q, n) {
		int t; ni(t);
		F(i, 301)F(j, 301)F(k, 8)d[cur ^ 1][i][j][k] = 0;
		F(i, 301) {
			F(j, 301) {
				F(k, 8) {
					if (!d[cur][i][j][k])continue;
					int x = i, y = j;
					F(tt, t) {
						x += di[k].first;
						y += di[k].second;
						chk[x][y] = 1;
					}
					d[cur ^ 1][x][y][nxt[k << 1]] = 1;
					d[cur ^ 1][x][y][nxt[k << 1|1]] = 1;
				}
			}
		}
		cur ^= 1;
	}
	int ans = 0;
	F(i, 301)F(j, 301)ans += chk[i][j];
	printf("%d\n", ans);
	return 0;

}