#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const int INF = 1<<29;

int main() {
    int N, M, X, Y, A, B;
    scanf("%d%d%d%d%d%d", &N, &M, &X, &Y, &A, &B);
    X--; Y--;
    int tx[]={0, 0, N-1, N-1};
    int ty[]={0, M-1, 0, M-1};

    int ans = INF;
    for (int d=0; d<4; d++) {
	if ((tx[d]-X) % A != 0 || (ty[d]-Y) % B != 0) continue;

	int z[2]={abs(tx[d]-X)/A, abs(ty[d]-Y)/B};

	if (z[0] % 2 == z[1] % 2) {
	    int tmp = max(z[0], z[1]);
	    if (tmp==0) ans = 0;
	    else {
		if ((0<=X-A || X+A<N) && 
		    (0<=Y-B || Y+B<M))
		    ans = min(ans, tmp);
	    }
	}
    }

    if (ans == INF) puts("Poor Inna and pony!");
    else printf("%d\n", ans);

    return 0;
}