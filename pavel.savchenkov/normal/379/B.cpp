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
const int MAXN = 310;

int n;
int a[MAXN];

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	scanf("%d", &n);
	int sum = 0;
	forn(i, n) {
		scanf("%d", &a[i]);
		sum += a[i];
	}

	int cnt = 0;
	while (sum > 0) {
		forn(i, n) {
			if  (a[i] > 0) {
				putchar('P');
				cnt++;
				sum--;
				a[i]--;
			}

			if  (i < n - 1) {
				cnt++;
				putchar('R');
			}
		}

		putchar('L');
		putchar('R');
		cnt += 2;

		ford(i, n) {
			if  (a[i] > 0) {
				putchar('P');
				cnt += 2;
				a[i]--;
				sum--;
			}

			if  (i) {
				putchar('L');
				cnt += 2;
			}
		}

		putchar('R');
		putchar('L');
	}

//	printf("cnt = %d\n", cnt);
	return 0;
}