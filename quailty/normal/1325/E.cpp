#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int MAXA=1000005;
const int MAXS=1005;
const int INF=0x3f3f3f3f;
int a[MAXN];
vector<int> e[MAXA];
int calc(int x)
{
    int res=1;
    for(int i=2;i*i<=x;i++)if(x%i==0)
    {
        int cnt=0;
        while(x%i==0)x/=i,cnt++;
        if(cnt&1)res*=i;
    }
    if(x>1)res*=x;
    return res;
}
int inq[MAXA],dis[MAXA];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),a[i]=calc(a[i]);
    sort(a+1,a+n+1);
    if(a[1]==1)return 0*printf("1\n");
    if(unique(a+1,a+n+1)-(a+1)<n)return 0*printf("2\n");
    vector<int> val;
    for(int i=1;i<=n;i++)
    {
        vector<int> p;
        for(int j=2;j*j<=a[i];j++)if(a[i]%j==0)
        {
            p.push_back(j);
            while(a[i]%j==0)a[i]/=j;
        }
        if(a[i]>1)p.push_back(a[i]);
        while((int)p.size()<2)p.push_back(1);
        int u=p[0],v=p[1];
        e[u].push_back(v);
        e[v].push_back(u);
        val.push_back(u);
        val.push_back(v);
    }
    sort(val.begin(),val.end());
    val.erase(unique(val.begin(),val.end()),val.end());
    int res=INF;
    for(int i=1;i<MAXS;i++)
    {
        if(e[i].empty())continue;
        for(auto &u:val)
            inq[u]=0,dis[u]=INF;
        queue<int> q;
        q.push(i);
        inq[i]=1,dis[i]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            inq[u]=0;
            for(auto &v:e[u])
            {
                if(dis[v]>dis[u]+1)
                {
                    inq[v]=1;
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
                else if(inq[v])
                    res=min(res,dis[u]+dis[v]+1);
            }
        }
    }
    return 0*printf("%d\n",(res<INF ? res : -1));
}