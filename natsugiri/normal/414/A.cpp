#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, K;
int main() {
    scanf("%d%d", &N, &K);
    if (N/2 > K || (N<2 && K!=0)) {
	puts("-1");
    } else if (N==1) {
	puts("1");
    } else {
	int a = K - N/2 + 1;
	printf("%d %d", a, 2*a);
	for (int i=2; i<N; i++) printf(" %d", 2*a+i-1);
	puts("");
    }

    return 0;
}