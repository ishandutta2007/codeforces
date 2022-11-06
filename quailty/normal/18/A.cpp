#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int x[3],y[3];
bool check()
{
    for(int i=0;i<3;i++)
    {
        int px[2],py[2];
        for(int j=0;j<2;j++)
        {
            px[j]=x[(i+2)%3]-x[(i+j)%3];
            py[j]=y[(i+2)%3]-y[(i+j)%3];
        }
        bool isok=1;
        for(int j=0;j<2;j++)if(!px[j] && !py[j])isok=0;
        if(isok && px[0]*px[1]+py[0]*py[1]==0)return 1;
    }
    return 0;
}
int main()
{
    for(int i=0;i<3;i++)
        scanf("%d%d",&x[i],&y[i]);
    if(check())return 0*printf("RIGHT");
    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++)
        {
            x[i]+=d[j][0];
            y[i]+=d[j][1];
            if(check())return 0*printf("ALMOST");
            x[i]-=d[j][0];
            y[i]-=d[j][1];
        }
    return 0*printf("NEITHER");
}