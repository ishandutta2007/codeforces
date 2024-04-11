#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;

int N, M, A[100010], L[100010], R[100010], B[100010];
int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++) scanf("%d", A+i);

    int p=0;
    for (int i=1; i<N; i++) {
	if (A[i-1]>A[i]) p=i;
	L[i]=p;
    }
    p=N-1; R[N-1]=N-1;
    for (int i=N-1; i--; ) {
	if (A[i+1]>A[i]) p=i;
	R[i]=p;
    }

    for (int i=0; i<N; i++) B[L[i]]=R[i]-L[i]+1;
    p=0;
    for (int i=0; i<N; i++) {
	if (p<B[i]) p=B[i];
	else B[i]=p;
	p--;
    }

    for (;M--;) {
	int x, y;
	scanf("%d%d", &x, &y); x--; y--;
	if (B[x]>=y-x+1) puts("Yes");
	else puts("No");
    }
    return 0;
}