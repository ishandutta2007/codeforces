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

ll solve( int* A, int l, int k ) {
	if  (l <= 0) {
		return 0;
	}

	ll a = 0;
	forn(i, l)
		a = a * 10ll + A[i];

	if  (k <= 0) {
		return a;
	}

	int mx = 0;
	forn(i, min(l, k + 1))
		mx = max(mx, A[i]);

//	printf("a = %I64d k = %d\n", a, k);
//	printf("mx = %d\n", mx);

	if  (mx == A[0]) {
		forn(i, l - 1)
			A[i] = A[i + 1];

		a = 0;
		forn(i, l - 1)
			a = a * 10ll + A[i];

		ll b = 1;
		forn(i, l - 1)
			b = b * 10ll;

		return mx * b + solve(A, l - 1, k);	
	}

	forn(i, min(k + 1, l))
		if  (A[i] == mx) {
			k -= i;
			for (int j = i; j > 0; --j)
				A[j] = A[j - 1];
			A[0] = mx;
			break;
		}

    a = 0;
    forn(i, l)
    	a = a * 10ll + A[i];

    return solve(A, l, k);
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	ll a;
	int k;
	
	cin >> a >> k;
	
	int A[20];
	int l = 0;
	while (a) {
		A[l++] = a % 10ll;
		a /= 10ll;
	}
	reverse(A, A + l);

	cout << solve(A, l, k) << '\n';
	return 0;
}