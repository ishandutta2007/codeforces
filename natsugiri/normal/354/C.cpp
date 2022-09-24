#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const int UB = 1000010;
int N, K, A[300100];
int dp[1000100];

int main() {
    scanf("%d%d", &N, &K);

    for (int i=0; i<N; i++) scanf("%d", A+i);
    int mi = A[0];

    for (int i=0; i<N; i++) {
	int L = max(0, A[i]-K), R = A[i];
	dp[L]++;
	dp[R+1]--;
	mi = min(mi, A[i]);
    }
    for (int i=0; i<UB; i++) dp[i+1] += dp[i];
    for (int i=mi; ; i--) {
	int cnt=0;
	for (int d=i; d<UB; d+=i) cnt += dp[d];
	if (cnt>=N) {
	    printf("%d\n", i);
	    return 0;
	}
    }	
    
    return 0;
}