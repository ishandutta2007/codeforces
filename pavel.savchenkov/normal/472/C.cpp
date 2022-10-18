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
const int MAXN = int(1e5 + 5);

string s[MAXN][2];
int p[MAXN];
int n;

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	scanf("%d", &n);

	FORN(i, n) {
		cin >> s[i][0] >> s[i][1];
		scanf("\n");
	}

	FORN(i, n) {
		scanf("%d", &p[i]);
		--p[i];
	}

	if  (s[p[0]][0] > s[p[0]][1]) {
		swap(s[p[0]][0], s[p[0]][1]);
	}

	for (int i = 1; i < n; ++i) {
		if  (s[p[i]][0] < s[p[i]][1]) {
			if  (s[p[i - 1]][0] < s[p[i]][0]) {
				// ok
			} else {
				swap(s[p[i]][0], s[p[i]][1]);
			}
		} else {
			if  (s[p[i]][1] > s[p[i - 1]][0]) {
				// ok
				swap(s[p[i]][1], s[p[i]][0]);
			} else {
				// stay
			}
		}	
	}
/*
	FORN(i, n) {
		cout << s[i][0] << '\n';
	}
*/
	FORN(i, n - 1) {
		if  (s[p[i]][0] >= s[p[i + 1]][0]) {
			puts("NO");
			return 0;
		}
	}

	puts("YES");
	return 0;
}