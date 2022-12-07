#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int a, b, c, d;

int main(){
    scanf("%d %d %d %d", &a, &b, &c, &d);
    swap(c,d);
    if(a <= c+1 && c <= 2*a+2)
        printf("YES\n");
    else if(b <= d+1 && d <= 2*b+2) 
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}