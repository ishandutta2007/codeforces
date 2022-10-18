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
const int MAXN = 3 * int(1e5) + 5;
const int MOD = int(1e9) + 9;

struct Query {
	int type, l, r;

	Query() {}

	void read() {
		scanf("%d%d%d", &type, &l, &r);
		--l;
		--r;
	}
};

void add( int &x, int y ) {
	if  ((x += y) >= MOD) {
		x -= MOD;
	}
}

int a[MAXN];
int sum[MAXN];
int F[MAXN];
int sumF[MAXN];
int n, m;
int b[MAXN];

vi whoEnd[MAXN];
vi whoStart[MAXN];

void precalc() {
	F[0] = F[1] = 1;
	for (int i = 2; i < n; ++i) {
		F[i] = 0;
		add(F[i], F[i - 2]);
		add(F[i], F[i - 1]);
	}

	sumF[0] = F[0];
	for (int i = 1; i < n; ++i) {
		sumF[i] = 0;
		add(sumF[i], sumF[i - 1]);
		add(sumF[i], F[i]);
	}
}

void calcSum() {
	sum[0] = a[0];
	for (int i = 1; i < n; ++i) {
		sum[i] = 0;
		add(sum[i], sum[i - 1]);
		add(sum[i], a[i]);
	}
}

int getSum( int l, int r ) {
	int res = sum[r];
	if  (l > 0) {
		add(res, -sum[l - 1] + MOD);
	}
	return res;
}

int getSumF( int l, int r ) {
	int res = sumF[r];
	if  (l > 0) {
		add(res, -sumF[l - 1] + MOD);
	}
	return res;
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	scanf("%d%d", &n, &m);

	precalc();

	forn(i, n) {
		scanf("%d", &a[i]);
	}

	int sqrtM = 1;
	while (sqrtM * sqrtM <= m) ++sqrtM;

	calcSum();

	vector <Query> Q;
	while (m --> 0) {
		Q.pb(Query());
		Q.back().read();

		if  (Q.back().type == 2) {
			int L = Q.back().l;
			int R = Q.back().r;

			int res = getSum(L, R);
			forn(i, sz(Q)) {
				if  (Q[i].type == 1) {
					int l = Q[i].l;
					int r = Q[i].r;

					int ll = max(l, L);
					int rr = min(r, R);

					if  (ll > rr) {
						continue;
					}

					add(res, getSumF(ll - l, rr - l));
				}
			}

			printf("%d\n", res);
		}

		if  (sz(Q) >= sqrtM) {
			forn(i, sz(Q)) {
				if  (Q[i].type == 1) {
					int l = Q[i].l;
					int r = Q[i].r;

//					printf("[%d, %d]\n", l, r);
					whoStart[l].pb(i);
					whoEnd[r].pb(i);
				}
			}	


			forn(i, n) {
				b[i] = 0;
				if  (i - 1 >= 0) {
					add(b[i], b[i - 1]);
				}
				if  (i - 2 >= 0) {
					add(b[i], b[i - 2]);
				}

				// 1
				add(b[i], sz(whoStart[i]));

				// 5
				if  (i - 1 >= 0) {
					forn(j, sz(whoEnd[i - 1])) {
						int l = Q[whoEnd[i - 1][j]].l;
						int len = i - 1 - l + 1;

						add(b[i], -F[len - 1] + MOD);
						if  (len >= 2) {
							add(b[i], -F[len - 2] + MOD);
						}
					}	
				}

				// 6
				if  (i - 2 >= 0) {
					forn(j, sz(whoEnd[i - 2])) {
						int l = Q[whoEnd[i - 2][j]].l;
						int len = i - 2 - l + 1;

						add(b[i], -F[len - 1] + MOD);
					}
				}
			}

			forn(i, n) {
				add(a[i], b[i]);
			}
			calcSum();


			forn(i, sz(Q)) {
				if  (Q[i].type == 1) {
					int l = Q[i].l;
					int r = Q[i].r;

					whoStart[l].clear();
					whoEnd[r].clear();
				}
			}

			Q.clear();
		}
	}

	return 0;
}