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
#define ALL(C) begin(C), end(C)

#define DEBUG(x) cerr << #x" = " << x << '\n';

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
const int MAXN = int(1e3 + 5);

char s[MAXN];
int n, p;

bool build( int pos ) {
	for (int i = pos; i < n; ++i) {
		s[i] = 0;

		for (char c = 'a'; c < 'a' + p; ++c) {
			if  (i - 1 >= 0 && c == s[i - 1]) {
				continue;
			}

			if  (i - 2 >= 0 && c == s[i - 2]) {
				continue;
			}

			s[i] = c;
			break;
		}

		if  (!s[i]) {
			return false;
		}
	}

	return true;
}

int main() {
	scanf("%d%d\n", &n, &p);

	gets(s);

	FORD(i, n) {
		for (char c = s[i] + 1; c < 'a' + p; ++c) {
			s[i] = c;

			if  (i - 1 >= 0 && c == s[i - 1]) {
				continue;
			}

			if  (i - 2 >= 0 && c == s[i - 2]) {
				continue;
			}

			if  (build(i + 1)) {
				puts(s);
				return 0;
			}	
		}
	}

	puts("NO");
	return 0;
}