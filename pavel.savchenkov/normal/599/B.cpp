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
const int MAXN = 1e5 + 10;

int f[MAXN];
int pos_f[MAXN];
bool amb_pos_f[MAXN];
int b[MAXN];
int n, m;
int a[MAXN];

int main() {
//	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);

	memset (pos_f, -1, sizeof pos_f);
	cin >> n >> m;
	forn(i, n) {
		scanf("%d", &f[i]);
		if  (pos_f[f[i]] != -1) {
			amb_pos_f[f[i]] = true;
		}
		pos_f[f[i]] = i;
	}  

bool amb = false;
	forn(i, m) {
		scanf("%d", &b[i]);
		if  (pos_f[b[i]] == -1) {
			puts("Impossible");
			return 0;
		}
		a[i] = pos_f[b[i]];
		if  (amb_pos_f[b[i]]) {
amb = true;			
			
		}
	}

if  (amb) { puts("Ambiguity"); return 0; } 
	puts("Possible");
	forn(i, m) {
		printf("%d%c", a[i] + 1, " \n"[i == n - 1]);
	}

	return 0;
}