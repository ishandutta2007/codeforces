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

int m;
string gen() {
	string s = "Aa";
	s[0] = s[0] + m / 26;
	s[1] = s[1] + m % 26;
	m++;
	return s;
}

vector<string> r;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, k; nii(n, k);
	F(i, k - 1) {
		string s = gen();
		r.push_back(s);
		printf("%s ", s.c_str());
	}
	char buf[4];
	F(i, n - k + 1) {
		scanf("%s", buf);
		if (buf[0] == 'Y') {
			string s = gen();
			printf("%s ", s.c_str());
			r.push_back(s);
		}
		else {
			string s = r[i];
			r.push_back(s);
			printf("%s ", s.c_str());
		}
	}
	puts("");

	return 0;
}