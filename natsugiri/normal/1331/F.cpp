#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

const string E[] = {
"H",
"HE",
"LI",
"BE",
"B",
"C",
"N",
"O",
"F",
"NE",
"NA",
"MG",
"AL",
"SI",
"P",
"S",
"CL",
"AR",
"K",
"CA",
"SC",
"TI",
"V",
"CR",
"MN",
"FE",
"CO",
"NI",
"CU",
"ZN",
"GA",
"GE",
"AS",
"SE",
"BR",
"KR",
"RB",
"SR",
"Y",
"ZR",
"NB",
"MO",
"TC",
"RU",
"RH",
"PD",
"AG",
"CD",
"IN",
"SN",
"SB",
"TE",
"I",
"XE",
"CS",
"BA",
"LA",
"CE",
"PR",
"ND",
"PM",
"SM",
"EU",
"GD",
"TB",
"DY",
"HO",
"ER",
"TM",
"YB",
"LU",
"HF",
"TA",
"W",
"RE",
"OS",
"IR",
"PT",
"AU",
"HG",
"TL",
"PB",
"BI",
"PO",
"AT",
"RN",
"FR",
"RA",
"AC",
"TH",
"PA",
"U",
"NP",
"PU",
"AM",
"CM",
"BK",
"CF",
"ES",
"FM",
"MD",
"NO",
"LR",
"RF",
"DB",
"SG",
"BH",
"HS",
"MT",
"DS",
"RG",
"CN",
"NH",
"FL",
"MC",
"LV",
"TS",
"OG",
};

const int SIZE = 118;

char S[111];
int N;
bool rec(int I) {
    if (I == N) return true;
    REP (i, SIZE) {
	if (E[i].compare(0, E[i].size(), S, I, E[i].size()) == 0 && rec(I + E[i].size())) {
	    return true;
	}
    }
    return false;
}

void MAIN() {
    //eprintf("%d\n", (int)((sizeof E) / (sizeof (string))));
    scanf("%s", S);
    N = strlen(S);
    bool yes = rec(0);
    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}