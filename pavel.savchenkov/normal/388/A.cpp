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
const int MAXN = 100 + 10;

int x[MAXN];
int cnt[MAXN];
int n;

int main() {
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &x[i]);
	}

	sort(x, x + n);
    
    memset (cnt, -1, sizeof cnt);

    int res = n;

	forn(i, n)
		if  (cnt[i] == -1) {
			for (int j = i + 1; j < n; j++)
				if  (x[j] >= 1 && cnt[j] == -1) {
					cnt[j] = 2;
					res--;
					break;	
				}
		} else {
			for (int j = i + 1; j < n; j++)
				if  (x[j] >= cnt[i] && cnt[j] == -1) {
					cnt[j] = cnt[i] + 1;
					res--;
					break;
				}
		}

	printf("%d\n", res);	
	return 0;
}