#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int> pii;
typedef pair < int, pii> pip;
typedef pair < pii, int> ppi;

const int N = 1e6 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 22;
const int OFF = (1 << LOG);
const double PI = 3.1415926535;
const double EPS = 1e-9;

int con[N], dis[N];
int n,k;
int par[N][LOG],dep[N];
vi v[N];
vi sol;

void dfs(int x,int lst){
    par[x][0] = lst;
    dep[x] = dep[lst] + 1;
    for(int i = 0;i<v[x].size();i++){
        if(v[x][i] == lst) continue;
        dfs(v[x][i], x);
    }
}

void compute(){
    for(int j = 1;j<LOG;j++){
        for(int i = 1;i<=n;i++){
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

int getdis(int x){
    int st = dep[x];
    if(con[x]) return 0;
    for(int i = LOG - 1;i>=0;i--){
        if(!con[par[x][i]]){
            x = par[x][i];
        }
    }
    return st - dep[x] + 1;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0;i<n - 1;i++){
        int x,y;scanf("%d%d", &x, &y);
        v[x].PB(y);
        v[y].PB(x);
    }
    k = n - k;
    dep[n] = -1;
    dfs(n,n);
    con[n] = 1;
    compute();
    k--;
    for(int i = n - 1;i>=1;i--){
        if(con[i]) continue;
        else if(getdis(i)  <= k){
            int x = i;
            while(!con[x]){
                con[x] = 1;
                x = par[x][0];
                k--;
            }
        }
        else{
            sol.PB(i);
        }
    }
    for(int i = sol.size() - 1;i>=0;i--)
        printf("%d ",sol[i]);
    printf("\n");
}