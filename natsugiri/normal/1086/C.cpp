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

char buf[1000111];

int N, K;
string S, A, B, T;

char fix[33];
bool use[33];

void fill_all(int I) {
    for (int i=I; i<N; i++) {
	if (!fix[S[i]-'a']) {
	    REP (k, K) if (!use[k]) {
		use[k] = true;
		fix[S[i]-'a'] = k+'a';
		break;
	    }
	}
	T[i] = fix[S[i]-'a'];
    }

    REP (k, K) if (!fix[k]) {
	REP (t, K) if (!use[t]) {
	    fix[k] = t + 'a';
	    use[t] = true;
	    break;
	}
    }
}

bool rec(int I) {
    if (I == N) {
	return true;
    } else {
	for (int i=I; i<N; i++) {
	    char c = fix[S[i]-'a'];
	    if (c) {
		if (A[i] <= c) {
		    T[i] = c;
		    if (A[i] < c) {
			fill_all(i+1);
			return true;
		    }
		} else {
		    return false;
		}
	    } else {
		for (int k=A[i]-'a'; k<K; k++) {
		    if (!use[k]) {
			use[k] = true;
			T[i] = fix[S[i]-'a'] = k + 'a';
			if (A[i] < T[i]) {
			    fill_all(i+1);
			    return true;
			}
			if (rec(i+1)) {
			    return true;
			}
			use[k] = false;
			fix[S[i]-'a'] = 0;
		    }
		}

		return false;
	    }
	}

	return true;
    }
}

void MAIN() {
    scanf("%d", &K);
    scanf("%s", buf);
    S = buf;
    scanf("%s", buf);
    A = buf;
    scanf("%s", buf);
    B = buf;

//#ifdef LOCAL
//    K = 26;
//    S = string(1000000, 'a');
//    A = string(1000000, 'a');
//    B = string(1000000, 'a');
//#endif

    N = S.size();
    T = string(N, '.');


    memset(fix, 0, sizeof fix);
    memset(use, 0, sizeof use);
    bool b = rec(0);

//    cerr << b << " " << T << endl;

    if (b && A <= T && T <= B) {
	fill_all(N);
	puts("YES");
	puts(fix);
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}