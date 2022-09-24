#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, B[200011];
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", B+i);

    sort(B, B+N);
    
    LL p=0, q=0;
    for (int i=0; i<N; i++) {
	if (B[i] == B[0]) p++;
	if (B[i] == B[N-1]) q++;
    }

    if (B[0] == B[N-1]) printf("0 %lld\n", p*(p-1)/2);
    else printf("%lld %lld\n", (LL)B[N-1]-B[0], p*q);
	

    return 0;
}