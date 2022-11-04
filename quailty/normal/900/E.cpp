#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
char str[MAXN];
struct Data
{
    int a,b;
    Data(int _a=0,int _b=0):a(_a),b(_b){}
    Data operator + (const Data &t)const
    {
        return Data(a+t.a,b+t.b);
    }
    bool operator < (const Data &t)const
    {
        return (a==t.a ? b>t.b : a<t.a);
    }
}dp[MAXN];
int go[MAXN][2],cnt[MAXN];
int main()
{
    int n,m;
    scanf("%d%s%d",&n,str+1,&m);
    for(int i=1;i<=n;i++)
        cnt[i]=cnt[i-1]+(str[i]=='?');
    for(int i=n;i>=1;i--)
    {
        if(str[i]!='b')go[i][0]=go[i+1][1]+1;
        if(str[i]!='a')go[i][1]=go[i+1][0]+1;
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        if(i>=m && go[i-m+1][0]>=m)
            dp[i]=max(dp[i],dp[i-m]+Data(1,cnt[i]-cnt[i-m]));
    }
    return 0*printf("%d\n",dp[n].b);
}