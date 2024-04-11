#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

int N, T;
int B[200][200], C[200][200];

int main() {
    scanf("%d%d", &N, &T);
    B[100][100]=N;
    int L=1;
    for (;;) {
	memset(C, 0, sizeof C);
	bool ok=true;
	for (int i=100-L; i<=100+L; i++) {
	    for (int j=100-L; j<=100+L; j++) {
		if (B[i][j]>=4) {
		    ok=false;
		    if (i==100+L) L++;
		    for (int d=0; d<4; d++)
			C[i+dx[d]][j+dy[d]] += B[i][j]>>2;
		}

		C[i][j] += B[i][j] & 3;
	    }
	}
	for (int i=100-L; i<=100+L; i++) {
	    for (int j=100-L; j<=100+L; j++) {
		B[i][j]=C[i][j];
	    }
	}

	if (ok) break;
    }

//     for (int i=90; i<=110; i++) {
// 	for (int j=90; j<=110; j++) {
// 	    printf("%d ", B[i][j]);
// 	}
// 	puts("");
//     }
    for (;T--;) {
	int x, y;
	scanf("%d%d", &x, &y);
	x+=100; y+=100;
	if (x<0 || 200<=x || y<0 || 200<=y) puts("0");
	else printf("%d\n", B[x][y]);
    }

    //for (int i=0; i<200; i++) printf("%d ", B[100][i]);
    return 0;
}
// 30000 0