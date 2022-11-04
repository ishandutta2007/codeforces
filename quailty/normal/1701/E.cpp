#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
const int INF=0x3f3f3f3f;
char s[MAXN],t[MAXN];
int dpl[2][MAXN],dpr[MAXN][MAXN];
int solve()
{
    int n,m;
    scanf("%d%d%s%s",&n,&m,s+1,t+1);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            dpr[i][j]=0;
            if(i)dpr[i][j]=max(dpr[i][j],dpr[i-1][j]/MAXN*MAXN);
            if(j)dpr[i][j]=max(dpr[i][j],dpr[i][j-1]/MAXN*MAXN);
            if(i && j && s[n+1-i]==t[m+1-j])
                dpr[i][j]=max(dpr[i][j],dpr[i-1][j-1]+MAXN+1);
        }
    if(dpr[n][m]/MAXN<m)return 0*printf("-1\n");
    int res=INF,now=0,la=1;
    for(int j=0;j<=m;j++)
        dpl[now][j]=0;
    for(int i=0;i<=n;i++)
    {
        swap(now,la);
        for(int j=0;j<=m;j++)
        {
            dpl[now][j]=0;
            if(i)dpl[now][j]=max(dpl[now][j],dpl[la][j]/MAXN*MAXN);
            if(j)dpl[now][j]=max(dpl[now][j],dpl[now][j-1]/MAXN*MAXN);
            if(i && j && s[i]==t[j])
                dpl[now][j]=max(dpl[now][j],dpl[la][j-1]+MAXN+1);
        }
        for(int j=0;j<=m;j++)
            if(dpl[now][j]/MAXN==j && dpr[n-i][m-j]/MAXN==m-j)
            {
                int cur=n-i-dpr[n-i][m-j]%MAXN;
                if(dpl[now][j]%MAXN<i)
                {
                    cur++; // home
                    cur+=i-dpl[now][j]%MAXN; // move
                    cur+=i-j; // delete
                }
                res=min(res,cur);
            }
    }
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}