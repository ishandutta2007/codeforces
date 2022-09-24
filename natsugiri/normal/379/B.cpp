#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, A[333];
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A+i);

    
    for (int i=0; i<N; i++) {
	while (A[i]) {
	    if (i==0) printf("RLP");
	    else printf("LRP");
	    A[i]--;
	}
	if (i<N-1) printf("R");
    }

    putchar('\n');

    return 0;
}