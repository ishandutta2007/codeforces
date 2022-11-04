#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1005;
const int MAXK=300005;
char s[MAXN][MAXN],e[MAXK][5];
int a[MAXK],b[MAXK],c[MAXK],d[MAXK];
ll cnt[2][MAXN][MAXN],sum[MAXN][MAXN],res[MAXK];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=k;i++)
        scanf("%d%d%d%d%s",&a[i],&b[i],&c[i],&d[i],e[i]);
    for(char _='a';_<='z';_++)
    {
        for(int t=0;t<2;t++)
            for(int i=0;i<=n+1;i++)
                for(int j=0;j<=m+1;j++)
                    cnt[t][i][j]=0;
        for(int i=1;i<=k;i++)
        {
            int t=(*e[i]>_);
            cnt[t][a[i]][b[i]]++;
            cnt[t][c[i]+1][b[i]]--;
            cnt[t][a[i]][d[i]+1]--;
            cnt[t][c[i]+1][d[i]+1]++;
        }
        for(int t=0;t<2;t++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    cnt[t][i][j]+=cnt[t][i][j-1]+cnt[t][i-1][j]-cnt[t][i-1][j-1];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cnt[s[i][j]>_][i][j]+=k-cnt[0][i][j]-cnt[1][i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                sum[i][j]=cnt[!(s[i][j]>_)][i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
        for(int t=0;t<2;t++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    cnt[t][i][j]+=cnt[t][i][j-1]+cnt[t][i-1][j]-cnt[t][i-1][j-1];
        for(int i=1;i<=k;i++)
        {
            ll tmp=sum[n][m];
            tmp-=sum[a[i]-1][b[i]-1]-sum[a[i]-1][d[i]]-sum[c[i]][b[i]-1]+sum[c[i]][d[i]];
            int t=!(*e[i]>_);
            tmp+=cnt[t][a[i]-1][b[i]-1]-cnt[t][a[i]-1][d[i]]-cnt[t][c[i]][b[i]-1]+cnt[t][c[i]][d[i]];
            res[i]+=tmp;
        }
    }
    ll now=(1LL<<62)-1;
    for(int i=1;i<=k;i++)
        now=min(now,res[i]);
    printf("%lld",now);
    return 0;
}