#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL MOD= 7340033;

LL ans[32][1010];
LL d[3][1010];

int main() {
    ans[0][0]=ans[1][0]=ans[1][1]=1;

    for (int i=2; i<32; i++) {
	memset(d, 0, sizeof d);
	for (int j=0; j<1010; j++) {
	    for (int k=0; k+j<1010; k++) {
		d[0][j+k] = (d[0][j+k]+ans[i-1][j]*ans[i-1][k])%MOD;
	    }
	}
	for (int j=0; j<1010; j++) {
	    for (int k=0; k+j<1010; k++) {
		d[1][j+k] = (d[1][j+k]+d[0][j]*ans[i-1][k])%MOD;
	    }
	}
	ans[i][0]=1;
	for (int j=0; j<1010; j++) {
	    for (int k=0; k+j<1010; k++) {
		ans[i][j+k+1] = (ans[i][j+k+1]+d[1][j]*ans[i-1][k])%MOD;
	    }
	}
    }

    int q;
    scanf("%d", &q);
    for (;q--;) {
	int n, k;
	scanf("%d%d", &n, &k);
	int cnt=0, m=n;
	for (;m>1 && m&1; m>>=1) cnt++;

	printf("%d\n", int(ans[cnt][k]));
    }
    return 0;
}