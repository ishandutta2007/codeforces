#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

LL K;

char F[1024][1024];
int M[2000][2000];
int main() {

    memset(F, 'N', sizeof F);
    cin >> K;

    int cnt=4;
    F[0][2] = F[2][0] = F[0][3] = F[3][0] = 'Y';
    M[1][0] = 2;
    M[1][1] = 3;

    for (int i=1; i<32; i++) {

	for (int j=0; j<=i-1; j++) {
	    int p = M[i][j], q = cnt++;
	    M[i+1][j] = q;
	    F[p][q] = F[q][p] = 'Y';
	}

	{
	    int a[2] = {M[i][i-1],  M[i][i]};
	    int b[2];
	    M[i+1][i] = b[0] = cnt++;
	    M[i+1][i+1] = b[1] = cnt++;
	    
	    for (int x=0; x<2; x++) {
		for (int y=0; y<2; y++) {
		    F[a[x]][b[y]] = F[b[y]][a[x]] = 'Y';
		}
	    }
	}
    }



    for (int i=0; i<32; i++) {
	if (K & (1LL<<i)) {
	    F[1][ M[32][i] ] = F[ M[32][i] ][1] = 'Y';
	}
    }

    printf("%d\n", cnt);
    
    for (int i=0; i<cnt; i++) {
	for (int j=0; j<cnt; j++) putchar(F[i][j]);
	putchar('\n');
    }


    return 0;
}