#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

char a[5], b[5];

int main(){
    scanf("%s%s", a, b);
    int x = b[0]-a[0];
    int y = b[1]-a[1];
    printf("%d\n", max(abs(x), abs(y)));
    while(x||y){
        if(x>0) printf("R"), --x; else if(x<0) printf("L"), ++x;
        if(y>0) printf("U"), --y; else if(y<0) printf("D"), ++y;
        printf("\n");
    }
    return 0;
}