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


int N, A[100011];


int main() {
    scanf("%d", &N);
    REP(i, N) scanf("%d", A+i);

    int p = 0;
    REP (i, N-1) if (A[i] > A[i+1]) p = i+1;

    REP (i, N-1) if (A[(p+i)%N] > A[(p+i+1)%N]) {
	puts("-1");
	return 0;
    }
    printf("%d\n", (N-p) % N);

    return 0;
}