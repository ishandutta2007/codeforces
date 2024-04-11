#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, M, Q;
char F[51][51];
int D[51][51][51][51];

int U[51][51];

int main() {
    scanf("%d%d%d", &N, &M, &Q);

    for (int i=0; i<N; i++) scanf("%s", F[i]);

    for (int i=0; i<N; i++) {
	for (int j=0; j<M; j++) {
	    if (F[i][j] == '1') {
		continue;
	    } else {
		int u = U[i][j+1]+1;
		U[i+1][j+1] = u;

		for (int k=j; k>=0; k--) {
		    u = min(u, U[i+1][k+1]);
		    for (int a=0; a<=i; a++) {
			for (int b=0; b<=k; b++) {
			    D[a][b][i+1][j+1] += min(u, i+1-a);
			}
		    }
		}
	    }
	}
    }

//     for (int i=0; i<=N; i++) {
// 	for (int j=0; j<=M; j++) {
// 	    printf("%d ", D[0][0][i][j]);
// 	}
// 	puts("");
//     }


    for (;Q--;) {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	a--; b--;

	int ans = 0;
	for (int i=a+1; i<=c; i++) {
	    for (int j=b+1; j<=d; j++) {
		ans += D[a][b][i][j];
	    }
	}
	printf("%d\n", ans);
    }

    return 0;
}