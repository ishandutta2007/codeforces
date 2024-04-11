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
const int MAXN = 3000 + 10;

int a[MAXN];
int b[MAXN];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, m)
		scanf("%d", &b[i]);

	int ans = 0;
	forn(i, n) {
		bool ok = false;
		forn(j, m)
			if  (b[j] != -1 && b[j] >= a[i]) {
				b[j] = -1;
				ok = true;
				break;
			}
		ans += !ok;	
	}

	printf("%d\n", ans);	
	return 0;
}