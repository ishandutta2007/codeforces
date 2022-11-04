#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
const int INF=0x3f3f3f3f;
char str[MAXN];
int dp[MAXN][2],rig[MAXN];
bool check(int n,int m,vector<int> &packman)
{
    int t=(int)packman.size();
    for(int i=0;i<t;i++)
    {
        int p=packman[i];
        if(i==0)
        {
            if(rig[0]<p)
            {
                if(p<=rig[0]+m)dp[i][0]=rig[p];
                else dp[i][0]=rig[0];
                dp[i][1]=rig[0];
            }
            else
            {
                dp[i][0]=rig[p];
                dp[i][1]=rig[min(n,p+m)];
            }
        }
        else
        {
            dp[i][0]=dp[i][1]=-INF;
            if(dp[i-1][0]<p)
            {
                if(p<=dp[i-1][0]+m)dp[i][0]=max(dp[i][0],rig[p]);
                else dp[i][0]=max(dp[i][0],dp[i-1][0]);
                dp[i][1]=max(dp[i][1],dp[i-1][0]);
            }
            else
            {
                dp[i][0]=max(dp[i][0],rig[p]);
                dp[i][1]=max(dp[i][1],rig[min(n,p+m)]);
            }

            int q=packman[i-1];
            if(dp[i-1][1]<q)
            {
                if(p<=dp[i-1][1]+m)dp[i][0]=max(dp[i][0],rig[min(n,m+q)]);
                dp[i][1]=max(dp[i][1],dp[i-1][1]);
            }
            else if(dp[i-1][1]<p)
            {
                if(p<=dp[i-1][1]+m)dp[i][0]=max(dp[i][0],rig[p]);
                else dp[i][0]=max(dp[i][0],dp[i-1][1]);
                dp[i][1]=max(dp[i][1],dp[i-1][1]);
            }
            else
            {
                dp[i][0]=max(dp[i][0],rig[p]);
                dp[i][1]=max(dp[i][1],rig[min(n,p+m)]);
            }
        }
    }
    return max(dp[t-1][0],dp[t-1][1])>n;
}
int main()
{
    int n;
    scanf("%d%s",&n,str+1);
    vector<int> asterisk,packman;
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='*')asterisk.push_back(i);
        if(str[i]=='P')packman.push_back(i);
    }
    if((int)packman.size()==1)
    {
        int cnt[2]={0,0};
        for(int i=0;i<(int)asterisk.size();i++)
            cnt[asterisk[i]>packman[0]]++;
        int dis[2]={packman[0]-asterisk.front(),asterisk.back()-packman[0]};
        if(cnt[0]>cnt[1])printf("%d %d\n",cnt[0],dis[0]);
        else if(cnt[0]<cnt[1])printf("%d %d\n",cnt[1],dis[1]);
        else printf("%d %d\n",cnt[0],min(dis[0],dis[1]));
        return 0;
    }
    for(int i=n,j=n+1;i>=0;i--)
    {
        rig[i]=j;
        if(str[i]=='*')j=i;
    }
    int l=1,r=n;
    while(l<r)
    {
        int m=(l+r)/2;
        if(check(n,m,packman))r=m;
        else l=m+1;
    }
    return 0*printf("%d %d\n",(int)asterisk.size(),l);
}