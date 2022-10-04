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

const int N = 300000;
vector<int> noti[N];
int chk[N];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, q; nii(n, q);
	int cnt = 0; int l = 0;
	int num = 0;
	F(i, q) {
		int tp; ni(tp);
		if (tp == 1) {
			int x; ni(x);
			x--;
			noti[x].push_back(cnt++);
			num++;
		}
		else if (tp == 2) {
			int x; ni(x); x--;
			for (auto &y : noti[x]) {
				if (!chk[y]) {
					chk[y] = 1;
					num--;
				}
			}
			noti[x].clear();
		}
		else {
			int t; ni(t);
			while (l < t) {
				if (!chk[l]) {
					chk[l] = 1;
					num--;
				}
				l++;
			}
		}
		printf("%d\n", num);
	}

	return 0;
}