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
const int MAXN = 3 * int(1e5) + 10;
const ll INF = ll(1e18);

set <pii> free_by_a; // free
set <pii> free_by_ab; // free
set <pii> free_only_b; // used only a

set <pii> used_by_a; // used only a
set <pii> used_by_b; // used a and b

int a[MAXN];
int b[MAXN];
int n, w;

int res[MAXN];

int main() {
	scanf("%d%d", &n, &w);

	forn(i, n) {
		scanf("%d%d", &a[i], &b[i]);

		b[i] = b[i] - a[i];

		free_by_a.insert(mp(a[i], i));
		free_by_ab.insert(mp(a[i] + b[i], i));
	}

	ll ans = 0;
	for (int cur_w = 1; cur_w <= w; ++cur_w) {
		// 1
		ll ans1 = INF;
		if  (!free_by_a.empty()) {
			ans1 = ans + 1ll * free_by_a.begin()->f;	
		}

		// 2
		ll ans2 = INF;
		if  (!used_by_a.empty() && !free_by_ab.empty()) {
			ans2 = ans - 1ll * used_by_a.rbegin()->f + 1ll * free_by_ab.begin()->f;
		}

		// 3
		ll ans3 = INF;
		if  (!free_only_b.empty()) {
			ans3 = ans + 1ll * free_only_b.begin()->f;
		}	

		// 4
		ll ans4 = INF;
		if  (!used_by_b.empty() && !free_by_ab.empty()) {
			ans4 = ans - 1ll * used_by_b.rbegin()->f + 1ll * free_by_ab.begin()->f;
		}

		// 1
		if  (ans1 <= ans2 && ans1 <= ans3 && ans1 <= ans4) {
			int id = free_by_a.begin()->s;

			free_by_a.erase(mp(a[id], id));
			free_by_ab.erase(mp(a[id] + b[id], id));
			used_by_a.insert(mp(a[id], id));
			free_only_b.insert(mp(b[id], id));
			ans = ans1;
			continue;
		}

		// 2
		if  (ans2 <= ans1 && ans2 <= ans3 && ans2 <= ans4) {
			int id_rem = used_by_a.rbegin()->s;
			int id = free_by_ab.begin()->s;
			
			used_by_a.erase(mp(a[id_rem], id_rem));
			free_by_a.insert(mp(a[id_rem], id_rem));
			free_by_ab.insert(mp(a[id_rem] + b[id_rem], id_rem));
			free_only_b.erase(mp(b[id_rem], id_rem));

			free_by_a.erase(mp(a[id], id));
			free_by_ab.erase(mp(a[id] + b[id], id));
			used_by_b.insert(mp(b[id], id));
			ans = ans2;
			continue;
		}

		if  (ans3 <= ans1 && ans3 <= ans2 && ans3 <= ans4) {
			int id = free_only_b.begin()->s;

			free_only_b.erase(mp(b[id], id));
			used_by_a.erase(mp(a[id], id));
			used_by_b.insert(mp(b[id], id));
			ans = ans3;
			continue;
		}

		assert(ans4 <= ans1 && ans4 <= ans2 && ans4 <= ans3);

		int id_rem = used_by_b.rbegin()->s;
	    int id = free_by_ab.begin()->s;

		used_by_b.erase(mp(b[id_rem], id_rem));
		used_by_a.insert(mp(a[id_rem], id_rem));
		free_only_b.insert(mp(b[id_rem], id_rem));

		free_by_a.erase(mp(a[id], id));
		free_by_ab.erase(mp(a[id] + b[id], id));
		used_by_b.insert(mp(b[id], id));
		ans = ans4;
	}

	cout << ans << '\n';

	memset (res, 0, sizeof res);

	for (set <pii> :: iterator it = used_by_a.begin(); it != used_by_a.end(); ++it) {
		res[it->s] = 1;
	}

	for (set <pii> :: iterator it = used_by_b.begin(); it != used_by_b.end(); ++it) {
		res[it->s] = 2;
	}

	forn(i, n)
		printf("%d", res[i]);
	return 0;
}