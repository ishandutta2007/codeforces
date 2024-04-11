#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=4444;
const int inf=1e9;

int n,k;

int v[nax][nax];

int dp[nax][nax];
int pp[4444][4444];

int koszt(int lo,int hi)
{
    if(lo>hi) return 0;
    int res=pp[hi][hi];
    res-=pp[lo-1][hi]*2;
    res+=pp[lo-1][lo-1];
    return res/2;
}


void ini()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            pp[i][j]=v[i][j]+pp[i-1][j]+pp[i][j-1]-pp[i-1][j-1];
        }
    }
}


void reku(int pos,int lo,int hi,int aktlo,int akthi)
{
    if(aktlo>akthi) return ;
    int mid=(aktlo+akthi)/2;
    int wynik=0;
    dp[pos][mid]=inf;
    for(int j=lo;j<=min(mid,hi);j++)
    {
        if(dp[pos-1][j]+koszt(j+1,mid)<dp[pos][mid])
        {
            dp[pos][mid]=dp[pos-1][j]+koszt(j+1,mid);
            wynik=j;
        }
    }
    reku(pos,lo,wynik,aktlo,mid-1);
    reku(pos,wynik,hi,mid+1,akthi);
}

inline int getint(){
	char c;
	while((c=getchar())<'0'||c>'9'); return c-'0';}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           v[i][j]=getint();
        }
    }
    ini();
    for(int i=1;i<=n;i++) dp[0][i]=inf;
    for(int i=1;i<=k;i++)
    {
        reku(i,0,n,i,n);
        for(int j=0;j<=n;j++)
        {

            if(j<i)
            {
                dp[i][j]=inf;
                continue;
            }
            if(j==i)
            {
                dp[i][j]=0; continue;
            }
        }
    }
    cout<<dp[k][n];
    return 0;
}