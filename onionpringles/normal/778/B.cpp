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

const int N = 5000;
const int B = 1 << 17;
struct L {
	string s;
	int op; //0c,1&,2|,3^
	int o1, o2;
} l[N];

vector<string> sn;
map<string, int> var;

int conv(const string& s) {
	if (s[0] == '?') return -1;
	else if (s[0] == '0' || s[0] == '1') {
		sn.push_back(s);
		return sn.size() - 1;
	}
	else {
		return B + var[s];
	}
}

string a1, a2;

int getval(const vector<int>& varv, int v, int j, int X) {
	if (v == -1) return X;
	else if (v >= B) return varv[v - B];
	else {
		return sn[v][j] - '0';
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	string foo, bar;
	getline(cin, foo);
	F(i, n) {
		getline(cin, foo);
		string op;
		stringstream ss(foo);
		ss >> l[i].s >> bar >> bar;
		var[l[i].s] = i;
		l[i].o1 = conv(bar);
		ss >> op;
		if (op.size() == 0) {
			l[i].op = 0;
		}
		else {
			ss >> bar;
			l[i].o2 = conv(bar);
			if (op[0] == 'A')l[i].op = 1;
			else if (op[0] == 'O')l[i].op = 2;
			else l[i].op = 3;
		}
	}
	F(j, m) {
		int X = 0;
		vector<int> val(n);
		F(i, n) {
			if (l[i].op == 0) {
				val[i] = getval(val, l[i].o1, j, X);
			}
			else if (l[i].op == 1) {
				val[i] = getval(val, l[i].o1, j, X) & getval(val, l[i].o2, j, X);
			}
			else if (l[i].op == 2) {
				val[i] = getval(val,l[i].o1, j, X) | getval(val,l[i].o2, j, X);
			}
			else {
				val[i] = getval(val,l[i].o1, j, X) ^ getval(val,l[i].o2, j, X);
			}
		}
		int s1 = 0;
		for (auto &s : val)s1 += s;
		val.clear();
		val.resize(n);
		X = 1;
		F(i, n) {
			if (l[i].op == 0) {
				val[i] = getval(val,l[i].o1, j, X);
			}
			else if (l[i].op == 1) {
				val[i] = getval(val,l[i].o1, j, X) & getval(val,l[i].o2, j, X);
			}
			else if (l[i].op == 2) {
				val[i] = getval(val,l[i].o1, j, X) | getval(val,l[i].o2, j, X);
			}
			else {
				val[i] = getval(val,l[i].o1, j, X) ^ getval(val,l[i].o2, j, X);
			}
		}
		int s2 = 0;
		for (auto &s : val)s2 += s;
		if (s1 == s2) {
			a1.push_back('0');
			a2.push_back('0');
		}
		else if (s1 < s2) {
			a1.push_back('0');
			a2.push_back('1');
		}
		else {

			a1.push_back('1');
			a2.push_back('0');
		}
	}
	cout << a1 << "\n" << a2 << "\n";
	return 0;
}