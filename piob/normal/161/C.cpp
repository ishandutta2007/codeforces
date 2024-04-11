#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int r;

void sol(int a, int b, int c, int d, int x){
    r = max(r, min(b,d)-max(a,c)+1);
    if(a == c) return;
    if(b == d) return;
    if(x == 0) return;
    if(a == x) ++a;
    if(b == x) --b;
    if(c == x) ++c;
    if(d == x) --d;
    if(a > b) return;
    if(c > d) return;
    if(a > x){
        a -= x+1;
        b -= x+1;
    }
    if(c > x){
        c -= x+1;
        d -= x+1;
    }
    if(b < x && d < x)
        sol(a,b,c,d,x/2);
    if(b > x && d < x){
        sol(a,x-1,c,d,x/2);
        sol(0,b-x-1,c,d,x/2);
    }
    if(b < x && d > x){
        sol(a,b,c,x-1,x/2);
        sol(a,b,0,d-x-1,x/2);
    }
    if(b > x && d > x){
        sol(a,x-1,c,x-1,x/2);
        sol(0,b-x-1,c,x-1,x/2);
        sol(a,x-1,0,d-x-1,x/2);
        sol(0,b-x-1,0,d-x-1,x/2);
    }
}

int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    --a;
    --b;
    --c;
    --d;
    sol(a, b, c, d, 1024*1024*1024-1);
    printf("%d\n", r);
    return 0;
}