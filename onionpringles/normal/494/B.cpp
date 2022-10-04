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
const ll infll = 9000000000000000000LL;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 101010;
char s[N], t[N];
class KMP {
public:
	char* str; int len;
	int fail[N];
	int next(int u, char c) {
		while (u == len || u&&str[u] != c)u = fail[u];
		if (str[u] == c)return u + 1;
		else return 0;
	}
	void init(char* _str, int _len) {
		str = _str;
		len = _len;
		fail[0] = fail[1] = 0;
		for (int i = 2; i <= len; i++) {
			fail[i] = next(fail[i - 1], str[i - 1]);
		}
	}
} kmp;

int d[N];

int tr[N];
void upd(int i, int v, int n) {
	i++;
	while (i <= n) {
		tr[i] += v;
		if (tr[i] >= mod)tr[i] -= mod;
		i += i&(-i);
	}
}
int get(int i) {
	i++;
	int ans = 0;
	while (i) {
		ans += tr[i];
		if (ans >= mod) ans -= mod;
		i -= i&(-i);
	}
	return ans;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	scanf("%s %s", s, t);
	int n = strlen(s);
	int m = strlen(t);
	kmp.init(t, m);
	int cur = 0;
	vector<int> oc;
	F(i, n) {
		cur = kmp.next(cur, s[i]);
		if (cur == m) {
			oc.push_back(i);
		}
	}
	int c = 0;
	cur = -inf;
	F(i, n) {
		if (c < (int)oc.size() && oc[c] == i) {
			cur = oc[c] - m;
			c++;
		}
		if(c) d[i] = get(cur) + 1;
		if(i)d[i] += d[i - 1];
		else d[i] += 1;
		if (d[i] >= mod) d[i] -= mod;
		upd(i, d[i], n);
	}
	printf("%d\n", (d[n - 1] + mod - 1)%mod);

	return 0;
}