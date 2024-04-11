#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=1000000007;
int n,m;
char maze[55][55];
bool visited[55][55];
void dfs(int a,int b)
{
    if(visited[a][b]==1)return;
    visited[a][b]=1;
    if(a<n-1&&maze[a+1][b]=='#')dfs(a+1,b);
    if(b<m-1&&maze[a][b+1]=='#')dfs(a,b+1);
    if(a>0&&maze[a-1][b]=='#')dfs(a-1,b);
    if(b>0&&maze[a][b-1]=='#')dfs(a,b-1);
}
int main()
{
    int ans=INF,num=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",maze[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j]=='#')num++;
        }
    }
    if(num<=2){
        printf("-1\n");
    }
    else{
        bool flag=0;
        for(int p=0;p<n&&!flag;p++){
            for(int q=0;q<m&&!flag;q++){
                int cnt=0;
                if(maze[p][q]=='#'){
                    maze[p][q]='.';
                    memset(visited,0,sizeof(visited));
                    for(int i=0;i<n;i++){
                        for(int j=0;j<m;j++){
                            if(maze[i][j]=='#'&&!visited[i][j]){
                                cnt++;
                                dfs(i,j);
                            }
                        }
                    }
                    maze[p][q]='#';
                }
                if(cnt>=2)flag=1;
            }
        }
        if(flag)printf("1\n");
        else printf("2\n");
    }
    return 0;
}