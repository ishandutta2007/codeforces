#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int gcd(int a, int b){
    while(a&&b) a>b?a%=b:b%=a;
    return a+b;
}

int n, a, g;

int main(){
    scanf("%d", &n);
    scanf("%d", &g);
    FWD(i,1,n){
        scanf("%d", &a);
        g = gcd(g, a);
    }
    printf("%d\n", g*n);
    return 0;
}