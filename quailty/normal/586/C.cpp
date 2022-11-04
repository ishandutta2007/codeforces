#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct person
{
    int v,d,p;
}s[4005];
bool run[4005];
int pre[4005],nxt[4005];
int ans[4005];
queue<int>q;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&s[i].v,&s[i].d,&s[i].p);
    for(int i=1;i<=n;i++)
        pre[i]=i-1;
    for(int i=1;i<=n;i++)
        nxt[i]=i+1;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(run[i])continue;
        ans[cnt++]=i;
        pre[nxt[i]]=0;
        while(!q.empty())q.pop();
        for(int rem=s[i].v,now=nxt[i];rem>0 && now<=n;now=nxt[now])
        {
            if(run[now])continue;
            s[now].p-=rem;
            rem--;
            if(s[now].p<0)
            {
                q.push(now);
                run[now]=1;
            }
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int now=nxt[u];now<=n;now=nxt[now])
            {
                if(run[now])continue;
                s[now].p-=s[u].d;
                if(s[now].p<0)
                {
                    q.push(now);
                    run[now]=1;
                }
            }
            nxt[pre[u]]=nxt[u];
            pre[nxt[u]]=pre[u];
        }
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
        printf("%d ",ans[i]);
    return 0;
}