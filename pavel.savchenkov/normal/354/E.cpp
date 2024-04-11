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
#define prev sdkljfskldjfkdsjflk

#define debug(x) cerr << #x" = " << x << '\n';

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
const int lucky[3] = { 0, 4, 7 };

vi repr[7 * 6 + 5];

void dfs(int sum, vi pr) {
	if  (sz(pr) == 6) {
		if  (repr[sum].empty()) {
			repr[sum] = pr;
		}
		return;
	}

	forn(i, 3) {
		pr.pb(lucky[i]);
		sum += lucky[i];
		dfs(sum, pr);
		pr.pop_back();
		sum -= lucky[i];
	}
}

void precalc() {
	vi pr;
	dfs(0, pr);
}

bool dp[20][15];
vi prev[20][15];

void solve(ll n) {
	vi N;
	while (n) {
		N.pb(n % 10);
		n /= 10;
	}

	// dp[pos][rest]
	// prev[pos][rest]
	memset (dp, false, sizeof dp);
	dp[0][0] = true;
	for (int pos = 0; pos < sz(N); ++pos) {
		for (int rest = 0; rest < 10; ++rest) {
			if  (!dp[pos][rest]) {
				continue;
			}

			for (int sum = 0; sum <= 7 * 6; ++sum) {
				if  (repr[sum].empty()) {
					continue;
				}

				int dig = (sum + rest) % 10;

				if  (dig != N[pos]) {
					continue;
				}

				int nrest = (sum + rest) / 10;

				dp[pos + 1][nrest] = true;
				prev[pos + 1][nrest] = repr[sum];
			}
		}
	}

	if  (!dp[sz(N)][0]) {
		puts("-1");
		return;
	}

	vll res(6, 0);
	int rest = 0;
	int pos = sz(N);
	while (!(pos == 0 && rest == 0)) {
		vi cur = prev[pos][rest];

		forn(i, 6) {
			res[i] = res[i] * 10ll + cur[i];
		}

		int sum = 0;
		forn(i, 6) {
			sum += cur[i];
		}

		int dig = N[pos - 1];

		// (sum + rest) % 10 == dig
		rest = (dig - sum % 10 + 10) % 10;
		--pos; 
	}

	forn(i, 6) {
		printf("%I64d ", res[i]);
	}
	puts("");
}

int main() {
	precalc();

	int t;
	scanf("%d", &t);
	while (t --> 0) {
		ll n;
		scanf("%I64d", &n);

		solve(n);
	}

	return 0;
}