#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL INF = 1e12;

int N, K, A[2010];
LL dp[2010];

int main() {
    scanf("%d%d", &N, &K);
    for (int i=0; i<N; i++) scanf("%d", A+i);

    LL l=-1, r=INF, m;
    for (;r-l>1;) {
	m = (r+l)/2;

	//memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for (int i=1; i<N; i++) {
	    dp[i] = i;
	    for (int j=0; j<i; j++) {
		if (abs((LL)A[j]-A[i]) <= m * (i-j)) {
		    dp[i] = min(dp[i], dp[j] + i-j-1);
		}
	    }
	}

	LL z = INF;
	for (int i=0; i<N; i++) z = min(z, dp[i] + (N-i-1));
	
	if (z<=K) r=m;
	else l=m;
    }

    cout << r << endl;

    return 0;
}