#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int>now[105][105];
int res[105][105];
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            now[i][j]=make_pair(i,j);
    while(q--)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            int r;
            scanf("%d",&r);
            r--;
            for(int i=1;i<m;i++)
                swap(now[r][i],now[r][i-1]);
        }
        else if(t==2)
        {
            int c;
            scanf("%d",&c);
            c--;
            for(int i=1;i<n;i++)
                swap(now[i][c],now[i-1][c]);
        }
        else
        {
            int r,c,x;
            scanf("%d%d%d",&r,&c,&x);
            r--,c--;
            res[now[r][c].first][now[r][c].second]=x;
        }
    }
    for(int i=0;i<n;i++,printf("\n"))
        for(int j=0;j<m;j++)
            printf("%d ",res[i][j]);
    return 0;
}