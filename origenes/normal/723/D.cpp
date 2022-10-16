#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
bool mat[60][60], vis[60][60], ocean[60][60];
int n, m, k;
struct pos{
    int x, y, num;
};
vector<pos> v;
inline bool cmp(pos p1, pos p2){
    return p1.num<p2.num;
}
void dfs(int y, int x, int* cnt, bool flag, bool* islake){
    if(!(*islake)){
        if(!mat[y][x]) ocean[y][x]=true;
        return;
    }
    //printf("%d%d!\n", y, x);
    if(!flag) if(!(x*y)||x>m||y>n||ocean[y][x]){
            *islake=false;
            ocean[y][x]=true;
            return;
        }
    //printf("!\n");
    if(mat[y][x]||vis[y][x]) return;
    //printf("!\n");
    vis[y][x]=true;
    if(!flag) (*cnt)++;
    else mat[y][x]=true;
                                        dfs(y-1, x, cnt, flag, islake);
    dfs(y, x-1, cnt, flag, islake);                                         dfs(y, x+1, cnt, flag, islake);
                                        dfs(y+1, x, cnt, flag, islake);
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    memset(mat, false, sizeof(mat));
    memset(vis, false, sizeof(vis));
    memset(ocean, false, sizeof(ocean));
    getchar();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char c;
            scanf("%c", &c);
            if(c=='*') mat[i][j]=true;
        }
        getchar();
    }
    /*for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(mat[i][j]) putchar('*');
            else putchar('.');
        }
        putchar('\n');
    }*/
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!mat[i][j]&&!vis[i][j]){
                int cnt=0;
                bool islake=true;
                dfs(i, j, &cnt, false, &islake);
                //printf("%d%d%d\n", i, j, vis[2][2]);
                if(islake){
                    pos p;
                    p.num=cnt;
                    p.x=j;
                    p.y=i;
                    v.push_back(p);
                }
            }
        }
    }
    //printf("!\n");
    memset(vis, false, sizeof(vis));
    sort(v.begin(), v.end(), cmp);
    /*for(int i=0; i<v.size(); i++)
        printf("%d %d %d\n", v[i].x, v[i].y, v[i].num);*/
    int change=v.size()-k, moves=0;
    //printf("%d\n", change);
    for(int i=0; i<change; i++){
        bool islake=true, flag=true;
        dfs(v[i].y, v[i].x, 0, flag, &islake);
        //printf("!\n");
        moves+=v[i].num;
    }
    //printf("!\n");
    printf("%d\n", moves);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(mat[i][j]) putchar('*');
            else putchar('.');
        }
        putchar('\n');
    }
    //printf("%d\n", ocean[2][2]);
    return 0;
}