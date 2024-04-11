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

const double EPS = 1e-9;
const int MAXN = int(1e5) + 10;

int fenw[MAXN];

int L;
int R;
int n, q;
bool rev;

void inc( int pos, int add ) {
	for (int i = pos; i < MAXN; i = i | (i + 1)) {
		fenw[i] += add;
	}
}

int sum( int r ) {
	int res = 0;
	for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
		res += fenw[i];
	}
	return res;
}

int sum( int l, int r ) {
	return sum(r) - sum(l - 1);
}
/*
void output() {
	printf("\n[%d, %d], rev = %d\n", L, R, rev);

	for (int i = L; i <= R; ++i) {
		printf("%d ", sum(i) - sum(i - 1));
	}

	puts("\n");
}
*/

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	scanf("%d%d", &n, &q);

	L = 0;
	R = n - 1;
	rev = false;
	memset (fenw, 0, sizeof fenw);

	FORN(i, n) {
		inc(i, 1);
	}

	while (q --> 0) {
		int t;
		scanf("%d", &t);

		if  (t == 1) {
			int p;
			scanf("%d", &p);

//			printf("p = %d\n", p);

			if  (rev) {
				int len = R - L + 1;
				int up = p;
				int down = len - p;
					
				if  (up > down) {
					rev = false;

					for (int i = R - p, j = R - p + 1; i >= L; --i, ++j) {
						inc(j, sum(i) - sum(i - 1));
				   	}

				   	L += len - p;
				} else {
					for (int i = R - p, j = R - p + 1; j <= R; --i, ++j) {
						inc(i, sum(j) - sum(j - 1));
				   	}

				   	R -= p;
				}
			} else {
				int len = R - L + 1;
				int up = p;
				int down = len - p;

				if  (up > down) {
					rev = true;

					for (int i = L + p - 1, j = L + p; j <= R; --i, ++j) {
						inc(i, sum(j) - sum(j - 1));
					}

					R -= len - p;
				} else {
					for (int i = L + p - 1, j = L + p; i >= L; --i, ++j) {
						inc(j, sum(i) - sum(i - 1));
					}

					L += p;					
				}
			}
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			--r;

			l += L;
			r += L;

			int len = R - L + 1;

			if  (rev) {
				l -= L;
				r -= L;

				l = len - 1 - l;
				r = len - 1 - r;

				l += L;
				r += L;

				swap(l, r);
            }

           	printf("%d\n", sum(l, r)); 
       	} 

//		output();
	}

	return 0;
}