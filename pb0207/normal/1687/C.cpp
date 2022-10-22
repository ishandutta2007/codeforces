#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,m;

int a[N],b[N];

long long s[N];

typedef pair<int,int> pii;
#define fs first
#define sd second

pii p[N];

int fa[N],vis[N];

int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

queue<int>q;

vector<int>g[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),g[i].clear();
        g[0].clear();
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)
            s[i]=s[i-1]+b[i]-a[i];
        for(int i=1;i<=m;i++)
            scanf("%d%d",&p[i].fs,&p[i].sd);
        sort(p+1,p+m+1);
        for(int i=0;i<=n+1;i++)
            fa[i]=i,vis[i]=0;
        for(int i=1;i<=m;i++)
        {
            auto [x,y]=p[i];
            g[x-1].push_back(y);
            g[y].push_back(x-1);
        }
        for(int i=0;i<=n;i++)
            if(!s[i])
                q.push(i),vis[i]=1,fa[find(i)]=find(i+1);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto v:g[x])
            {
                if(s[v]==0)
                {
                    int L=x,R=v;
                    if(L>R)
                        swap(L,R);
                    L++;
                    for(int i=find(L);i<=R;i=find(i))
                    {
                        fa[find(i)]=find(i+1);
                        s[i]=s[i-1];
                        q.push(i);
                    }
                }
            }
        }
        int ans=1;
        for(int i=1;i<=n;i++)
            ans&=!s[i];
        puts(ans?"YES":"NO");
    }
}