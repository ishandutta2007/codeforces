#include <cstdio>
#include <vector>
#include <algorithm>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < ll, ll > pt;

const int N = 1e5 + 500;
const int LOG = 20;

int par[N][LOG], dep[N], n, q;
pt toc[N];

vector < int > hull;

ll ccw(pt A, pt B, pt C){
    return A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y);
}

void gradi(){
    hull.PB(n - 1);
    par[n - 1][0] = n - 1;
    for(int i = n - 2;i>=0;i--){
        while(hull.size() >= 2 && ccw(toc[hull.back()], toc[hull[hull.size() - 2]], toc[i]) > 0LL)
            hull.pop_back();
        par[i][0] = hull.back();
        dep[i] = dep[par[i][0]] + 1;
        hull.PB(i);
    }
}

void priprema(){
    for(int i = 1;i<LOG;i++){
        for(int j = 0;j<n;j++){
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
}

int lca(int x,int y){
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = LOG - 1;i >= 0;i--){
        if(dep[x] - dep[y] >= (1 << i))
            x = par[x][i];
    }
    if(x == y) return x;
    for(int i = LOG - 1; i >= 0 ;i--){
        if(par[x][i] != par[y][i]){
            x = par[x][i], y = par[y][i];
        }
    }
    return par[x][0];
}

int main(){
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%lld%lld", &toc[i].X, &toc[i].Y);
    }
    gradi();
    priprema();
    int q;scanf("%d", &q);
    for(int i = 0;i<q;i++){
        int x, y;scanf("%d%d", &x, &y);
        x--;y--;
        printf("%d ", lca(x, y) + 1);
    }
    printf("\n");
}