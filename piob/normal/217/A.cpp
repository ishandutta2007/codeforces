#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <set>
#include <stack>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(__typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define PDD pair<long double, long double>
#define x first
#define y second
#define EPS 1e-9
#define INF 1000000009
#define ALL(a) (a).begin(), (a).end()

using namespace std;

int n;
int R[110];
PII P[110];
vector<PII> E;

int cost(int u, int v){
    if(P[u].x == P[v].x || P[u].y == P[v].y) return 0;
    return 1;
}

inline bool cmp(const PII &a, const PII &b){
    return cost(a.x, a.y) < cost(b.x, b.y);
}

int find(int u){
    return R[u] == u?u:(R[u]=find(R[u]));
}

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d %d", &P[i].x, &P[i].y);
        FWD(j,i+1,n)
            E.push_back(PII(i,j));
        R[i] = i;
    }
    sort(ALL(E), cmp);
    int r = 0;
    FE(e,E){
        if(find(e->x) != find(e->y)){
            R[find(e->x)] = find(e->y);
            r += cost(e->x, e->y);
        }
    }
    printf("%d\n", r);
    return 0;
}