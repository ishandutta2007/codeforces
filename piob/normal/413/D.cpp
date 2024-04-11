#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, k;

int add(int m, int a){
    if(m&(a-1)){
        if(m >= (1<<k))
            return m;
        return a;
    }
    while(m&a){
        m -=a;
        a *= 2;
    }
    return m+a;
}

map<int, int> C[2];

int main(){
    scanf("%d %d", &n, &k);
    C[0][0] = 1;
    FWD(i,0,n){
        int x = (i&1);
        int y = 1-x;
        int a;
        scanf("%d", &a);
        C[y].clear();
        if(a == 0){
            for(PII p : C[x]){
                int m = add(p.x, 2);
                C[y][m] = (C[y][m] + p.y) % 1000000007;
            }
            for(PII p : C[x]){
                int m = add(p.x, 4);
                C[y][m] = (C[y][m] + p.y) % 1000000007;
            }
        }else
            for(PII p : C[x]){
                int m = add(p.x, a);
                C[y][m] = (C[y][m] + p.y) % 1000000007;
            }
    }
    int r = 0;
    for(PII p : C[n&1])
        if(p.x >= (1<<k))
            r = (r + p.y) % 1000000007;
    printf("%d\n", r);
    return 0;
}