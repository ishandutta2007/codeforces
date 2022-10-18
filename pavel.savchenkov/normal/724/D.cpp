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
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const int MAXN = 1e5 + 10;

int n, m;
char s[MAXN];

bool read() {
	if  (scanf("%d\n", &m) < 1) {
		return false;
	}
	scanf("%s", s);
	n = strlen(s);
	return true;
}

int nxt[MAXN];

string solve() {
	for (char last = 'a'; last <= 'z'; ++last) {
		bool ok = true;
		int prev = -1;
		forn(i, n + 1) {
			if  (i == n || s[i] <= last) {
				if  (i - prev > m) {
					ok = false;
					break;
				}
				prev = i;
			}
		}
		if  (!ok) {
			continue;
		}
		// printf("last=%c\n", last);
		nxt[n - 1] = nxt[n] = n;
		ford(i, n - 1) {
			nxt[i] = nxt[i + 1];
			if  (s[i + 1] <= last) {
				nxt[i] = i + 1;
			} 
		}
		int cnt_last = 0;
		prev = -1;
		forn(i, n) {
			if  (s[i] < last) {
				assert(i - prev <= m);
				prev = i;
			} else if  (s[i] == last) {
				if  (nxt[i] - prev > m) {
					++cnt_last;
					prev = i;
				}
			}
		}

		string ans;
		forn(i, n) {
			if  (s[i] < last) {
				ans += s[i];
			}
		}
		sort(all(ans));
		ans += string(cnt_last, last);
		return ans;
	}
	assert(false);
	return "";
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		puts(solve().c_str());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}