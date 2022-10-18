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

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; i++)    
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgk
#define right yytrwtretywretwreytwreytwr
#define all(A) A.begin(), A.end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int MAXN = int(1e6) + 10;

struct action {
	int type;
	int l, c;
	int x;

	action( int l, int c ) : l(l), c(c) {
		type = 2;
	}

	action( int x ) : x(x) {
		type = 1;
	}
};

vector <action> actions;
int s[MAXN];
int L;
int m, n;

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	L = 0;
	bool to_actions = false;
	scanf("%d", &m);

	while (m --> 0) {
		int type;
		scanf("%d", &type);

		if  (type == 1) {
			int x;
			scanf("%d", &x);

			if  (L + 1 < MAXN && !to_actions) {
				s[L++] = x;
			} else {
				to_actions = true;
				actions.pb(action(x));
			}
		} else {
			assert(type == 2);

			int l, c;
			scanf("%d%d", &l, &c);
	
			while (c > 0 && !to_actions) {
				if  (L + l >= MAXN)
					break;
				c--;

				forn(i, l)
					s[L++] = s[i];
			}

			if  (c > 0) {
				to_actions = true;
				actions.pb(action(l, c));
			}
		}	
	}

	ll pos = 0;
	int id_action = 0;
	scanf("%d", &n);

	forn(i, n) {
		ll id;
		scanf("%I64d", &id);
		id--;

		while (1) {
			if  (pos < ll(L)) {
				if  (id < ll(L)) {
					printf("%d ", s[int(id)]);
					break;
				} else {
					pos++;
				}
			} else {
				int type = actions[id_action].type;

				if  (type == 1) {
					if  (pos == id) {
						printf("%d ", actions[id_action].x);
						break;
					} else {
						pos++;
						id_action++;
					}
				} else {
					int l = actions[id_action].l;
					int c = actions[id_action].c;

					if  (id < pos + l * 1ll * c) {
						printf("%d ", s[int((id - pos) % ll(l))]);
						break;
					} else {
						pos += l * 1ll * c;
						id_action++;
					}
				}
			}
		}
	}
		
	return 0;
}