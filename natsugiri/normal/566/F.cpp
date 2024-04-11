#include<map>
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
int A[1000111];
int C[1000111];
int main() {
    scanf("%d", &N);
    REP (i, N) {
    	scanf("%d", A+i);
    }

    sort(A, A+N);
    
    int ans = 0;
    for (int i=N-1; i>=0; i--) {
	if (i+1 < N && A[i] == A[i+1]) C[A[i]]++;
	else {
	    C[A[i]] = 0;
	    for (int j=A[i]; j<1000111; j+=A[i]) amax(C[A[i]], C[j]+1);
	}
    }
    REP (i, N) {
	amax(ans, C[A[i]]);
    }

    printf("%d\n", ans);
    return 0;
}