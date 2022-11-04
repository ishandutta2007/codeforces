#include<bits/stdc++.h>
using namespace std;
const int MAXN=300005;
const int MAXM=8;
int a[MAXN][MAXM],idx[1<<MAXM];
pair<int,int> solve(int n,int m,int tm)
{
    for(int i=0;i<(1<<m);i++)
        idx[i]=0;
    for(int i=1;i<=n;i++)
    {
        int mask=0;
        for(int j=0;j<m;j++)
            mask|=(a[i][j]>=tm)<<j;
        idx[mask]=i;
    }
    for(int i=0;i<(1<<m);i++)
        for(int j=0;j<(1<<m);j++)
            if(idx[i] && idx[j] && (i|j)==(1<<m)-1)
                return {idx[i],idx[j]};
    return {0,0};
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    int tl=0,tr=1000000000;
    while(tl<tr)
    {
        int tm=(tl+tr+1)/2;
        pair<int,int> now=solve(n,m,tm);
        if(now.first)tl=tm;
        else tr=tm-1;
    }
    pair<int,int> res=solve(n,m,tl);
    printf("%d %d\n",res.first,res.second);
    return 0;
}