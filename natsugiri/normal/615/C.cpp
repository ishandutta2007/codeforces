#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }


char S[6666], T[2222];
int Sn, Tn, Snn;

int ansC, ansA[2222], ansB[2222];
int sa[6666];

struct CMP {
    bool operator()(int x, int y) const {
	if (x == y) return false;
	while (true) {
	    if (S[x] != S[y]) return S[x] < S[y];
	    x++; y++;
	}
    }
} cmp;

char S_get(int i) {
    if (i < Snn) return S[i];
    return 0;
}

int main() {
    scanf("%s%s", S, T);
    Sn = strlen(S);
    Tn = strlen(T);

    S[Sn] = '#';
    Snn = 2*Sn+1;
    REP (i, Sn) S[Sn+1+i] = S[Sn-1-i];
    REP (i, Snn) sa[i] = i;
    sort(sa, sa+Snn, cmp);

    // REP (i, Snn) eprintf("%2d %s\n", sa[i], S + sa[i]);

    int cur = 0;
    while (cur < Tn) {
	int plo = 0;
	int lo = 0, hi = Snn-1;
	int i;
	for (i=0; T[cur+i]; i++) {
	    while (lo < Snn && S_get(sa[lo]+i) < T[cur+i]) lo++;
	    while (hi >= 0 && S_get(sa[hi]+i) > T[cur+i]) hi--;
	    
	    if (hi < lo ||
		lo >= Snn || S_get(sa[lo]+i) != T[cur+i] ||
		hi < 0 || S_get(sa[hi]+i) != T[cur+i]) {
		break;
	    }
	    plo = lo;
	}
	
	if (i == 0) {
	    puts("-1");
	    return 0;
	} else {
	    int g = sa[plo];
	    if (g < Sn) {
		ansA[ansC] = g + 1;
		ansB[ansC] = g + i;
		ansC++;
	    } else {
		ansA[ansC] = 2*Sn - g + 1;
		ansB[ansC] = ansA[ansC] - i + 1;
		ansC++;
	    }
	    cur += i;
	}
    }

    printf("%d\n", ansC);
    REP (i, ansC) {
	printf("%d %d\n", ansA[i], ansB[i]);
    }
    
    
    return 0;
}