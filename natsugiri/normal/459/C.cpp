#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, D, K;
int ans[1111][1111];


int main() {
    scanf("%d%d%d", &N, &K, &D);

    bool ok = true;
    for (int i=0; i<N-1; i++) {
	int c = 1;
	for (int j=0; j<D; j++) {
	    ans[j][i+1] = ans[j][i] + c;
	    if (ans[j][i+1] >= K) {
		c = 1;
		ans[j][i+1] -= K;
	    } else {
		c = 0;
	    }
	}
	if (c == 1) ok = false;
    }

    if (ok) {
	for (int d=0; d<D; d++) {
	    for (int i=0; i<N; i++)
		printf("%d%c", ans[d][i]+1, i==N-1 ? '\n' : ' ' );
	}
    } else {
	puts("-1");
    }

    return 0;
}