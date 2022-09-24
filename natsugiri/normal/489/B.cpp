#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

template<class T> inline T &amin(T &a, T b) { if (a>b) a=b; return a; }
template<class T> inline T &amax(T &a, T b) { if (a<b) a=b; return a; }


int A_N, A[111];
int B_N, B[111];
int main() {
    scanf("%d", &A_N);
    REP (i, A_N) scanf("%d", A+i);
    sort(A, A+A_N);

    scanf("%d", &B_N);
    REP (i, B_N) scanf("%d", B+i);
    sort(B, B+B_N);

    int ans = 0;
    for (int a=0, b=0; a<A_N && b<B_N;) {
	if (abs(A[a] - B[b]) < 2) {
	    ans++;
	    a++;
	    b++;
	} else if (A[a] < B[b]) {
	    a++;
	} else {
	    b++;
	}
    }

    printf("%d\n", ans);
    

    return 0;
}