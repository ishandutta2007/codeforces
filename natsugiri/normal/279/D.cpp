#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;
const int INF=1<<29;
int N, A[64], memo[1<<23];
int popcount(int n) {
    int r=0;
    for (;n;) {
	r+=n&1;
	n>>=1;
    }
    return r;
}
int calc(int S) {
    if (memo[S]!=-1) return memo[S];
    if (S==1) return 1;
    int x, ret=INF, p=popcount(S);
    for (x=N; ~S&(1<<x); x--);
    for (int i=0; i<x; i++) {
	for (int j=0; j<=i; j++) {
	    if (A[i]+A[j]==A[x]) {
		int tmp=calc((S & ~(1<<x)) | (1<<(x-1)) | (1<<i) | (1<<j));
		ret=min(ret, max(tmp, p));
	    }
	}
    }
    return memo[S]=ret;
}
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A+i);
    memset(memo, -1, sizeof memo);
    int ans=calc(1<<(N-1));
    if (ans==INF) ans=-1;
    printf("%d\n", ans);
    return 0;
}