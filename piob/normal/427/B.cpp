#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, t, c, r;

int main(){
    scanf("%d %d %d", &n, &t, &c);
    int p = -1, a;
    FWD(i,0,n){
        scanf("%d", &a);
        if(a > t){
            r += max(0, i-p-c);
            p = i;
        }
    }
    r += max(0, n-p-c);
    printf("%d\n", r);
    return 0;
}