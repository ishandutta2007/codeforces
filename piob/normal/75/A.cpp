#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int a, b;

int er(int x){
    LL y = 0;
    while(x){
        if(x%10) y = 10*y + (x%10);
        x /= 10;
    }
    x = 0;
    while(y){
        if(y%10) x = 10*x + (y%10);
        y /= 10;
    }
    return x;
}

int main(){
    scanf("%d %d", &a, &b);
    if(er(a)+er(b) == er(a+b))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}