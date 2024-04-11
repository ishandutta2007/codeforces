#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=20*(1<<19)+10;
int ans[N],mx[N],mi[N],bg[19*(1<<19)+5];
int go[2][19*(1<<19)+5],n,k,tot;
void insert(int x)
{
    int p=0;
    for(int i=k-1;i>=0;i--)
    {
        int b=(x>>i)&1;
        if(!go[b][p])go[b][p]=++tot;
        p=go[b][p];
    }
}
void work(int p,int B)
{
    if(B<0)
    {
        bg[p]=tot;
        ans[tot]=1<<(k+1);
        mx[tot]=mi[tot]=0;
        tot++;
        return;
    }
    if(go[0][p])work(go[0][p],B-1);
    if(go[1][p])work(go[1][p],B-1);
    int *ansp=ans+tot,*mxp=mx+tot,*mip=mi+tot,*anss[2],*mxs[2],*mis[2];
    for(int i=0;i<2;i++)if(go[i][p])anss[i]=ans+bg[go[i][p]],mxs[i]=mx+bg[go[i][p]],mis[i]=mi+bg[go[i][p]];
    int full=(1<<B)-1;
    for(int i=0;i<(1<<(B+1));i++)
    {
        ansp[i]=1<<(k+1);mxp[i]=-(1<<k);mip[i]=1<<(k+1);
        for(int j=0;j<2;j++)if(go[j][p])
        {
            mxp[i]=max(mxp[i],mxs[j][i&full]|(((i>>B)^j)<<B));
            mip[i]=min(mip[i],mis[j][i&full]|(((i>>B)^j)<<B));
            ansp[i]=min(ansp[i],anss[j][i&full]);
        }
        if(go[0][p]&&go[1][p])
        {
            if((i>>B)&1)ansp[i]=min(ansp[i],(1<<B)+mis[0][i&full]-mxs[1][i&full]);
            else ansp[i]=min(ansp[i],(1<<B)+mis[1][i&full]-mxs[0][i&full]);
        }
    }
    bg[p]=tot;
    tot+=1<<(B+1);
}
int main()
{
    scanf("%d%d",&n,&k);
    rep(i,n)
    {
        int x;
        scanf("%d",&x);
        insert(x);
    }
    tot=0;
    work(0,k-1);
    for(int i=0;i<(1<<k);i++)printf("%d%c",ans[bg[0]+i]," \n"[i==(1<<k)-1]);
    return 0;
}