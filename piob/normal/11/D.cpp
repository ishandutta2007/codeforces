#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, m;
LL D[(1<<19)+3][21];
LL r;
bool M[21][21];
vector<int> in[(1<<19)+3], out[(1<<19)+3];

int main(){
    scanf("%d %d", &n, &m);
    FWD(i,0,m){
        int a, b;
        scanf("%d %d", &a, &b);
        --a; --b;
        M[a][b] = M[b][a] = 1;
    }
    FWD(m,0,1<<n)
        FWD(u,0,n)
            if(m&(1<<u))
                in[m].push_back(u);
            else
                out[m].push_back(u);
    FWD(u,0,n){
        FWD(m,0,1<<n)
            FWD(v,0,n)
                D[m][v] = 0;
        D[1<<u][u] = 1;
        FWD(m,0,1<<(n-u))
            for(int v : in[m<<u]){
                for(int w : out[m<<u])
                    if(M[v][w] && !((m<<u)&(1<<w)))
                        D[(m<<u)|(1<<w)][w] += D[(m<<u)][v];
                if(__builtin_popcount(m) > 2 && M[u][v])
                    r += D[(m<<u)][v];
            }
    }
    cout << r/2 << endl;
    return 0;
}