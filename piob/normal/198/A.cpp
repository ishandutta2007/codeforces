#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int k, b, n, t;

int main(){
    scanf("%d %d %d %d", &k, &b, &n, &t);
    LL z = 1;
    FWD(i,0,n+1){
        if(t < z){
            printf("%d\n", n-i+1);
            return 0;
        }
        z = z * k + b;
    }
    printf("0\n");
    return 0;
}