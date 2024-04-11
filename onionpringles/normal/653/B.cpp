#pragma warning(disable:4996)

#include <stdio.h>
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
#include <tuple>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

char a[36][3];
char b[36];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<string> v;
	int n, q; nii(n, q);
	for (int i = 0; i < q; i++) scanf(" %s %c", a[i], b + i);
	v.push_back("a");
	for (int i = 2; i <= n; i++) {
		set<string> sss;
		for (auto &x : v) {
			int j = 0;
			for (int k = 0; k < q; k++) {
				if (x[j] == b[k]) {
					string tmp = x.substr(0, j);
					tmp = tmp + string(a[k], 2);
					tmp = tmp + x.substr(j + 1, i - 2 - j);
					sss.insert(tmp);
				}
			}
		}
		v = vector<string>(sss.begin(), sss.end());
	}
	printf("%d", v.size());
	
	return 0;
}