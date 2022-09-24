#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
char buf[200011];

string ans;
bool solve(const string &A, const string &B) {

    char x = '0', y = '1';
    REP (t, 2) {
	if (count(A.begin(), A.end(), x) >= N && count(B.begin(), B.end(), x) >= N) {
	    string tmp;
	    int i = 0, j = 0;
	    while (i < (int)A.size() || j < (int)B.size()) {
		char z;
		if (i < (int)A.size() && A[i] == y) z = y;
		else if (j < (int)B.size() && B[j] == y) z = y;
		else z = x;

		if (i < (int)A.size() && A[i] == z) i++;
		if (j < (int)B.size() && B[j] == z) j++;
		tmp.push_back(z);
	    }

	    while ((int)tmp.size() < 3*N) tmp.push_back('0');
	    ans = tmp;
	    return true;
	}

	swap(x, y);
    }

    return false;
}


string A, B, C;


void MAIN() {
    scanf("%d", &N);
    scanf("%s", buf);
    A = buf;
    scanf("%s", buf);
    B = buf;
    scanf("%s", buf);
    C = buf;

#ifdef LOCALx
    N = 6;
    A = B = C = string(N*2, '0');
    REP (i, N*2) {
	A[i] = rand() % 2 + '0';
	B[i] = rand() % 2 + '0';
	C[i] = rand() % 2 + '0';
    }
#endif

    ans.clear();

    bool b =
	solve(A, B)
	|| solve(A, C)
	|| solve(B, A)
	|| solve(B, C)
	|| solve(C, A)
	|| solve(C, B);

    puts(ans.c_str());
    assert(b);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}