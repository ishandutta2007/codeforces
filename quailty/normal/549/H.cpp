#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db eps=1e-13;
int main()
{
    db a[4];
    for(int i=0;i<4;i++)
    {
        scanf("%lf",&a[i]);
    }
    db l=0.0,r=1e10;
    db p[4][2];
    db t[4][2];
    for(int _=1;_<=1000000;_++)
    {
        db m=(l+r)/2;
        for(int i=0;i<4;i++)
        {
            p[i][0]=a[i]-m;
            p[i][1]=a[i]+m;
        }
        for(int i=0;i<2;i++)
        {
            t[i][0]=p[i][0]*p[3-i][0];
            t[i][1]=p[i][0]*p[3-i][0];
            for(int j=0;j<=1;j++)
            {
                for(int k=0;k<=1;k++)
                {
                    t[i][0]=min(t[i][0],p[i][j]*p[3-i][k]);
                    t[i][1]=max(t[i][1],p[i][j]*p[3-i][k]);
                }
            }
        }
        if(t[0][1]<t[1][0] || t[1][1]<t[0][0])l=m;
        else r=m;
    }
    printf("%.13f\n",(l+r)/2);
    return 0;
}