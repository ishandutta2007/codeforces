
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

int N;
int A[100111], end;

int main() {
    scanf("%d", &N);
    REP (i, N) {
	A[end++] = 1;
	while (end > 1 && A[end-2] == A[end-1]) {
	    A[end-2]++;
	    end--;
	}
    }

    REP (i, end) printf("%d%c", A[i], i==end-1?'\n':' ');
    return 0;
}