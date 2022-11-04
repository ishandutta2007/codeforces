#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int m;
int vis[20005];
queue<int>q;
void bfs(int s)
{
    q.push(s);
    vis[s]=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        if(t>1&&(vis[t-1]==-1||vis[t-1]>vis[t]+1)){
            vis[t-1]=vis[t]+1;
            q.push(t-1);
        }
        if(t>0&&t<=10000&&(vis[2*t]==-1||vis[2*t]>vis[t]+1)){
            vis[2*t]=vis[t]+1;
            q.push(2*t);
        }
    }
}
int main()
{
    int n;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=20000;i++)vis[i]=-1;
    bfs(n);
    printf("%d\n",vis[m]);
    return 0;
}