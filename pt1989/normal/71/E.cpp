//      hello world


//DS includes
#include<bitset>
#include<complex>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

//Other Includes
#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<sstream>

#define oo 			0xBADC0DE
#define s(n)			scanf("%d",&n)
#define sl(n) 			scanf("%lld",&n)
#define sf(n) 			scanf("%lf",&n)
#define fill(a,v) 		memset(a, v, sizeof a)
#define ull 			unsigned long long
#define ll 				long long
#define bitcount 		__builtin_popcount
#define all(x) 			x.begin(), x.end()
#define pb( z ) 		push_back( z )
#define gcd				__gcd

#define FOR(i,n) for (int i=0; i < (n); i++)

using namespace std;
map<string, int> id;

void prec() {
	//auto generated code
	id["H"] = 1;
	id["He"] = 2;
	id["Li"] = 3;
	id["Be"] = 4;
	id["B"] = 5;
	id["C"] = 6;
	id["N"] = 7;
	id["O"] = 8;
	id["F"] = 9;
	id["Ne"] = 10;
	id["Na"] = 11;
	id["Mg"] = 12;
	id["Al"] = 13;
	id["Si"] = 14;
	id["P"] = 15;
	id["S"] = 16;
	id["Cl"] = 17;
	id["Ar"] = 18;
	id["K"] = 19;
	id["Ca"] = 20;
	id["Sc"] = 21;
	id["Ti"] = 22;
	id["V"] = 23;
	id["Cr"] = 24;
	id["Mn"] = 25;
	id["Fe"] = 26;
	id["Co"] = 27;
	id["Ni"] = 28;
	id["Cu"] = 29;
	id["Zn"] = 30;
	id["Ga"] = 31;
	id["Ge"] = 32;
	id["As"] = 33;
	id["Se"] = 34;
	id["Br"] = 35;
	id["Kr"] = 36;
	id["Rb"] = 37;
	id["Sr"] = 38;
	id["Y"] = 39;
	id["Zr"] = 40;
	id["Nb"] = 41;
	id["Mo"] = 42;
	id["Tc"] = 43;
	id["Ru"] = 44;
	id["Rh"] = 45;
	id["Pd"] = 46;
	id["Ag"] = 47;
	id["Cd"] = 48;
	id["In"] = 49;
	id["Sn"] = 50;
	id["Sb"] = 51;
	id["Te"] = 52;
	id["I"] = 53;
	id["Xe"] = 54;
	id["Cs"] = 55;
	id["Ba"] = 56;
	id["La"] = 57;
	id["Ce"] = 58;
	id["Pr"] = 59;
	id["Nd"] = 60;
	id["Pm"] = 61;
	id["Sm"] = 62;
	id["Eu"] = 63;
	id["Gd"] = 64;
	id["Tb"] = 65;
	id["Dy"] = 66;
	id["Ho"] = 67;
	id["Er"] = 68;
	id["Tm"] = 69;
	id["Yb"] = 70;
	id["Lu"] = 71;
	id["Hf"] = 72;
	id["Ta"] = 73;
	id["W"] = 74;
	id["Re"] = 75;
	id["Os"] = 76;
	id["Ir"] = 77;
	id["Pt"] = 78;
	id["Au"] = 79;
	id["Hg"] = 80;
	id["Tl"] = 81;
	id["Pb"] = 82;
	id["Bi"] = 83;
	id["Po"] = 84;
	id["At"] = 85;
	id["Rn"] = 86;
	id["Fr"] = 87;
	id["Ra"] = 88;
	id["Ac"] = 89;
	id["Th"] = 90;
	id["Pa"] = 91;
	id["U"] = 92;
	id["Np"] = 93;
	id["Pu"] = 94;
	id["Am"] = 95;
	id["Cm"] = 96;
	id["Bk"] = 97;
	id["Cf"] = 98;
	id["Es"] = 99;
	id["Fm"] = 100;
	id["Md"] = 101;
	id["No"] = 102;
	id["Lr"] = 103;
	id["Rf"] = 104;
	id["Db"] = 105;
	id["Sg"] = 106;
	id["Bh"] = 107;
	id["Hs"] = 108;
	id["Mt"] = 109;
	id["Ds"] = 110;
	id["Rg"] = 111;
	id["Cn"] = 112;
	id["Uut"] = 113;
	id["Uuq"] = 114;
	id["Uup"] = 115;
	id["Uuh"] = 116;
	id["Uus"] = 117;
	id["Uuo"] = 118;
}


string from[17], to[17];
int sum[1<<17], fval[17], tval[17];
int n, m;
int dp[17][1<<17];
int solve(int tw, int mask) {
	int rem = mask ^ ( (1<<n) - 1 );
	if (rem == 0 || tw == m) {
		return rem==0 && tw==m;
	}
	
	
	int &ret = dp[tw][mask];
	if (~ret)
		return ret;
	ret = 0;
	
	for (int sub=rem; ret == 0 && sub > 0; sub = (sub-1)&rem) {
		if (sum[sub] == tval[tw]) {
			ret |= solve(tw+1, mask | sub);
		}
	}
	return ret;
}


void recon(int tw, int mask) {
	int rem = mask ^ ( (1<<n) - 1 );
	if (rem == 0 || tw == m) {
		return;
	}
	for (int sub=rem; sub > 0; sub = (sub-1)&rem) {
		if (sum[sub] == tval[tw]) {
			if (solve(tw+1, mask | sub)) {
				vector<string> sol;
				for (int x=0; x < n; x++)
				if (sub & 1 << x) {
					sol.pb( from[x] );
				}
				sol.pb( to[tw] );
				for (int x=0; x < (int)sol.size(); x++) {
					if (x > 0) {
						if (x + 1 == (int)sol.size()) {
							cout << "->";
						} else {
							cout << "+";
						}
					}
					cout << sol[x];
				}
				cout << endl;
				return recon(tw+1, mask | sub);
			}
		}
	}
}

int main(int argc, char** argv) {
	prec();
	cin>>n>>m;
	for (int i=0; i < n; i++) {
		cin>>from[i];
		assert( id.count( from[i] ) );
		fval[i] = id[ from[i] ];
	}
	for (int j=0; j < m; j++) {
		cin>>to[j];
		assert( id.count( to[j] ) );
		tval[j] = id[ to[j] ];
	}
	
	//precomputation part
	for (int i=0; i < (1<<n); i++) {
		sum[i] = 0;
		for (int j=0; j < n; j++)
		if (i & 1 << j) {
			sum[i] += fval[ j ];
		}
	}
	fill(dp, -1);
	
	
	if (solve(0,0)) {
		cout << "YES" <<endl;
		recon(0,0);
	} else {
		cout << "NO" << endl;
	}
	
	

	return 0;
}