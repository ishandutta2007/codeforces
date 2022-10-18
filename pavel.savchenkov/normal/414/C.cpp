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
const int MAXN = (1 << 21) + 10;
const int MAXLOG = 22;

ll left_big[MAXN];
ll right_big[MAXN];
ll sum_left_big[MAXLOG];
ll sum_right_big[MAXLOG];
ll INV = 0;
int val[MAXN];
int sz;

void build( int v, int l, int r, int de ) {
	if  (l == r) {
		return;
	}

	int m = (l + r) >> 1;
	build(v * 2, l, m, de - 1);
	build(v * 2 + 1, m + 1, r, de - 1);

	left_big[v] = right_big[v] = 0;
	int L = (r - l + 1) >> 1;

	for (int i = l; i <= m; ++i) {
		int pos = upper_bound(val + m + 1, val + r + 1, val[i]) - (val + m + 1);
		right_big[v] += L - pos;
	}

	for (int i = m + 1; i <= r; ++i) {
		int pos = upper_bound(val + l, val + m + 1, val[i]) - (val + l);
		left_big[v] += L - pos;
	}

	sum_left_big[de] += left_big[v];
	sum_right_big[de] += right_big[v];
	INV += left_big[v];

	sort(val + l, val + r + 1);
}

int n;

void build() {
	build(1, 0, sz - 1, n);
}

int main() {
	scanf("%d", &n);
	sz = 1 << n;

	forn(i, sz) {
		scanf("%d", &val[i]);
	}

	build();
		
	int m;
	scanf("%d", &m);
	while (m --> 0) {
		int q;
		scanf("%d", &q);

		for (int de = q; de; --de) {
			INV -= sum_left_big[de];
			INV += sum_right_big[de];
			swap(sum_left_big[de], sum_right_big[de]);
		}

		printf("%I64d\n", INV);	
	}

	return 0;
}