#include <cstdio>
#include <vector>
#include <assert.h>

using namespace std;

int n,m;
bool imp = false;
short int col[100005];
vector <int> g[100005];

void dfs(int x,int y,int color){
    if(col[x] != color && col[x] != 0){imp = true;return;}
    if(col[x] != 0) return;
    col[x] = color;
    for(int i = 0;i<g[x].size();i++){
        if(g[x][i] != y){
            dfs(g[x][i],x,color*-1);
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    int x,y;
    for(int i = 0;i<m;i++){
        scanf("%d %d",&x,&y);
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 0;i<n;i++){
        if(col[i] == 0 && g[i].size() != 0){
            dfs(i,i,1);
        }

    }
    if(imp){
        printf("-1\n");
        return 0;
    }
    else{
        vector <int> sol1;
        vector <int> sol2;
        for(int i = 0;i<n;i++){
            if(col[i] == 1) sol1.push_back(i);
            if(col[i] == -1) sol2.push_back(i);
            if(col[i] == 0 && g[i].size()!=0){
                printf("-1\n");
                return 0;
            }

        }
        printf("%d\n",sol1.size());
        for(int i = 0;i<sol1.size();i++){
            printf("%d ",sol1[i]+1);
        }
        printf("\n");
        printf("%d\n",sol2.size());
        for(int i = 0;i<sol2.size();i++){
            printf("%d ",sol2[i]+1);
        }
        printf("\n");
    }
}