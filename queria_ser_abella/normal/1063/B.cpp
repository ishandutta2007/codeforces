#include <bits/stdc++.h>
#define pii pair<int,int>
#define pip pair<int,pii>
#define maxn 2020
#define debug 
typedef long long ll;
using namespace std;

char M[maxn][maxn];
int dist[maxn][maxn];
int foi[maxn][maxn];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int n,m;

int ok(int a,int b){
    return a >= 0 && b >= 0 && a < n && b < m && M[a][b] != '*' && !foi[a][b];
}

int main() {
    int r,c;
    int x,y;
    scanf("%d%d%d%d%d%d",&n,&m,&r,&c,&x,&y);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf(" %c",&M[i][j]), dist[i][j] = maxn*maxn;
    r--, c--;
    dist[r][c] = 0;
    set<pip> S;
    int ans = 0;
    S.insert(pip(0,pii(r,c)));
   
    while(S.size()){
        pip u = *(S.begin());
        S.erase(u);
        pii o = u.second;
        if(foi[o.first][o.second]) continue;
        foi[o.first][o.second] = 1;
        int R = dist[o.first][o.second];
        int AA = o.second-c;
        //R-L = AA;
        int L = R-AA;
        debug("xy %d %d lr %d %d\n",o.first,o.second,L,R);
        if(R <= y && L <= x) ans++;
        for(int i=0;i<4;i++){
            int x = o.first+dx[i];
            int y = o.second+dy[i];
            if(ok(x,y) && dist[x][y] > dist[o.first][o.second]+(i==0)){
                dist[x][y] = dist[o.first][o.second]+(i==0);
                S.insert(pip(dist[x][y],pii(x,y)));
            }
        }
    }
    printf("%d\n",ans);
}