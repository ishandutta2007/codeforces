#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long LL;


int N, p[2000010];
	
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) p[i]=i+1;
    for (int i=2; i<=N; i++) {
	int x=N-(N-1)%i-1+i-2;
	p[N+i-2]=p[x];
	for (;x-i>=i-2;x-=i) p[x]=p[x-i];
    }
    for (int i=N; i<N*2; i++) printf("%d ", p[i-1]); puts("");
    return 0;
}