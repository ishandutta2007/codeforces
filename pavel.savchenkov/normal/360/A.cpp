#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = int(a); i < int(n); i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define all(A) A.begin(), A.end()
#define sqr(x)((x) * (x))

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int MAXN = 5 * int(1e3) + 10;
const int INF = int(1e9);

int a[MAXN];
int add[MAXN];
int n, m;

int L[MAXN];
int R[MAXN];
bool type[MAXN];
int PAR[MAXN];

bool check() {    
	forn(j, m)
		if  (type[j]) {
			int l = L[j];
			int r = R[j];
			int m = PAR[j];

			int mx = -INF;
			for (int i = l; i <= r; i++)
				mx = max(mx, a[i]);

			if  (mx != m)
				return false;
		} else {
			int l = L[j];
			int r = R[j];
			int d = PAR[j];

			for (int i = l; i <= r; i++)
				a[i] += d;
		}

	return true;
}

int main() {
	scanf("%d%d", &n, &m);

	forn(i, n) {
		a[i] = INF;
		add[i] = 0;
	}

	forn(j, m) {
		int t;
		scanf("%d", &t);

		if  (t == 1) {
			int l, r, d;
			scanf("%d%d%d", &l, &r, &d);
			l--; r--;

			for (int i = l; i <= r; i++)
				add[i] += d;

			type[j] = false;
			L[j] = l;
			R[j] = r;
			PAR[j] = d;
		} else {
			assert(t == 2);

			int l, r, m;
			scanf("%d%d%d", &l, &r, &m);
			l--; r--;

			for (int i = l; i <= r; i++) {
				//a[i] + add[i] <= m -> a[i] <= m - add[i]

				if  (a[i] > m - add[i])
					a[i] = m - add[i];
			}

			type[j] = true;
			L[j] = l;
			R[j] = r;
			PAR[j] = m;
		}
	}

	if  (check()) {
		puts("YES");
		forn(i, n)
			printf("%d ", a[i] - add[i]);
	} else {
		puts("NO");
	}

	return 0;
}