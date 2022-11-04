#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int query(int xl,int yl,int xr,int yr)
{
    printf("? %d %d %d %d\n",xl,yl,xr,yr);
    fflush(stdout);
    int res;
    scanf("%d",&res);
    return res;
}
vector<int> getRes(int xl,int yl,int xr,int yr)
{
    int l=xl,r=xr;
    while(l<r)
    {
        int m=(l+r+1)/2;
        if(query(m,yl,xr,yr)<1)r=m-1;
        else l=m;
    }
    xl=l;
    l=xl,r=xr;
    while(l<r)
    {
        int m=(l+r)/2;
        if(query(xl,yl,m,yr)<1)l=m+1;
        else r=m;
    }
    xr=l;
    l=yl,r=yr;
    while(l<r)
    {
        int m=(l+r+1)/2;
        if(query(xl,m,xr,yr)<1)r=m-1;
        else l=m;
    }
    yl=l;
    l=yl,r=yr;
    while(l<r)
    {
        int m=(l+r)/2;
        if(query(xl,yl,xr,m)<1)l=m+1;
        else r=m;
    }
    yr=l;
    return vector<int>{xl,yl,xr,yr};
}
int main()
{
    int n;
    scanf("%d",&n);
    int l=1,r=n-1;
    while(l<r)
    {
        int m=(l+r)/2;
        if(query(1,1,m,n)<1)l=m+1;
        else r=m;
    }
    if(l<n && query(1,1,l,n)==1 && query(l+1,1,n,n)==1)
    {
        vector<int>tmp[2]={getRes(1,1,l,n),getRes(l+1,1,n,n)};
        printf("!");
        for(int i=0;i<2;i++)
            for(int j=0;j<4;j++)
                printf(" %d",tmp[i][j]);
        fflush(stdout);
        return 0;
    }
    l=1,r=n-1;
    while(l<r)
    {
        int m=(l+r)/2;
        if(query(1,1,n,m)<1)l=m+1;
        else r=m;
    }
    vector<int>tmp[2]={getRes(1,1,n,l),getRes(1,l+1,n,n)};
    printf("!");
    for(int i=0;i<2;i++)
        for(int j=0;j<4;j++)
            printf(" %d",tmp[i][j]);
    fflush(stdout);
    return 0;
}