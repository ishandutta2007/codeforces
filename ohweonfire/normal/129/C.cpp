#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <utility>
#include <cstdlib>
#include <bitset>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=10,n=8;
bool bad[maxn][maxn][maxn*maxn],vis[maxn][maxn][maxn*maxn];
char field[maxn][maxn];
int qx[maxn*maxn*maxn*maxn],qy[maxn*maxn*maxn*maxn],qt[maxn*maxn*maxn*maxn];
bool bfs(int x,int y,int t)
{
    int front=0,rear=1,nx,ny,nt;
    qx[0]=x;
    qy[0]=y;
    qt[0]=t;
    while(front!=rear)
    {
        x=qx[front];
        y=qy[front];
        t=qt[front++];
        if(x==0&&y==n-1)
            return true;
        for(int dx=-1;dx<=1;dx++)for(int dy=-1;dy<=1;dy++)
        {
            nx=x+dx;
            ny=y+dy;
            nt=t+1;
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&!bad[nx][ny][nt]&&!vis[nx][ny][nt])
            {
                qx[rear]=nx;
                qy[rear]=ny;
                qt[rear++]=nt;
                vis[nx][ny][nt]=true;
            }
        }
    }
    return false;
}
int main()
{
    for(int i=0;i<n;i++)
    {
        scanf("%s",field[i]);
        for(int j=0;j<n;j++)
            if(field[i][j]=='S')
                for(int k=i;k<n;k++)
                    bad[k][j][k-i]=bad[k][j][k-i+1]=true;
    }
    if(bfs(n-1,0,0))
        puts("WIN");
    else
        puts("LOSE");
    return 0;
}