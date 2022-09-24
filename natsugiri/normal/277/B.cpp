#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;


int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    if (M==3) {
	if (N==3) { puts("0 0\n0 3\n3 0"); }
	if (N==4) { puts("0 0\n0 3\n3 0\n1 1"); }
	if (N>4) { puts("-1"); }
    } else {
	for (int i=0; i<M; i++) {
	    printf("%d %d\n", M-i, i*i);
	}
	for (int i=0; i<N-M; i++) {
	    printf("%d %d\n", -(N-M-i), -i*i);
	}
    }

    return 0;
}