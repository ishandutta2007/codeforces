
#include<stack>
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


int calc(const char* const buf) {
    int a[3] = {
	buf[0] - 'A',
	buf[1] - 'A',
	buf[2] - 'A',
    };
    return (a[0] * 26 + a[1]) * 26 + a[2];
}

int N;
char buf[111], bufx[111];
int A[1111], B[1111];
int sel[1111];

int main() {
    scanf("%d", &N);

    REP (i, N) {
	scanf("%s%s", buf, bufx);
	int a = calc(buf);
	buf[2] = bufx[0];
	int b = calc(buf);

	A[i] = a;
	B[i] = b;
    }

    REP (i, N) REP (j, N) if (i!=j) {
	if (A[i] == A[j]) {
	    sel[i] = sel[j] = 1;
	}
    }

    stack<int> st;
    REP (i, N) st.push(i);
    while (!st.empty()) {
	int x = st.top(); st.pop();
	REP (i, N) if (x != i) {
	    int a = sel[i] ? B[i] : A[i];
	    int b = sel[x] ? B[x] : A[x];
	    if (a == b) {
		if (sel[i] == 0) {
		    sel[i] = 1;
		    st.push(i);
		}
		if (sel[x] == 0) {
		    sel[x] = 1;
		    st.push(x);
		    break;
		}
	    }
	}
    }

    bool yes = true;
    REP (i, N) REP (j, N) if (i!=j) {
	int a = sel[i] ? B[i] : A[i];
	int b = sel[j] ? B[j] : A[j];
	if (a == b) { yes = false; break; }
    }

    if (yes) {
	puts("YES");
	REP (i, N) {
	    int a = sel[i] ? B[i] : A[i];
	    buf[3] = 0;
	    buf[2] = a % 26 + 'A'; a /= 26;
	    buf[1] = a % 26 + 'A'; a /= 26;
	    buf[0] = a % 26 + 'A'; a /= 26;
	    puts(buf);
	}
    } else {
	puts("NO");
    }
    return 0;
}