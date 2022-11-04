#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1000005;
const int MAXD=10000005;
int cnt[MAXD],s[MAXN],id[MAXN],res[MAXN];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        int f;
        scanf("%d",&f);
        cnt[f]++;
    }
    for(int i=1;i<=m;i++)
        scanf("%d",&s[i]);
    ll now=0;
    for(int i=0;i<MAXD;i++)
    {
        now+=k;
        now-=cnt[i];
        if(now<0)return 0*printf("-1");
    }
    for(int i=1;i<=m;i++)
        id[i]=i;
    for(int i=1;i<MAXD;i++)
        cnt[i]+=cnt[i-1];
    sort(id+1,id+m+1,[](int a,int b){return s[a]>s[b];});
    now=1LL*k*MAXD-cnt[MAXD-1];
    for(int ii=1,j=MAXD-1;ii<=m;ii++)
    {
        int i=id[ii];
        while(j>=s[i])now=min(now,1LL*k*(j+1)-cnt[j]),j--;
        if(now)res[++res[0]]=i,now--;
    }
    printf("%d\n",res[0]);
    for(int i=1;i<=res[0];i++)
        printf("%d ",res[i]);
    return 0;
}