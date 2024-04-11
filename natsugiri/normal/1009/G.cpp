#include<queue>
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

char S[100011];
int C[6];
int N, M;

int Mask[100011];
int Masks[1<<6];

int has[1<<6], up[1<<6];
bool valid() {
    memset(has, 0, sizeof has);

    REP (s, 1<<6) {
	REP (c, 6) if (s>>c&1) has[s] += C[c];
	up[s] = Masks[s];
    }
    REP (c, 6) REP (s, 1<<6) if (~s>>c&1) up[s|(1<<c)] += up[s];
    
//    rprintf("%d", has, has+(1<<6));
    REP (s, 1<<6) if(has[s] < up[s]) return false;
    return true;
}

void MAIN() {
    scanf("%s%d", S, &M);
    N = strlen(S);
    REP (i, N) C[S[i]-'a']++;

    REP (i, N) Mask[i] = -1;

    REP (i, M) {
	int pos;
	static char op[11];
	scanf("%d%s", &pos, op);
	pos--;
	int mask = 0;
	for (int j=0; op[j]; j++) 
	    mask |= 1<<(op[j]-'a');

	Mask[pos] = mask;
	Masks[mask]++;
    }

    REP (i, N) {
	REP (c, 7) {
	    if (c == 6) {
		puts("Impossible");
		return;
	    }
	    if (C[c] == 0) continue;
	    if (~Mask[i]>>c&1) continue;

	    C[c]--;
	    if (Mask[i] != -1) Masks[Mask[i]]--;

	    if (valid()) {
		S[i] = c+'a';
		break;
	    }

	    if (Mask[i] != -1) Masks[Mask[i]]++;
	    C[c]++;
	}
    }
    puts(S);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}