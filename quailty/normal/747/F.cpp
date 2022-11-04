#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=(1LL<<31)-1;
const char d[]="0123456789abcdef";
char s[255];
ll num[25],dp[20][255];
ll cal(ll n,ll k)
{
    if(k>n)return 0;
    ll res=1;
    for(int i=1;i<=k;i++)
    {
        res*=n-i+1;
        res/=i;
    }
    return min(INF,res);
}
ll work(int len,int on)
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0,d=15;i<16;i++,d--)
        for(int j=0;j<=len;j++)
            for(int k=0;k<=min(j*1LL,num[d]);k++)
                dp[i+1][j]=min(INF,dp[i+1][j]+cal(j-on*(d==0),k)*dp[i][j-k]);
    return dp[16][len];
}
int main()
{
    ll k,t;
    scanf("%lld%lld",&k,&t);
    k--;
    for(int i=0;i<16;i++)
        num[i]=t;
    int len=0;
    for(int i=1;;i++)
    {
        ll c=work(i,1);
        if(k<c)
        {
            len=i;
            break;
        }
        k-=c;
    }
    for(int i=0;i<len;i++)
    {
        for(int j=(i==0);j<16;j++)
        {
            num[j]--;
            ll c=work(len-i-1,0);
            if(k<c)
            {
                s[i]=d[j];
                break;
            }
            k-=c;
            num[j]++;
        }
    }
    return 0*printf("%s",s);
}