#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, a, r;

int main(){
    r = 0;
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &a);
        r = max(r, a);
    }
    printf("%d\n", r);
    return 0;
}