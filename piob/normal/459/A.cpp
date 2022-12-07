#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

const int MAXN = 100010;

int main(){
    int x0, y0, x1, y1;
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
    if(x0 == x1){
        printf("%d %d %d %d\n", x0+(y1-y0), y0, x1+(y1-y0), y1);
        return 0;
    }
    if(y0 == y1){
        printf("%d %d %d %d\n", x0, y0+(x1-x0), x1, y1+(x1-x0));
        return 0;
    }
    if(abs(x0-x1) == abs(y0-y1)){
        printf("%d %d %d %d\n", x0, y1, x1, y0);
        return 0;
    }
    printf("-1\n");
    return 0;
}