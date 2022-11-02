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
int a[50],q[11],x[11][50],n,k;
void REJ(){puts("REJECTED");exit(0);}
void dfs(int now)
{
    if(now>k)
    {
        int x=0,y=0;
        rep(i,n)
        {
            if(a[i]==0&&(x||y))REJ();
            if(a[i]==-1&&(x||y))REJ();
            if(a[i]==1)y++;else if(a[i]==-1)x++;
        }
        return;
    }
    int cnt[2]={0,0};
    rep(i,q[now])if(a[x[now][i]]!=-1)cnt[a[x[now][i]]]++;
    int tmp[50];
    rep(i,n)tmp[i]=a[i];
    rep(i,cnt[0])a[x[now][i]]=0;
    for(int i=cnt[0]+1;i<=q[now];i++)a[x[now][i]]=1;
    for(int i=cnt[0];i<=q[now]-cnt[1];i++)
    {
        a[x[now][i]]=0;
        dfs(now+1);
    }
    rep(i,n)a[i]=tmp[i];
}
int main()
{
    scanf("%d%d",&n,&k);
    rep(i,k){scanf("%d",&q[i]);rep(j,q[i])scanf("%d",&x[i][j]);}
    rep(i,n)a[i]=-1;
    dfs(1);
    puts("ACCEPTED");
    return 0;
}