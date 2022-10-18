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

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) (C).begin(), (C).end()

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

const double EPS = 1e-9;

int main() {
	int n;
	scanf("%d", &n);

	vi a(n);
	vi left(n);
	vi right(n);

	forn(i, n) {
		scanf("%d", &a[i]);
	}

	left[0] = 1;
	for (int i = 1; i < n; ++i) {
		if  (a[i] > a[i - 1]) {
			left[i] = left[i - 1] + 1;
		} else {
			left[i] = 1;
		}
	}

	right[n - 1] = 1;
	for (int i = n - 2; i >= 0; --i) {
		if  (a[i] < a[i + 1]) {
			right[i] = right[i + 1] + 1;
		} else {
			right[i] = 1;
		}
	}

	int res = 1;
	for (int i = 1; i + 1 < n; ++i) {
		if  (a[i - 1] + 1 < a[i + 1]) {
			res = max(res, left[i - 1] + right[i + 1] + 1);
		}	
		res = max(res, left[i - 1] + 1);
		res = max(res, right[i + 1] + 1);
	}

	if  (n > 1) {
		res = max(res, right[1] + 1);
		res = max(res, left[n - 2] + 1);
	}

	printf("%d\n", res);
	return 0;
}