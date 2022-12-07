#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int k, d;

int main(){
    scanf("%d %d", &k, &d);
    if(!d && k > 1){
        printf("No solution\n");
        return 0;
    }
    printf("%d", d);
    FWD(i,0,k-1)
        printf("0");
    printf("\n");
    return 0;
}