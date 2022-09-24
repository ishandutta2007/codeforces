#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, R[128], C[128];
char F[128][128];

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
	scanf("%s", F[i]);
	for (int j=0; j<N; j++) {
	    if (F[i][j] == '.') {
		R[i]++;
		C[j]++;
	    }
	}
    }

    bool ok = true;

    for (int i=0; i<N; i++) ok &= (R[i]>0);
    if (ok) {
	for (int i=0; i<N; i++) {
	    for (int j=0; j<N; j++) {
		if (F[i][j]=='.') {
		    printf("%d %d\n", i+1, j+1);
		    break;
		}
	    }
	}
	return 0;
    }

    ok = true;
    for (int j=0; j<N; j++) ok &= (C[j]>0);
    if (ok) {
	for (int j=0; j<N; j++) {
	    for (int i=0; i<N; i++) {
		if (F[i][j]=='.') {
		    printf("%d %d\n", i+1, j+1);
		    break;
		}
	    }
	}
	return 0;
    }
    puts("-1");
    

    return 0;
}