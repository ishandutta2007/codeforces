#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, k, r;
int M[1010][1010];
int P[1010];
int D[1010];

void policz(int u){
    if(D[u]) return;
    D[u] = 1;
    FWD(v,1,n+1)
        if(M[v][u] == k){
            policz(v);
            D[u] = max(D[u], D[v]+1);
        }
    r = max(r, D[u]);
}

int main(){
    scanf("%d %d", &n, &k);
    FWD(j,0,k){
        FWD(i,0,n) scanf("%d", &P[i]);
        FWD(i,0,n)
            FWD(j,i+1,n)
                ++M[P[i]][P[j]];
    }
    FWD(i,1,n+1) policz(i);
    printf("%d\n", r);
    return 0;
}