#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <complex>
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
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < n; i++)
#define FF(i,n) for(int i = 1; i <= n; i++)
#define println(x) printf("%d\n", x)
#define print(x) printf("%d ", x)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

map<int, vector<tuple<int, int, int> > > Qs;

vector<tuple<int, int, int> > qs;

const int N = 100000;

int BIT[N + 2];

int MN;
void upd(int p, int val) {
	while (p <= MN) {
		BIT[p] += val;
		p += p&-p;
	}
}
int sum(int p) {
	int ret = 0;
	while (p > 0) {
		ret += BIT[p];
		p -= p&-p;
	}
	return ret;
}

void init(int n) {
	MN = n;
	for (int i = 0; i <= MN; i++) BIT[i] = 0;
}

map<int, int> timetoid;
int ans[N];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	F(i, n) {
		int x, y, z;
		nii(x, y); ni(z);
		qs.emplace_back(x, y, z);
		if (x == 3) {
			timetoid[y] = i;
		}
		ans[i] = -1;
	}
	F(i, n) {
		Qs[get<2>(qs[i])].push_back(qs[i]);
	}
	for (auto &x : Qs) {
		vector<int> T;

		int sz = x.second.size();
		init(sz);

		for (auto &y : x.second) {
			T.push_back(get<1>(y));
		}
		sort(T.begin(), T.end());
		T.erase(unique(T.begin(), T.end()), T.end());
		for (auto &y : x.second) {
			int t = lower_bound(T.begin(), T.end(), get<1>(y)) - T.begin();

			int a = get<0>(y);
			if (a == 1) {
				upd(t + 1, 1);
			}
			else if (a == 2) {
				upd(t + 1, -1);
			}
			else {
				int s = sum(t + 1);
				int id = timetoid[get<1>(y)];
				ans[id] = s;
			}

		}
	}
	
	F(i, n) {
		if (ans[i] == -1)continue;
		println(ans[i]);
	}
}