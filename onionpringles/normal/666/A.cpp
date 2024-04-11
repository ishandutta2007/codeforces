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

int hsh3[10000];
int hsh2[10000];

char buf[10001];

int pos2[10000];
int pos3[10000];

set<int> ans;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", buf);
	int n = strlen(buf);
	for (int i = 0; i < n; i++) {
		if (i + 1 < n) {
			hsh2[i] = 26 * (buf[i] - 'a') + buf[i + 1] - 'a';
		}
		if (i + 2 < n) {
			hsh3[i] = 26 * 26 * (buf[i] - 'a' + 1) + 26 * (buf[i + 1] - 'a') + buf[i + 2] - 'a';
		}
	}
	F(i, n) {
		pos2[i] = pos3[i] = 1;
	}
	pos2[n - 1] = pos3[n - 1] = 0;
	pos3[n - 2] = 0;
	pos2[n - 3] = 0;
	if (n <= 6) {
		puts("0"); return 0;
	}
	ans.insert(hsh2[n - 2]);
	if (n > 7) ans.insert(hsh3[n - 3]);
	for (int i = n - 4; i >= 5; i--) {
		pos2[i] = (hsh2[i] != hsh2[i+2] && pos2[i + 2]) || pos3[i+2];
		pos3[i] = (hsh3[i] != hsh3[i+3] && pos3[i+3] ) || pos2[i + 3];
		if (pos2[i]) ans.insert(hsh2[i]);
		if (pos3[i]) ans.insert(hsh3[i]);
	}
	set<string> sans;
	char buf2[4] = { 0 };
	for (auto &x : ans) {
		if (x < 26 * 26) {
			buf2[0] = x / 26 + 'a';
			buf2[1] = x % 26 + 'a';
			sans.insert(string(buf2, buf2 + 2));
		}
		else {
			int y = x - 26 * 26;
			buf2[0] = y / 26 / 26 + 'a';
			buf2[1] = y / 26 % 26 + 'a';
			buf2[2] = y % 26 + 'a';
			sans.insert(string(buf2, buf2 + 3));
		}
	}
	printf("%d\n", sans.size());
	for (auto &x : sans) {
		printf("%s\n", x.c_str());
	}
	return 0;
}