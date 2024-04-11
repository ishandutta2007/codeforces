#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int MOD=(int)1e9+7;
const int N=200010;
int f[1<<17],pos[18][N],id[1<<17],nxt[20],mi[18][N],n,k;
char s[N];
bool check(int x)
{
    for(int i=n;i;i--)rep(j,k)pos[j][i]=i+x<=mi[j][i]?i+x:pos[j][i+1];
    rep(i,(1<<k)-1)f[i]=n+2;
    f[0]=1;
    for(int i=0;i<(1<<k)-1;i++)
    if(f[i]<=n)
    {
        int now=(~i)&((1<<k)-1);
        for(;now;now-=now&(-now))
        {
            int tmp=id[now&(-now)];
            f[i|(1<<(tmp-1))]=min(f[i|(1<<(tmp-1))],pos[tmp][f[i]]);
        }
    }
    return f[(1<<k)-1]<=n+1;
}
int main()
{
    scanf("%d%d",&n,&k);
    rep(i,k)id[1<<(i-1)]=i;
    scanf("%s",s+1);
    rep(i,k)nxt[i]=n+1,pos[i][n+1]=n+2;
    for(int i=n;i;i--)
    {
        if(s[i]!='?')nxt[s[i]-'a'+1]=i;
        int mi1=n+1,mi2=n+1;
        rep(j,k)if(nxt[j]<mi1)mi2=mi1,mi1=nxt[j];else if(nxt[j]<mi2)mi2=nxt[j];
        rep(j,k)mi[j][i]=nxt[j]==mi1?mi2:mi1;
    }
    int l=0,r=n/k+1;
    for(;l<r-1;)
    {
        int mid=(l+r)>>1;
        if(check(mid))l=mid;else r=mid;
    }
    printf("%d\n",l);
    return 0;
}