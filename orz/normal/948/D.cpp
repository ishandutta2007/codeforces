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

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define ld long double
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

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/


/** -----GLOBAL VARIABLES----- **/
i64 N; vi A; multiset<i64> P;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N; A.resize(N);
	for (i64 i=0; i<N; i++) cin >> A[i];
	for (i64 i=0; i<N; i++) {
		i64 x; cin >> x; P.insert(x);
	}
}

void ProSolve() {
	for (i64 i=0; i<N; i++) {
		i64 optimal = 0;
		for (i64 j=29; j>=0; j--) {
			//cout << "bitOn = " << (i & (1LL << j)) << endl;
			if ((A[i] & (1LL << j)) == 0) {
				auto ite1 = P.lower_bound(optimal), ite2 = P.lower_bound(optimal+(1LL << j));
				if (ite1 == ite2) optimal += (1LL << j);
			}
			else {
				auto ite1 = P.lower_bound(optimal+(1LL << j)), ite2 = P.lower_bound(optimal+(1LL << j)+(1LL << j));
				if (ite1 != ite2) optimal += (1LL << j);
			}
			//cout << "working at j = " << j << ": optimal = " << optimal << endl;
		}
		//cout << "optimal = " << optimal << endl;
		P.erase(P.find(optimal));
		cout << (A[i] ^ optimal) << " ";
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
			cout << "\n\nTime elapsed: " << fixed << setprecision(18) << chrono::duration<double>(DIFF).count() << " seconds.";
			#endif
	return 0;
}