#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int a, b, n;

int pow(int x, int y){
    int z = 1;
    FWD(i,0,y){
        z *= x;
        if(abs(z) > 1010)
            return z;
    }
    return z;
}

int main(){
    scanf("%d %d %d", &a, &b, &n);
    FWD(x,-1010,1010)
        if(a*pow(x,n) == b){
            printf("%d\n", x);
            return 0;
        }
    printf("No solution\n");
    return 0;
}