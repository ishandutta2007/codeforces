/**
	Template by Akikaze () - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
	
	HG x Mili - November 27th, 2013
	Mag Mell (Mili) - Sep 17th, 2014
	HG x Mili Vol.2 - May 9th, 2015
	Miracle Milk (Mili) - Oct 12th, 2016
	 (HG) - February 14th, 2018
	Millennium Mother (Mili) - April 25th, 2018
**/

/** -----PRAGMA----- **/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define ld long double
#define rsz resize
#define pub push_back
#define mp make_pair
#define fi first
#define se second
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
vi HashMod = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/


/** -----GLOBAL VARIABLES----- **/
i64 n, m, k;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m >> k; k++;
}

void ProSolve() {
	if (k <= n) cout << k << " 1";
	else if (k <= n + m - 1) cout << n << " " << k - n + 1;
	else {
		k -= (n + m - 1);
		i64 wholeLine = k / (m - 1);
		i64 leftover = k % (m - 1);
		i64 x = n - wholeLine - (leftover != 0), y = 0;
		if (leftover == 0) {
			if (wholeLine % 2 == 0) y = m; else y = 2;
		}
		else {
			if (wholeLine % 2 == 0) y = m - (leftover - 1);
			else y = 2 + (leftover - 1);
		}
		cout << x << " " << y;
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
			#ifdef Akikaze
			//freopen("FILE.INP", "r", stdin);
			//freopen("FILE.OUT", "w", stdout);
			#endif
	VarInput();
			#ifdef Akikaze
			auto TIME1 = chrono::steady_clock::now();
			#endif
	ProSolve();
			#ifdef Akikaze
			auto TIME2 = chrono::steady_clock::now();
			auto DIFF = TIME2 - TIME1;
			cout << "\n\nTime elapsed: " << chrono::duration<double>(DIFF).count() << " seconds.";
			#endif
	return 0;
}