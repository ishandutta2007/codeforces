#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long double db;
db dp[2][2][255][256];
int mm[256];
int main()
{
    mm[0]=-1;
    for(int i=1;i<256;i++)
        mm[i]=mm[i-1]+((i&(i-1))==0);
    int x,k,tp;
    cin>>x>>k>>tp;
    db p=tp/100.0;
    int now=0,la=1;
    if(~x>>8&1)
    {
        int loc=0;
        for(int i=30;i>=8;i--)
            if(x>>i&1)loc=i-8;
        dp[now][0][loc][x%256]=1;
    }
    else
    {
        int cnt=0;
        for(int i=30;i>=8;i--)
            cnt=(x>>i&1 ? cnt+1 : 0);
        dp[now][1][cnt][x%256]=1;
    }
    for(int _=1;_<=k;_++)
    {
        swap(now,la);
        memset(dp[now],0,sizeof(dp[now]));
        for(int i=0;i<2;i++)
            for(int j=0;j<250;j++)
            {
                //mul 2
                for(int k=0;k<256;k++)
                {
                    if(i^(k<128))dp[now][i][j+1][k%128*2]+=dp[la][i][j][k]*p;
                    else dp[now][i^1][1][k%128*2]+=dp[la][i][j][k]*p;
                }
                //add 1
                for(int k=0;k<255;k++)
                    dp[now][i][j][k+1]+=dp[la][i][j][k]*(1-p);
                if(i==0)dp[now][1][1][0]+=dp[la][0][j][255]*(1-p);
                else dp[now][0][j][0]+=dp[la][1][j][255]*(1-p);
            }
    }
    db res=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<250;j++)
            for(int k=0;k<256;k++)
                res+=dp[now][i][j][k]*(k ? mm[k&-k] : 8+(i==0)*j);
    cout<<fixed<<setprecision(12)<<res<<endl;
    return 0;
}