#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=5005;
const int mod=1e9+7;
ll dp[nax][nax];

ll a[nax];

ll daj(int l,int r)
{
    if(l==0) return a[r];
    ll res=a[r]-a[l-1];
    if(res<0) res+=mod;
    if(res>=mod) res-=mod;
    return res;
}


int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
    int n; cin>>n;
    ll res=1;
    dp[1][0]=1;
    char pop; cin>>pop;
    for(int i=2;i<=n;i++)
    {
        char akt; cin>>akt;
        if(pop=='f')
        {
            for(int j=1;j<=n;j++) dp[i][j]=dp[i-1][j-1];
        }
        else if(pop=='s')
        {
            a[0]=dp[i-1][0];
            for(int j=1;j<=n;j++)
            {
                a[j]=(a[j-1]+dp[i-1][j]);
                if(a[j]>=mod) a[j]-=mod;
            }
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=daj(j,n);
            }
        }

        pop = akt;
    }
    ll sum=0;
    for(int i=0;i<=n;i++)
    {
        sum+=dp[n][i];
        if(sum>=mod) sum-=mod;
    }
    cout<<sum<<endl;
    return 0;
}