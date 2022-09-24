#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;

int N, P, A[55];
double d[55][55][210], fact[55];

int main() {
    scanf("%d", &N); for (int i=0; i<N; i++) scanf("%d", A+i);
    scanf("%d", &P);
    fact[0]=1;
    for (int i=1; i<55; i++) fact[i]=fact[i-1]*i;
    
    int su=0;
    for (int i=0; i<N; i++) su+=A[i];
    if (su<=P) {
	printf("%f\n", double(N));
	return 0;
    }

    double ans=0;
    for (int e=0; e<N; e++) {
	d[e][0][0]=1;
	for (int i=0; i<N; i++) {
	    if (i==e) continue;
	    for (int j=N-1; j>0; j--) {
		for (int k=0; k<=P; k++) {
		    d[e][j][k+A[i]]+=d[e][j-1][k];
		}
	    }
	}
	//double tmp=0;
	for (int j=1; j<N; j++) {
	    for (int k=0; k<=P; k++) {
		if (k+A[e]>P) {
		    ans+=d[e][j][k]*fact[j]*fact[N-1-j]*j;
		    //tmp+=d[e][j][k]*fact[j]*fact[N-1-j]*j;
		}
	    }
	}
    }
    ans/=fact[N];
    printf("%.9f\n", ans);

    return 0;
}