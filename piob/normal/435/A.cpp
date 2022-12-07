#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, m, c, f;

int main(){
    scanf("%d %d", &n, &m);
    FWD(i,0,n){
        int a;
        scanf("%d", &a);
        if(f + a > m){
            ++c;
            f = 0;
        }
        f += a;
    }
    if(f) ++c;
    printf("%d\n", c);
    return 0;
}