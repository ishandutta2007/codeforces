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
const int MAXN = 2000 + 10;

int t[MAXN];
int m[MAXN];
int h[MAXN];
int n;
bool used[MAXN];

int get( int first, int x ) {
	memset (used, false, sizeof used);

	int ans = 0;
	int prev = first;
	while (1) {
		int max_m = -1;
		int id = -1;
		forn(i, n)
			if  (!used[i] && x >= h[i] && t[i] != prev && m[i] > max_m) {
				max_m = m[i];
				id = i;
			}

		if  (id == -1) {
			break;
		}

		x += m[id];
		prev = t[id];
		used[id] = true;
		++ans;
	}

	return ans;
}

int x;

int main() {
	scanf("%d%d", &n, &x);

	forn(i, n) {
		scanf("%d%d%d", &t[i], &h[i], &m[i]);
	}

	printf("%d\n", max(get(1, x), get(0, x)));
	return 0;
}