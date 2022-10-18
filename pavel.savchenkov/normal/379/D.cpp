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
const ll INF = ll(1e9) + 10ll;

ll add( ll a, ll b ) {
	if  (a + b > INF)
		return INF;

	return a + b;
}

ll mul( ll a, ll b ) {
	if  (a >= INF && b >= INF)
		return INF;

	if  (a * b >= INF)
		return INF;

	return a * b;
}

int k, x, n, m;

ll both[60][2][2];
ll cnt[60][2];
int end[60];
int start[60];

char s1[200];
char s2[200];
char ch[3] = { 'A', 'C', 'X' };

int main() {
	scanf("%d%d%d%d", &k, &x, &n, &m);
	k--;

	memset (both, 0, sizeof both);
	memset (cnt, 0, sizeof cnt);
	cnt[0][0] = 1ll;
	cnt[1][1] = 1ll;
	end[0] = start[0] = 0;
	end[1] = start[1] = 1;

	for (int i = 2; i <= k; i++) {
		forn(i1, 2)
			cnt[i][i1] = add(cnt[i - 2][i1], cnt[i - 1][i1]);

		start[i] = start[i - 2];
		end[i] = end[i - 1];

		forn(i1, 2)
			forn(i2, 2)
				both[i][i1][i2] = add(both[i - 2][i1][i2], both[i - 1][i1][i2]);

		both[i][end[i - 2]][start[i - 1]]++;
	}

//	cout << cnt[k][1] << '\n';

	forn(i, n)
		s1[i] = 'X';
	s1[n] = 0;

	forn(i, m)
		s2[i] = 'X';
	s2[m] = 0;

	for (int cnt0 = 0; cnt0 <= n / 2; cnt0++)
		for (int cnt1 = 0; cnt1 <= m / 2; cnt1++)
			for (int c00 = 0; c00 < 3; c00++)
				for (int c01 = 0; c01 < 3; c01++)
					for (int c10 = 0; c10 < 3; c10++)
						for (int c11 = 0; c11 < 3; c11++) {
							int len0 = n;
							if  (ch[c00] != 'A')
								len0--;
							if  (ch[c01] != 'C')
								len0--;

							if  (len0 / 2 < cnt0)
								continue;

							int len1 = m;
							if  (ch[c10] != 'A')
								len1--;
							if  (ch[c11] != 'C')
								len1--;

							if  (len1 / 2 < cnt1)
								continue;

							if  (n == 1 && c01 != c00)
								continue;

							if  (m == 1 && c11 != c10)
								continue;

							if  (n == 2 && ch[c00] == 'A' && ch[c01] == 'C' && cnt0 != 1)
								continue;

							if  (m == 2 && ch[c10] == 'A' && ch[c11] == 'C' && cnt1 != 1)
								continue;

							ll ans = 0;
							if  (ch[c01] == 'A' && ch[c00] == 'C')
								ans = add(ans, both[k][0][0]);

							if  (ch[c01] == 'A' && ch[c10] == 'C')
								ans = add(ans, both[k][0][1]);

							if  (ch[c11] == 'A' && ch[c00] == 'C')
								ans = add(ans, both[k][1][0]);

							if  (ch[c11] == 'A' && ch[c10] == 'C')
								ans = add(ans, both[k][1][1]);

							ans = add(ans, mul(cnt0, cnt[k][0]));
							ans = add(ans, mul(cnt1, cnt[k][1]));

							if  (ans == ll(x)) {
//								printf("cnt0 = %d cnt1 = %d ch[c10] = %c ch[c11] = %c\n", cnt0, cnt1, ch[c10], ch[c11]);

								s1[0] = ch[c00];
								s1[n - 1] = ch[c01];

								int l = 0;
								int r = n - 1;

								if  (ch[c00] == 'A' && cnt0 > 0) {
									s1[1] = 'C';
									cnt0--;
									l = 2;
								} else {
									l = (ch[c00] == 'A') ? 0 : 1;
								}

								if  (ch[c01] == 'C' && cnt0 > 0) {
									s1[n - 2] = 'A';
									cnt0--;
									r = n - 3;
								} else {
									r = (ch[c01] == 'C') ? n - 1 : n - 2;	
								}

								for (int j = l; j + 1 <= r && cnt0 > 0; j += 2) {
									s1[j] = 'A';
									s1[j + 1] = 'C';
									cnt0--;
								}

								////////////////////
								s2[0] = ch[c10];
								s2[m - 1] = ch[c11];
								l = 0;
								r = m - 1;

								if  (ch[c10] == 'A' && cnt1 > 0) {
									s2[1] = 'C';
									cnt1--;
									l = 2;
								} else {
									l = (ch[c10] == 'A') ? 0 : 1;
								}

								if  (ch[c11] == 'C' && cnt1 > 0) {
									s2[m - 2] = 'A';
									cnt1--;
									r = m - 3;
								} else {
									r = (ch[c11] == 'C') ? m - 1 : m - 2;	
								}

								for (int j = l; j + 1 <= r && cnt1 > 0; j += 2) {
									s2[j] = 'A';
									s2[j + 1] = 'C';
									cnt1--;
								}

								puts(s1);
								puts(s2);

								exit(0);
							}
						}

	puts("Happy new year!");	
	return 0;
}