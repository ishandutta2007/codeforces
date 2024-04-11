#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define mp make_pair
#define pb push_back
#define mod 1000000007

int n,l[6],r[6];
double dp[35][11111],cur,cul[35][11111];

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    cin>>n;
    For(i,0,35) For(j,0,11111) {dp[i][j]=0.0;cul[i][j]=0.0;}
    For(i,0,n) cin>>l[i]>>r[i];
    For(i,0,n) For(j,l[i],r[i]+1) {dp[1<<i][j]=1.0/(r[i]+1-l[i]);}
    For(i,0,n) For(j,1,10011) cul[1<<i][j]=dp[1<<i][j]+cul[1<<i][j-1];
    //cout<<dp[1<<1][8];
    For(i,2,1<<n) For(j,1,1<<n) if((i|j)==i)
    {
        int jj=i^j;
        if(jj==0) continue;
        //if(i==2) cout<<j<<' '<<(i|j)<<endl;
        For(k,1,10011)
        {
            dp[i][k]=dp[j][k]*cul[jj][k]+dp[jj][k]*cul[j][k-1];
            cul[i][k]=cul[i][k-1]+dp[i][k];
        }
    }
    //cout<<dp[1<<1][8];
    double ans=0.0;
    For(i,0,n)
    {
        int k=(1<<i)^((1<<(n))-1);
        cur=0.0;
        For(j,1,10011)
        {
            cur+=(j-1)*dp[k][j-1];
            ans+=cur*dp[1<<i][j];
            //if(j==6) cout<<cur<<endl;
            //if(cur*dp[1<<i][j]) cout<<k<<' '<<i<<' '<<j<<' '<<cur*dp[1<<i][j]<<endl;
        }
        //cout<<ans<<endl;
    }
    //cout<<ans<<endl;
    For(i,1,10011) For(j,1,(1<<n)-1)
    {
        int b=0;
        For(jj,0,n) if(j&(1<<jj)) b++;
        if(b>=2)
        {
            cur=1.0*i;
            int k=j^((1<<(n))-1);
            cur*=cul[k][i-1];
            For(jj,0,n) if((1<<jj)&j) cur*=dp[1<<jj][i];
            ans+=cur;
        }
    }
    //cout<<ans<<endl;
    For(i,1,10011)
    {
        cur=1.0*i;
        For(j,0,n) cur*=dp[1<<j][i];
        ans+=cur;
    }
    printf("%.11f",ans);
    return 0;
}