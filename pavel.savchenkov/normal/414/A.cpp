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
#define foran(i, a, n) for (int i = (int) a; i < (int) n; ++i)
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

const double EPS = 1e-9;

int n, k;

bool solve() {
	if  (n <= 1) {
		if  (k) {
			return false;
		}

		puts("1");
		return true;
	}

	int pairs = n / 2;
	int K = k - (pairs - 1);
	if  (K <= 0) {
		return false;
	}

	printf("%d %d ", K, K * 2);

	int cur = 1;
	forn(i, pairs - 1) {
		while  (cur == K || cur == K * 2 || cur + 1 == K || cur + 1 == K * 2) {
			++cur;
		}

		printf("%d %d ", cur, cur + 1);
		cur += 2;	
	}

	if  (n & 1) {
		while  (cur == K || cur == K * 2 || cur + 1 == K || cur + 1 == K * 2) {
			++cur;
		}

		printf("%d\n", cur);	
	}

	return true;
}

int main() {
	scanf("%d%d", &n, &k);

	if  (!solve()) {
		puts("-1");
	}
		
	return 0;
}