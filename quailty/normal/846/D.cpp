#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=505;
int a[MAXN][MAXN];
int x[MAXN*MAXN],y[MAXN*MAXN],t[MAXN*MAXN];
int main()
{
    int n,m,k,q;
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=1;i<=q;i++)
        scanf("%d%d%d",&x[i],&y[i],&t[i]);
    int tl=0,tr=1000000001;
    while(tl<tr)
    {
        int tm=(tl+tr)/2;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                a[i][j]=0;
        for(int i=1;i<=q;i++)
            if(t[i]<=tm)a[x[i]][y[i]]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        bool isok=0;
        for(int i=k;i<=n;i++)
            for(int j=k;j<=m;j++)
                isok|=(a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k]==k*k);
        if(isok)tr=tm;
        else tl=tm+1;
    }
    return 0*printf("%d\n",(tl>1000000000 ? -1 : tl));
}