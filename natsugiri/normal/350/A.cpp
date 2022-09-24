#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, M;
int main() {
    scanf("%d%d", &N, &M);
    int a1=1000, an=-1, b=1000, x;
    for (int i=0; i<N; i++) {
	scanf("%d", &x);
	a1 = min(a1, x);
	an = max(an, x);
    }
    for (int i=0; i<M; i++) {
	scanf("%d", &x);
	b = min(b, x);
    }
    
    int v = max(an, 2*a1);
    if (v<b) printf("%d\n", v);
    else puts("-1");
    
    return 0;
}