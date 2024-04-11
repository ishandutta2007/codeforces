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
#define all(C) begin(C), end(C)

#define debug(x) cout << #x" = " << x << '\n';

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
const int MAXN = 1e5 + 5;
const ll INF = 1e18;

ll mult(ll a, ll b) {
	if  (!a || !b) {
		return 0;
	}

	ll res = a * b;
	if  (res / b != a || a >= INF || b >= INF) {
		return INF;
	}

	return a * b;
}

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
	return a ? mult(a / gcd(a, b), b) : b;
}

int a[MAXN];       
vi g[MAXN];
int n;

ll min_sz[MAXN];
ll max_sz[MAXN];

void dfs(int v, int par) {
	if  (v && sz(g[v]) == 1) {
		min_sz[v] = 1;
		max_sz[v] = a[v];
		return;
	}

	int deg = 0;
	min_sz[v] = 0;
	max_sz[v] = INF;
	for (int to : g[v]) {
		if  (to != par) {
			dfs(to, v);
			min_sz[v] = lcm(min_sz[v], min_sz[to]);
			max_sz[v] = min(max_sz[v], max_sz[to]);
			++deg;
		}	
	}

	min_sz[v] *= deg;
	max_sz[v] *= deg;
}

int main() {
	cin >> n;
	forn(i, n) {
		scanf("%d", &a[i]);
	}

	forn(i, n - 1) {
		int v, u;
		scanf("%d%d", &v, &u);
		--v;
		--u;

		g[v].pb(u);
		g[u].pb(v);
	}

	dfs(0, -1);

	ll sum_a = 0;
	forn(i, n) {
		sum_a += a[i];
	}

	ll mn = min_sz[0];
	if  (mn == 0) {
		cout << sum_a << endl;
		return 0;
	}
	ll max_k = max_sz[0] / mn;

	// sum_a - mn * k --> min
	ll k = min(sum_a / mn, max_k);
	cout << (sum_a - mn * k) << endl;
    return 0;
}