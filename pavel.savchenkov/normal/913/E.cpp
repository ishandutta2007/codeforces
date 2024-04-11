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
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

bool bit(int mask, int i) {
	return (mask >> i) & 1;
} 

int Mask;

bool read() {
	string s;
	if  (!getline(cin, s)) {
		return 0;
	}
	Mask = 0;
	forn(i, 8) {
		if  (s[i] == '1') {
			Mask ^= 1 << i;
		}
	}
	return 1;
}

const int MAXL = 80;

string dpE[1 << 8][MAXL];
string dpT[1 << 8][MAXL];
string dpF[1 << 8][MAXL];
bool ok_mask[1 << 8];

void remin(string& s, const string& t) {
	if  (s.empty()) {
		s = t;
		return;
	}
	assert(sz(s) == sz(t));
	if  (s > t) {
		s = t;
	}
}

void precalc() {
	const int full = (1 << 8) - 1;

	memset (ok_mask, 0, sizeof ok_mask);

	forn(l, MAXL) {
		forn(mask, 1 << 8) {
			dpE[mask][l].clear();
			dpF[mask][l].clear();
			dpT[mask][l].clear();

			// if  (l - 1 >= 0 && !dpE[mask][l - 1].empty() && !dpT[mask][l - 1].empty() && !dpF[mask][l - 1].empty()) {
			// 	dpE[mask][l] = dpE[mask][l - 1];
			// 	dpT[mask][l] = dpT[mask][l - 1];
			// 	dpF[mask][l] = dpF[mask][l - 1];
			// 	continue;
			// }

			// if  (mask == full) {
			// 	continue;
			// }

			eprintf("l = %d, mask = %d\n", l, mask);

			// 1
			{
				forn(mask1, 1 << 8) {
					forn(l1, l) {
						forn(mask2, 1 << 8) {
							const int l2 = l - l1 - 1;
							if  (l2 < 0) {
								continue;
							}
							if  ((mask1 | mask2) == mask) {
								if  (dpT[mask2][l2].empty() || dpE[mask1][l1].empty()) {
									continue;
								}
								assert(l1 + 1 + l2 == l);
								// eprintf("++++\n");
								remin(dpE[mask][l], dpE[mask1][l1] + "|" + dpT[mask2][l2]);
								remin(dpE[mask][l], dpT[mask2][l2] + "|" + dpE[mask1][l1]);
								// eprintf("----\n");
							}
							if  ((mask1 & mask2) == mask) {
								if  (dpF[mask2][l2].empty() || dpT[mask1][l1].empty()) {
									continue;
								}
								// eprintf("!!!!!!++++\n");
								assert(l1 + 1 + l2 == l);
								remin(dpT[mask][l], dpT[mask1][l1] + "&" + dpF[mask2][l2]);
								remin(dpT[mask][l], dpF[mask2][l2] + "&" + dpT[mask1][l1]);
								// eprintf("!!!!!!----\n");
							}
						}
					}
				}
			}

			// 2
			if  (l >= 2 && !dpE[mask][l - 2].empty()) {
				remin(dpF[mask][l], "(" + dpE[mask][l - 2] + ")");
			}	
			if  (l >= 1 && !dpF[~mask & full][l - 1].empty()) {
				remin(dpF[mask][l], "!" + dpF[~mask & full][l - 1]);
			}

			// eprintf("here +\n");
			const string vars = "zyx";
			forn(i, 3) {
				int only = 0;
				forn(j, 8) {
					if  (bit(j, i)) {
						only ^= 1 << j;
					}
				}

				if  (mask == only && l == 1) {
					remin(dpF[mask][l], string(1, vars[i]));
				}

				if  ((mask == (~only & full)) && l == 2) {
					remin(dpF[mask][l], "!" + string(1, vars[i]));
				}
			}
			// eprintf("here -\n");

			if  (!dpF[mask][l].empty()) {
				remin(dpT[mask][l], dpF[mask][l]);
			}
			if  (!dpT[mask][l].empty()) {
				remin(dpE[mask][l], dpT[mask][l]);
			}

			eprintf("dpE[mask = %d] = %s\n", mask, dpE[mask][l].data());
		}

		forn(mask, 1 << 8) {
			if  (!dpE[mask][l].empty()) {
				ok_mask[mask] = 1;
			}
		}

		bool ok = 1;
		forn(mask, 1 << 8) {
			if  (!ok_mask[mask]) {
				ok = 0;
				break;
			}
		}
		if  (ok) {
			break;
		}
	}

	forn(mask, 1 << 8) {
		string best;
		forn(l, MAXL) {
			if  (!dpE[mask][l].empty()) {
				best = dpE[mask][l];
				break;
			}
		}
		printf("ans[%d] = \"%s\";\n", mask, best.data());
	}

	exit(0);
}

void solve() {

}

string ans[300];

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	// precalc();

ans[0] = "!x&x";
ans[1] = "!(x|y|z)";
ans[2] = "!x&!y&z";
ans[3] = "!x&!y";
ans[4] = "!x&!z&y";
ans[5] = "!x&!z";
ans[6] = "!(!y&!z|x|y&z)";
ans[7] = "!(x|y&z)";
ans[8] = "!x&y&z";
ans[9] = "!(!y&z|!z&y|x)";
ans[10] = "!x&z";
ans[11] = "!(!z&y|x)";
ans[12] = "!x&y";
ans[13] = "!(!y&z|x)";
ans[14] = "!x&(y|z)";
ans[15] = "!x";
ans[16] = "!y&!z&x";
ans[17] = "!y&!z";
ans[18] = "!(!x&!z|x&z|y)";
ans[19] = "!(x&z|y)";
ans[20] = "!(!x&!y|x&y|z)";
ans[21] = "!(x&y|z)";
ans[22] = "!(!x&!y|x&y|z)|!x&!y&z";
ans[23] = "!((x|y)&z|x&y)";
ans[24] = "!x&y&z|!y&!z&x";
ans[25] = "!x&y&z|!y&!z";
ans[26] = "!x&z|!y&!z&x";
ans[27] = "!x&z|!y&!z";
ans[28] = "!x&y|!y&!z&x";
ans[29] = "!x&y|!y&!z";
ans[30] = "!x&(y|z)|!y&!z&x";
ans[31] = "!x|!y&!z";
ans[32] = "!y&x&z";
ans[33] = "!(!x&z|!z&x|y)";
ans[34] = "!y&z";
ans[35] = "!(!z&x|y)";
ans[36] = "!x&!z&y|!y&x&z";
ans[37] = "!x&!z|!y&x&z";
ans[38] = "!x&!z&y|!y&z";
ans[39] = "!x&!z|!y&z";
ans[40] = "!x&y&z|!y&x&z";
ans[41] = "!(!x&z|!z&x|y)|!x&y&z";
ans[42] = "!(x&y)&z";
ans[43] = "!(!z&x|y)|!x&z";
ans[44] = "!x&y|!y&x&z";
ans[45] = "!(!y&z|x)|!y&x&z";
ans[46] = "!x&y|!y&z";
ans[47] = "!x|!y&z";
ans[48] = "!y&x";
ans[49] = "!(!x&z|y)";
ans[50] = "!y&(x|z)";
ans[51] = "!y";
ans[52] = "!x&!z&y|!y&x";
ans[53] = "!x&!z|!y&x";
ans[54] = "!x&!z&y|!y&(x|z)";
ans[55] = "!x&!z|!y";
ans[56] = "!x&y&z|!y&x";
ans[57] = "!(!x&z|y)|!x&y&z";
ans[58] = "!x&z|!y&x";
ans[59] = "!x&z|!y";
ans[60] = "!x&y|!y&x";
ans[61] = "!(!x&!y&z|x&y)";
ans[62] = "!x&(y|z)|!y&x";
ans[63] = "!x|!y";
ans[64] = "!z&x&y";
ans[65] = "!(!x&y|!y&x|z)";
ans[66] = "!x&!y&z|!z&x&y";
ans[67] = "!x&!y|!z&x&y";
ans[68] = "!z&y";
ans[69] = "!(!y&x|z)";
ans[70] = "!x&!y&z|!z&y";
ans[71] = "!x&!y|!z&y";
ans[72] = "!x&y&z|!z&x&y";
ans[73] = "!(!x&y|!y&x|z)|!x&y&z";
ans[74] = "!x&z|!z&x&y";
ans[75] = "!(!z&y|x)|!z&x&y";
ans[76] = "!(x&z)&y";
ans[77] = "!(!y&x|z)|!x&y";
ans[78] = "!x&z|!z&y";
ans[79] = "!x|!z&y";
ans[80] = "!z&x";
ans[81] = "!(!x&y|z)";
ans[82] = "!x&!y&z|!z&x";
ans[83] = "!x&!y|!z&x";
ans[84] = "!z&(x|y)";
ans[85] = "!z";
ans[86] = "!x&!y&z|!z&(x|y)";
ans[87] = "!x&!y|!z";
ans[88] = "!x&y&z|!z&x";
ans[89] = "!(!x&y|z)|!x&y&z";
ans[90] = "!x&z|!z&x";
ans[91] = "!(!x&!z&y|x&z)";
ans[92] = "!x&y|!z&x";
ans[93] = "!x&y|!z";
ans[94] = "!x&(y|z)|!z&x";
ans[95] = "!x|!z";
ans[96] = "!y&x&z|!z&x&y";
ans[97] = "!(!x&y|!y&x|z)|!y&x&z";
ans[98] = "!y&z|!z&x&y";
ans[99] = "!(!z&x|y)|!z&x&y";
ans[100] = "!y&x&z|!z&y";
ans[101] = "!(!y&x|z)|!y&x&z";
ans[102] = "!y&z|!z&y";
ans[103] = "!(!y&!z&x|y&z)";
ans[104] = "!x&y&z|!y&x&z|!z&x&y";
ans[105] = "!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
ans[106] = "!(x&y)&z|!z&x&y";
ans[107] = "!(!z&x|y)|!x&z|!z&x&y";
ans[108] = "!(x&z)&y|!y&x&z";
ans[109] = "!(!y&x|z)|!x&y|!y&x&z";
ans[110] = "!(x&y)&z|!z&y";
ans[111] = "!x|!y&z|!z&y";
ans[112] = "!(y&z)&x";
ans[113] = "!(!x&y|z)|!y&x";
ans[114] = "!y&z|!z&x";
ans[115] = "!y|!z&x";
ans[116] = "!y&x|!z&y";
ans[117] = "!y&x|!z";
ans[118] = "!y&(x|z)|!z&y";
ans[119] = "!y|!z";
ans[120] = "!(y&z)&x|!x&y&z";
ans[121] = "!(!x&y|z)|!x&y&z|!y&x";
ans[122] = "!(x&y)&z|!z&x";
ans[123] = "!x&z|!y|!z&x";
ans[124] = "!(x&z)&y|!y&x";
ans[125] = "!x&y|!y&x|!z";
ans[126] = "!x&y|!y&z|!z&x";
ans[127] = "!(x&y&z)";
ans[128] = "x&y&z";
ans[129] = "!(x|y|z)|x&y&z";
ans[130] = "!x&!y&z|x&y&z";
ans[131] = "!x&!y|x&y&z";
ans[132] = "!x&!z&y|x&y&z";
ans[133] = "!x&!z|x&y&z";
ans[134] = "!(!y&!z|x|y&z)|x&y&z";
ans[135] = "!(x|y&z)|x&y&z";
ans[136] = "y&z";
ans[137] = "!(x|y|z)|y&z";
ans[138] = "!x&z|y&z";
ans[139] = "!x&!y|y&z";
ans[140] = "!x&y|y&z";
ans[141] = "!x&!z|y&z";
ans[142] = "!x&(y|z)|y&z";
ans[143] = "!x|y&z";
ans[144] = "!y&!z&x|x&y&z";
ans[145] = "!y&!z|x&y&z";
ans[146] = "!(!x&!z|x&z|y)|x&y&z";
ans[147] = "!(x&z|y)|x&y&z";
ans[148] = "!(!x&!y|x&y|z)|x&y&z";
ans[149] = "!(x&y|z)|x&y&z";
ans[150] = "!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
ans[151] = "!((x|y)&z|x&y)|x&y&z";
ans[152] = "!y&!z&x|y&z";
ans[153] = "!y&!z|y&z";
ans[154] = "!x&z|!y&!z&x|y&z";
ans[155] = "!(x&z|y)|y&z";
ans[156] = "!x&y|!y&!z&x|y&z";
ans[157] = "!(x&y|z)|y&z";
ans[158] = "!x&(y|z)|!y&!z&x|y&z";
ans[159] = "!x|!y&!z|y&z";
ans[160] = "x&z";
ans[161] = "!(x|y|z)|x&z";
ans[162] = "!y&z|x&z";
ans[163] = "!x&!y|x&z";
ans[164] = "!x&!z&y|x&z";
ans[165] = "!x&!z|x&z";
ans[166] = "!x&!z&y|!y&z|x&z";
ans[167] = "!(x|y&z)|x&z";
ans[168] = "(x|y)&z";
ans[169] = "!(x|y|z)|(x|y)&z";
ans[170] = "z";
ans[171] = "!x&!y|z";
ans[172] = "!x&y|x&z";
ans[173] = "!(!y&z|x)|x&z";
ans[174] = "!x&y|z";
ans[175] = "!x|z";
ans[176] = "!y&x|x&z";
ans[177] = "!y&!z|x&z";
ans[178] = "!y&(x|z)|x&z";
ans[179] = "!y|x&z";
ans[180] = "!x&!z&y|!y&x|x&z";
ans[181] = "!(x&y|z)|x&z";
ans[182] = "!x&!z&y|!y&(x|z)|x&z";
ans[183] = "!x&!z|!y|x&z";
ans[184] = "!y&x|y&z";
ans[185] = "!(!x&z|y)|y&z";
ans[186] = "!y&x|z";
ans[187] = "!y|z";
ans[188] = "!x&y|!y&x|x&z";
ans[189] = "!x&!z|!y&x|y&z";
ans[190] = "!x&y|!y&x|z";
ans[191] = "!x|!y|z";
ans[192] = "x&y";
ans[193] = "!(x|y|z)|x&y";
ans[194] = "!x&!y&z|x&y";
ans[195] = "!x&!y|x&y";
ans[196] = "!z&y|x&y";
ans[197] = "!x&!z|x&y";
ans[198] = "!x&!y&z|!z&y|x&y";
ans[199] = "!(x|y&z)|x&y";
ans[200] = "(x|z)&y";
ans[201] = "!(x|y|z)|(x|z)&y";
ans[202] = "!x&z|x&y";
ans[203] = "!(!z&y|x)|x&y";
ans[204] = "y";
ans[205] = "!x&!z|y";
ans[206] = "!x&z|y";
ans[207] = "!x|y";
ans[208] = "!z&x|x&y";
ans[209] = "!y&!z|x&y";
ans[210] = "!x&!y&z|!z&x|x&y";
ans[211] = "!(x&z|y)|x&y";
ans[212] = "!z&(x|y)|x&y";
ans[213] = "!z|x&y";
ans[214] = "!x&!y&z|!z&(x|y)|x&y";
ans[215] = "!x&!y|!z|x&y";
ans[216] = "!z&x|y&z";
ans[217] = "!(!x&y|z)|y&z";
ans[218] = "!x&z|!z&x|x&y";
ans[219] = "!x&!y|!z&x|y&z";
ans[220] = "!z&x|y";
ans[221] = "!z|y";
ans[222] = "!x&z|!z&x|y";
ans[223] = "!x|!z|y";
ans[224] = "(y|z)&x";
ans[225] = "!(x|y|z)|(y|z)&x";
ans[226] = "!y&z|x&y";
ans[227] = "!(!z&x|y)|x&y";
ans[228] = "!z&y|x&z";
ans[229] = "!(!y&x|z)|x&z";
ans[230] = "!y&z|!z&y|x&y";
ans[231] = "!x&!y|!z&y|x&z";
ans[232] = "(x|y)&z|x&y";
ans[233] = "!(x|y|z)|(x|y)&z|x&y";
ans[234] = "x&y|z";
ans[235] = "!x&!y|x&y|z";
ans[236] = "x&z|y";
ans[237] = "!x&!z|x&z|y";
ans[238] = "y|z";
ans[239] = "!x|y|z";
ans[240] = "x";
ans[241] = "!y&!z|x";
ans[242] = "!y&z|x";
ans[243] = "!y|x";
ans[244] = "!z&y|x";
ans[245] = "!z|x";
ans[246] = "!y&z|!z&y|x";
ans[247] = "!y|!z|x";
ans[248] = "x|y&z";
ans[249] = "!y&!z|x|y&z";
ans[250] = "x|z";
ans[251] = "!y|x|z";
ans[252] = "x|y";
ans[253] = "!z|x|y";
ans[254] = "x|y|z";
ans[255] = "!x|x";

	int T;
	scanf("%d\n", &T);
	forn(t, T) {
		assert(read());
		// eprintf("Mask = %d\n", Mask);
		printf("%s\n", ans[Mask].data());
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}