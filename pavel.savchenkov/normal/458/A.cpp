#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair 
#define SZ(C) ((int) (C).size())
#define FORN(i, n) for (int i = 0; i < (int) n; ++i)
#define FORD(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define ALL(C) (C).begin(), (C).end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef vector <vector<pii> > vvii;

constexpr double EPS = 1e-9;
constexpr double M_PI = acos(1.0);
const int MAXN = int(1e5) + 10;

char s[MAXN];
char t[MAXN];
int n;

char solve( int i ) {
	if  (i >= n) {
		return '=';
	}

	if  (s[i] == t[i]) {
		return solve(i + 1);
	}

	// 1
	if  (i + 1 >= n) {
		return s[i] == '1' ? '>' : '<';
	}

	if  (s[i + 1] == t[i + 1]) {
		return s[i] == '1' ? '>' : '<';
	}

	// 2
	if  (s[i] == '1' && s[i + 1] == '1') {
		return '>';
	}

	if  (t[i] == '1' && t[i + 1] == '1') {
		return '<';
	}

	// 3
	if  (i + 2 >= n) {
		return s[i] == '1' ? '>' : '<';
	}

	// 4
	if  (s[i + 2] == t[i + 2]) {
		s[i + 2] = s[i] == '1' ? '1' : '0';
		t[i + 2] = s[i] == '1' ? '0' : '1';
		return solve(i + 2);
	}

	if  (s[i] == '1' && t[i + 2] == '1') {
		return solve(i + 3);
	}

	if  (t[i] == '1' && s[i + 2] == '1') {
		return solve(i + 3);
	}

	// 5
	return s[i] == '1' ? '>' : '<';

}

main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	gets(s);
	gets(t);

	int ls = strlen(s);
	int lt = strlen(t);

	if  (ls > lt) {
		for (int i = lt - 1; i >= 0; --i) {
			t[i - (lt - 1) + (ls - 1)] = t[i];
		}

		for (int i = 0; i < -(lt - 1) + (ls - 1); ++i) {
			t[i] = '0';
		}
	} else {
		for (int i = ls - 1; i >= 0; --i) {
			s[i - (ls - 1) + (lt - 1)] = s[i];
		}

		for (int i = 0; i < -(ls - 1) + (lt - 1); ++i) {
			s[i] = '0';
		}
	}

	n = max(ls, lt);

	s[n] = 0;
	t[n] = 0;
	
//	puts(s);
//	puts(t);

	putchar(solve(0));

	return 0;
}