#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, s, r, x, y;

int main(){
    r = -1;
    scanf("%d %d", &n, &s);
    FWD(i,0,n){
        scanf("%d %d", &x, &y);
        if(x < s)
            r = max(r, (100-y)%100);
        if(x == s && y == 0)
            r = max(r, 0);
    }
    printf("%d\n", r);
    return 0;
}