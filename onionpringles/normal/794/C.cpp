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

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	string a, b;  cin >> a >> b;
	string res, res2;
	int n = a.size();
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int s1 = 0, e1 = (n + 1) / 2, s2 = n - n / 2, e2 = n;
	int tn = 0;
	while ((int)res.size() + (int)res2.size() < n ) {
		if (tn == 0) {
			if (a[s1] < b[e2 - 1]) {
				res.push_back(a[s1]);
				s1++;
			}
			else {
				res2.push_back(a[e1 - 1]);
				e1--;
			}
		}
		else {
			if (a[s1] < b[e2 - 1]) {
				res.push_back(b[e2 - 1]);
				e2--;
			}
			else {
				res2.push_back(b[s2]);
				s2++;
			}
		}
		tn ^= 1;
	}
	reverse(res2.begin(), res2.end());
	cout << res << res2 << "\n";
	return 0;
}