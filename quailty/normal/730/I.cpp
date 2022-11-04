#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=3005;
const int INF=0x3f3f3f3f;
pair<int,int>t[MAXN];
int usd[MAXN],dp[MAXN][MAXN];
vector<int>ch;
int main()
{
    int n,p,s;
    scanf("%d%d%d",&n,&p,&s);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i].first);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i].second);
    for(int i=1;i<=n;i++)
        ch.push_back(i);
    sort(ch.begin(),ch.end(),[](int a,int b){return t[a]>t[b];});
    for(int i=0;i<=n;i++)
        for(int j=0;j<=s;j++)
            dp[i][j]=-INF;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=s;j++)
        {
            if(i-j<=p)dp[i][j]=max(dp[i][j],dp[i-1][j]+t[ch[i-1]].first);
            else dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(j)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+t[ch[i-1]].second);
        }
    printf("%d\n",dp[n][s]);
    vector<int>pro,spo;
    int nowi=n,nowj=s;
    while(nowi>0)
    {
        if(nowj && dp[nowi][nowj]==dp[nowi-1][nowj-1]+t[ch[nowi-1]].second)
            spo.push_back(ch[nowi-1]),nowj--;
        else if(dp[nowi][nowj]==dp[nowi-1][nowj]+t[ch[nowi-1]].first)
            pro.push_back(ch[nowi-1]);
        nowi--;
    }
    for(int i=0;i<(int)pro.size();i++)
        printf("%d%s",pro[i],(i<(int)pro.size()-1 ? " " : "\n"));
    for(int i=0;i<(int)spo.size();i++)
        printf("%d%s",spo[i],(i<(int)spo.size()-1 ? " " : "\n"));
    return 0;
}