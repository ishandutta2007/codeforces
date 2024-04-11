#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2007;
long long int dp[nax];
int oferty[nax];
long long int suma[nax];

long long int ile(int l,int r)
{
    if(l==0) return suma[r];
    return suma[r]-suma[l-1];
}

int main()
{
    memset(oferty,0,sizeof oferty);
    int n,m,k; cin>>n>>m>>k;
    int * a=new int[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int * tab=new int [k+1];
    for(int i=1;i<=k;i++) tab[i]=a[i];
    for(int i=0;i<=k;i++) dp[i]=1e18;
    for(int i=0;i<m;i++)
    {
        int x,y; cin>>x>>y;
        if(x>=nax) continue;
        oferty[x]=max(oferty[x],y);
    }
    suma[0]=0;
    for(int i=1;i<=k;i++) suma[i]=suma[i-1]+tab[i];
    dp[0]=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(j>i) break;
            long long int koszt;
            koszt=ile(i-j+oferty[j]+1,i);
            dp[i]=min(dp[i],dp[i-j]+koszt);
        }
    }
    cout<<dp[k];
    return 0;
}