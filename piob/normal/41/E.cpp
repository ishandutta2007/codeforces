#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n;

int main(){
    scanf("%d", &n);
    printf("%d\n", (n/2)*(n-n/2));
    FWD(i,0,n/2)
        FWD(j,n/2,n)
            printf("%d %d\n", i+1, j+1);
    return 0;
}