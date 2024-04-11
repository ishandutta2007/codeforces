#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const int MAXT=1000005;
const ll INF=(1LL<<60)-1;
int d[MAXN],f[MAXN],t[MAXN],c[MAXN];
int now[MAXN],id[MAXN];
ll arr[MAXT],dep[MAXT];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d%d",&d[i],&f[i],&t[i],&c[i]),id[i]=i;
    sort(id+1,id+m+1,[](int a,int b){return d[a]<d[b];});
    int cnt=0;
    ll sum=0;
    memset(now,-1,sizeof(now));
    for(int i=0,j=1;i<MAXT;i++)
    {
        while(j<=m && d[id[j]]<i)
        {
            if(!t[id[j]])
            {
                if(now[f[id[j]]]<0)
                {
                    now[f[id[j]]]=c[id[j]];
                    cnt++;
                    sum+=c[id[j]];
                }
                else if(now[f[id[j]]]>c[id[j]])
                {
                    sum-=now[f[id[j]]];
                    sum+=c[id[j]];
                    now[f[id[j]]]=c[id[j]];
                }
            }
            j++;
        }
        if(cnt<n)arr[i]=INF;
        else arr[i]=sum;
    }
    sort(id+1,id+m+1,[](int a,int b){return d[a]>d[b];});
    cnt=sum=0;
    memset(now,-1,sizeof(now));
    for(int i=MAXT-1,j=1;i>=0;i--)
    {
        while(j<=m && d[id[j]]>i)
        {
            if(!f[id[j]])
            {
                if(now[t[id[j]]]<0)
                {
                    now[t[id[j]]]=c[id[j]];
                    cnt++;
                    sum+=c[id[j]];
                }
                else if(now[t[id[j]]]>c[id[j]])
                {
                    sum-=now[t[id[j]]];
                    sum+=c[id[j]];
                    now[t[id[j]]]=c[id[j]];
                }
            }
            j++;
        }
        if(cnt<n)dep[i]=INF;
        else dep[i]=sum;
    }
    ll res=INF;
    for(int i=0;i+k-1<MAXT;i++)
        res=min(res,arr[i]+dep[i+k-1]);
    return 0*printf("%lld\n",(res<INF ? res : -1LL));
}