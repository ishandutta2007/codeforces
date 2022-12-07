#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int p, n, a;
bool u[310];

int main(){
    scanf("%d %d", &p, &n);
    FWD(i,0,n){
        scanf("%d", &a);
        if(u[a%p]){
            printf("%d\n", i+1);
            return 0;
        }
        u[a%p] = 1;
    }
    printf("-1\n");
    return 0;
}