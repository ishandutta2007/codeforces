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

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const ld EPS = 1e-9;
const int MAXN = 1e6 + 10;

int type(char c) {
	if  (c == '{' || c == '}') return 0;
	if  (c == '[' || c == ']') return 1;
	if  (c == '<' || c == '>') return 2;
	return 3;
}

bool is_open(char c) {
	return c == '{' || c == '[' || c == '<' || c == '(';
}

#define pair pair_________________

char s[MAXN];
int pair[MAXN];
int n;

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif

	gets(s);
	n = strlen(s);

	memset (pair, -1, sizeof pair);
	vi st;
	forn(i, n) {
		char c = s[i];
		if (!st.empty()) {
			if  (is_open(s[st.back()]) && !is_open(c)) {
				pair[st.back()] = i;
				st.pop_back();
			} else {
				st.pb(i);
			}
		} else {
			st.pb(i);
		}
	}	

	if  (!st.empty()) {
		puts("Impossible");
		return 0;
	}

	int ans = 0;
	forn(i, n) {
		if  (pair[i] != -1) {
			ans += (type(s[i]) != type(s[pair[i]]));
		}
	}
	printf("%d\n", ans);
	return 0;
}