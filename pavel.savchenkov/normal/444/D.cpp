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
const int MAXN = 5 * int(1e4) + 10;
const int INF = int(1e8);
const int BASE = 27;

char s[MAXN];
vi pos[BASE * BASE * BASE * BASE + BASE * BASE * BASE + BASE * BASE + BASE + 10];
map <pii, int> answer;

inline int code( char c ) {
	return int(c - 'a') + 1;
}

inline int calcHash( char* t ) {
	int len = (int) strlen(t);

	int hash = 0;

	forn(i, len) {
		hash = hash * BASE + code(t[i]);
	}

	return hash;
}

int main() {
	gets(s);

	int n = (int) strlen(s);
	forn(i, n) {
		int hash = 0;
		for (int len = 1; len <= 4 && i + len - 1 < n; ++len) {
			hash = hash * BASE + code(s[i + len - 1]);
			pos[hash].pb(i);
		}
	}

	int q;
	scanf("%d\n", &q);
	while (q --> 0) {
		char a[6];
		char b[6];

		scanf("%s %s\n", a, b);

		int hashA = calcHash(a);
		int hashB = calcHash(b);
		int la = (int) strlen(a);
		int lb = (int) strlen(b);

		pii id = mp(hashA, hashB);
		if  (answer.count(id)) {
			printf("%d\n", answer[id]);
			continue;
		}

		if  (sz(pos[hashA]) > sz(pos[hashB])) {
			swap(hashA, hashB);
			swap(la, lb);
		}

		int ans = INF;
		forn(i, sz(pos[hashA])) {
			int j = upper_bound(all(pos[hashB]), pos[hashA][i]) - pos[hashB].begin();

			if  (j < sz(pos[hashB])) {
				int r = max(pos[hashB][j] + lb - 1, pos[hashA][i] + la - 1);
				int l = min(pos[hashA][i], pos[hashB][j]);
				ans = min(ans, r - l + 1);
			}

			--j;
			if  (j >= 0) {
				int r = max(pos[hashB][j] + lb - 1, pos[hashA][i] + la - 1);
				int l = min(pos[hashA][i], pos[hashB][j]);
				ans = min(ans, r - l + 1);			
			}
		}

		if  (ans == INF) {
			ans = -1;
		}

		answer[id] = ans;
		printf("%d\n", ans);
	}

	return 0;
}