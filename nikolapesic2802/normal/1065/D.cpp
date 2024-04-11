#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
int m;
bool inside(int x,int y,int n)
{
    if(x>=0&&x<n&&y>=0&&y<n)
        return true;
    return false;
}
int main()
{
    int n;
    scanf("%i",&n);
    m=n*n;
    pair<int,int> dist[n][n][4][n][n][4];
    pair<int,int> poz[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=1;k<4;k++)
            {
                for(int i1=0;i1<n;i1++)
                {
                    for(int j1=0;j1<n;j1++)
                    {
                        for(int k1=1;k1<4;k1++)
                        {
                            dist[i][j][k][i1][j1][k1]=make_pair(INT_MAX/10,INT_MAX/10);
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a;
            scanf("%i",&a);
            a--;
            poz[a]=make_pair(i,j);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=1;k<4;k++)
            {
                for(int l=1;l<4;l++)
                {
                    if(l!=k)
                    {
                        dist[i][j][k][i][j][l]=make_pair(1,1);

                    }
                    else
                    {
                        dist[i][j][k][i][j][l]=make_pair(0,0);
                        //printf("od %i-%i-%i do %i-%i-%i  %i,%i\n",i,j,k,i,j,l,dist[i][j][k][i][j][l].first,dist[i][j][k][i][j][l].second);
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int tx=i-1,ty=j-1;
            while(inside(tx,ty,n))
            {
                dist[i][j][2][tx][ty][2]=make_pair(1,0);
                tx--;
                ty--;
            }
            tx=i-1,ty=j+1;
            while(inside(tx,ty,n))
            {
                dist[i][j][2][tx][ty][2]=make_pair(1,0);
                tx--;
                ty++;
            }
            tx=i+1,ty=j-1;
            while(inside(tx,ty,n))
            {
                dist[i][j][2][tx][ty][2]=make_pair(1,0);
                tx++;
                ty--;
            }
            tx=i+1,ty=j+1;
            while(inside(tx,ty,n))
            {
                dist[i][j][2][tx][ty][2]=make_pair(1,0);
                tx++;
                ty++;
            }
            tx=i-1,ty=j;
            while(inside(tx,ty,n))
            {
                dist[i][j][3][tx][ty][3]=make_pair(1,0);
                tx--;
            }
            tx=i+1,ty=j;
            while(inside(tx,ty,n))
            {
                dist[i][j][3][tx][ty][3]=make_pair(1,0);
                tx++;
            }
            tx=i,ty=j-1;
            while(inside(tx,ty,n))
            {
                dist[i][j][3][tx][ty][3]=make_pair(1,0);
                ty--;
            }
            tx=i,ty=j+1;
            while(inside(tx,ty,n))
            {
                dist[i][j][3][tx][ty][3]=make_pair(1,0);
                ty++;
            }
            tx=i+2,ty=j+1;
            if(inside(tx,ty,n))
                dist[i][j][1][tx][ty][1]=make_pair(1,0);
            tx=i-2,ty=j+1;
            if(inside(tx,ty,n))
                dist[i][j][1][tx][ty][1]=make_pair(1,0);
            tx=i-2,ty=j-1;
            if(inside(tx,ty,n))
                dist[i][j][1][tx][ty][1]=make_pair(1,0);
            tx=i+2,ty=j-1;
            if(inside(tx,ty,n))
                dist[i][j][1][tx][ty][1]=make_pair(1,0);
            tx=i+1,ty=j+2;
            if(inside(tx,ty,n))
                dist[i][j][1][tx][ty][1]=make_pair(1,0);
            tx=i+1,ty=j-2;
            if(inside(tx,ty,n))
                dist[i][j][1][tx][ty][1]=make_pair(1,0);
            tx=i-1,ty=j+2;
            if(inside(tx,ty,n))
                dist[i][j][1][tx][ty][1]=make_pair(1,0);
            tx=i-1,ty=j-2;
            if(inside(tx,ty,n))
                dist[i][j][1][tx][ty][1]=make_pair(1,0);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=1;k<4;k++)
            {
                for(int i1=0;i1<n;i1++)
                {
                    for(int j1=0;j1<n;j1++)
                    {
                        for(int k1=1;k1<4;k1++)
                        {
                            for(int i2=0;i2<n;i2++)
                            {
                                for(int j2=0;j2<n;j2++)
                                {
                                    for(int k2=1;k2<4;k2++)
                                    {
                                        if(dist[i1][j1][k1][i2][j2][k2]>make_pair(dist[i1][j1][k1][i][j][k].first+dist[i][j][k][i2][j2][k2].first,dist[i1][j1][k1][i][j][k].second+dist[i][j][k][i2][j2][k2].second))
                                            dist[i1][j1][k1][i2][j2][k2]=make_pair(dist[i1][j1][k1][i][j][k].first+dist[i][j][k][i2][j2][k2].first,dist[i1][j1][k1][i][j][k].second+dist[i][j][k][i2][j2][k2].second);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    pair<int,int> dp[n*n][4];
    int p=n*n-1;
    dp[p][1]=make_pair(0,0);
    dp[p][2]=make_pair(0,0);
    dp[p][3]=make_pair(0,0);
    for(int i=n*n-2;i>=0;i--)
    {
        int x1=poz[i].first,y1=poz[i].second,x2=poz[i+1].first,y2=poz[i+1].second;
        //printf("Iz %i %i do %i %i\n",x1,y1,x2,y2);
        for(int k=1;k<4;k++)
        {
            dp[i][k]=make_pair(INT_MAX,INT_MAX);
            for(int l=1;l<4;l++)
                dp[i][k]=min(dp[i][k],make_pair(dp[i+1][l].first+dist[x1][y1][k][x2][y2][l].first,dp[i+1][l].second+dist[x1][y1][k][x2][y2][l].second));
            //printf("Dist od %i %i do kraja: %i-%i\n",i,k,dp[i][k].first,dp[i][k].second);
        }
    }
    pair<int,int> res=min(dp[0][1],min(dp[0][2],dp[0][3]));
    printf("%i %i\n",res.first,res.second);
    return 0;
}