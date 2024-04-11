#include<assert.h>
#include<map>
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

#define left TWILIGHT_SKY
#define right SPARKLING_GIRL

int N, M;
char buf[11111];
int A[5111];
string MY[5111], L[5111], OP[5111], R[5111];
char var[1111], left[1111], op[1111], right[1111];

map<string, int> mp;
char ans_min[1111], ans_max[1111];

int get(const string &ex, int digit, int def) {
    if (ex[0] == '?') return def;
    if (isdigit(ex[0])) return ex[digit] - '0';
    if (isalpha(ex[0])) return A[mp[ex]];
    assert(false);
}

int main() {
    scanf("%d%d ", &N, &M);
    REP (i, N) {
	scanf("%[^\r\n] ", buf);
	int c = sscanf(buf, "%s := %s %s %s", var, left, op, right);

	MY[i] = var;
	mp.insert(make_pair(MY[i], i));
	L[i] = left;
	if (c == 4) {
	    OP[i] = op;
	    R[i] = right;
	}
    }

    REP (m, M) {
	int cnt[2] = {};
	REP (t, 2) {
	    REP (i, N) {
		int l, r;
		l = get(L[i], m, t);
		if (!OP[i].empty()) {
		    r = get(R[i], m, t);
		    if (OP[i][0] == 'A') l &= r;
		    if (OP[i][0] == 'O') l |= r;
		    if (OP[i][0] == 'X') l ^= r;
		}

		A[i] = l;
	    }

	    cnt[t] =  count(A, A+N, 1);
	}

	if (cnt[0] <= cnt[1]) {
	    ans_min[m] = '0';
	} else {
	    ans_min[m] = '1';
	}

	if (cnt[0] >= cnt[1]) {
	    ans_max[m] = '0';
	} else {
	    ans_max[m] = '1';
	}
    }
    puts(ans_min);
    puts(ans_max);

    return 0;
}