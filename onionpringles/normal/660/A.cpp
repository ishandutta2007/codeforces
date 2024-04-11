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

const int N = 2000;

int a[N];

int gcd(int a, int b) {
	if (!b) return a;
	else return gcd(b, a%b);
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n); F(i, n)ni(a[i]);
	vector<int> ans;
	ans.push_back(a[0]);
	FF(i, n - 1) {
		int g = gcd(a[i], a[i - 1]);
		if (g == 1) {
			ans.push_back(a[i]);
		}
		else {
			ans.push_back(1);
			ans.push_back(a[i]);
		}
	}
	println(ans.size() - n);
	for (auto &x : ans) print(x);

	return 0;
}