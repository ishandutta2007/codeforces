#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
typedef unsigned long long ULL;

typedef pair<ULL, ULL> Hash;
namespace std {
    template<> struct hash<Hash> {
	ULL operator()(const Hash &h) const {
	    return h.first << 32 | h.second;
	}
    };
};
struct RollingHash2 {
    static const ULL MOD0 = 1e9+7; // 2e9 + 11; 3e9+19; 4e9+7;
    static const ULL MOD1 = 1e9+9;
    static const ULL BASE = 1007;
    static const int MAX_LEN = 1e6 + 11;
    static const vector<ULL> pow0, pow1;
    static const vector<ULL> build(ULL);

//    vector<int> S;
    vector<ULL> H0, H1; // H[i] := hash(S[0 .. i])
    RollingHash2() {}
//    RollingHash2(const string &str) {
//	init(str);
//    }
    void init(const VI &v) {
	int n = v.size();
//	S.assign(n, 0);
	H0.assign(n+1, 0); H1.assign(n+1, 0);
	for (int i=0; i<n; i++) {
//	    S[i] = v[i];
	    H0[i+1] = (H0[i] * BASE+ v[i]) % MOD0;
	    H1[i+1] = (H1[i] * BASE + v[i]) % MOD1;
	}
    }
//    void init(const string &str) {
//	int n = str.size();
//	S.assign(n, 0); H0.assign(n+1, 0); H1.assign(n+1, 0);
//	for (int i=0; i<n; i++) {
//	    S[i] = str[i];
//	    H0[i+1] = (H0[i] * BASE+ str[i]) % MOD0;
//	    H1[i+1] = (H1[i] * BASE + str[i]) % MOD1;
//	}
//    }
    Hash get(int l, int r) { // hash(S[l .. r-1])
	Hash ret;
	ULL a;
	a = H0[l] * pow0[r-l] % MOD0;
	ret.first = H0[r] + (H0[r] < a ? MOD0 : 0) - a;
	a = H1[l] * pow1[r-l] % MOD1;
	ret.second = H1[r] + (H1[r] < a ? MOD1 : 0) - a;
	return ret;
    }
//    void push(char c) {
//	S.push_back(c);
//	H0.push_back((H0.back() * BASE + c) % MOD0);
//	H1.push_back((H1.back() * BASE + c) % MOD1);
//    }
//    void pop() {
//	S.pop_back();
//	H0.pop_back();
//	H1.pop_back();
//    }

    static Hash concat(const Hash &x, const Hash &y, int len) { // len: y's len
	return Hash((x.first * powMod(BASE, len, MOD0) + y.first) % MOD0,
		(x.second * powMod(BASE, len, MOD1) + y.second) % MOD1);
    }

    static Hash repeat(Hash x, LL len, LL y) {
	Hash r(0, 0);
	for (; y; y>>=1) {
	    if (y & 1) r = concat(r, x, len);
	    x = concat(x, x, len);
	    len *= 2;
	}
	return r;
    }

    static ULL powMod(ULL x, ULL y, ULL m) {
	ULL r = 1;
	for (; y; y>>=1) {
	    if (y & 1) r = r * x % m;
	    x = x * x % m;
	}
	return r;
    }
};
const vector<ULL> RollingHash2::build(ULL MOD) {
    vector<ULL>h(MAX_LEN);
    h[0] = 1;
    for (int i=1; i<MAX_LEN; i++) h[i] = h[i-1] * BASE % MOD;
    return h;
}
const vector<ULL>RollingHash2::pow0 = RollingHash2::build(RollingHash2::MOD0);
const vector<ULL>RollingHash2::pow1 = RollingHash2::build(RollingHash2::MOD1);

int N, M;
char S[200011];
int nxt[200011][26];

int xpos[26], ypos[26];

VI P[26];
int pos[200011][26];
RollingHash2 RH[26];

void MAIN() {
    scanf("%d%d", &N, &M);
    scanf("%s", S);

    REP (c, 26) P[c].push_back(0);
    REP (i, N) {
	REP (c, 26) pos[i][c] = P[c].size();
	P[S[i]-'a'].push_back(i);
    }
    REP(c, 26) pos[N][c] = P[c].size();
    // diff
    REP (c, 26) {
	for (int i=P[c].size(); --i;) {
	    P[c][i] -= P[c][i-1];
	}
	RH[c].init(P[c]);
    }

    REP (c, 26) nxt[N][c] = N;
    for (int i=N; i--;) {
	REP (c, 26) nxt[i][c] = nxt[i+1][c];
	nxt[i][S[i]-'a'] = i;
    }

    REP ($, M) {
	int x, y, len;
	scanf("%d%d%d", &x, &y, &len);
	x--; y--;

	REP (c, 26) {
	    xpos[c] = min(x + len, nxt[x][c]);
	    ypos[c] = min(y + len, nxt[y][c]);
	}

//	cerr << string(S+x, S+x+len) << endl;
//	cerr << string(S+y, S+y+len) << endl;
//	rprintf("%d", xpos, xpos+26);
//	rprintf("%d", ypos, ypos+26);
//	cerr <<  endl;

	sort(xpos, xpos+26);
	sort(ypos, ypos+26);

	bool yes = true;
	if (yes) REP (c, 26) {
	    if (xpos[c]-x != ypos[c]-y) {
		yes = false;
		break;
	    }
	}
	if (yes) {
	    REP (c, 26) if (xpos[c] < x+len) {
		int xchar = S[xpos[c]] - 'a';
		int ychar = S[ypos[c]] - 'a';

		int x_left = pos[x][xchar]+1;
		int x_right = pos[x+len][xchar];
		int y_left = pos[y][ychar]+1;
		int y_right = pos[y+len][ychar];

		if (x_right - x_left != y_right - y_left) {
		    yes = false;
		    break;
		}
		if (RH[xchar].get(x_left, x_right) != RH[ychar].get(y_left, y_right)) {
		    yes = false;
		    break;
		}
	    }
	}

	puts(yes? "YES": "NO");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}