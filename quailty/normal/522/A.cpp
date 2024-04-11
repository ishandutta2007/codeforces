#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
map<string,int>h;
int cnt=0,in[405],dp[405],G[405][405];
int get(string str)
{
    if(!h[str])
    {
        h[str]=++cnt;
    }
    return h[str];
}
void solve()
{
    queue<int>q;
    for(int i=1;i<=cnt;i++)
    {
        if(in[i]==0)
        {
            dp[i]=1;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int j=1;j<=cnt;j++)
        {
            if(G[t][j])
            {
                dp[j]=max(dp[j],dp[t]+1);
                G[t][j]=0;
                in[j]--;
                if(in[j]==0)
                {
                    q.push(j);
                }
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    string a,r,b;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>r>>b;
        for(int j=0;j<a.size();j++)
        {
            if(a[j]>='A'&&a[j]<='Z')
            {
                a[j]=a[j]-'A'+'a';
            }
        }
        for(int j=0;j<b.size();j++)
        {
            if(b[j]>='A'&&b[j]<='Z')
            {
                b[j]=b[j]-'A'+'a';
            }
        }
        G[get(a)][get(b)]=1;
        in[get(b)]++;
    }
    solve();
    int ans=0;
    for(int i=1;i<=cnt;i++)
    {
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}