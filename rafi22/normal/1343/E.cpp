#include <bits/stdc++.h>

using namespace std;

int a,b,c;
vector <int> G[200007];
deque <pair<int,int> > kolejka;
bool odw[3][200007];
int dis[3][200007];
long long pref[200007];
long long price[200007];

void bfs(int x)
{
    if(x==0)
    {
        kolejka.push_back(make_pair(a,0));
        odw[x][a]=1;
    }
    else if(x==1)
    {
        kolejka.push_back(make_pair(b,0));
        odw[x][b]=1;
    }
    else
    {
        kolejka.push_back(make_pair(c,0));
        odw[x][c]=1;
    }
    int p,d;
    while(!kolejka.empty())
    {
        p=kolejka[0].first;
        d=kolejka[0].second;
        dis[x][p]=d;
        for(int i=0;i<G[p].size();i++)
        {
            if(!odw[x][G[p][i]])
            {
                kolejka.push_back(make_pair(G[p][i],d+1));
                odw[x][G[p][i]]=1;
            }
        }
        kolejka.pop_front();
    }
}

int main()
{
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
        int n,m;
        cin>>n>>m>>a>>b>>c;
        long long x;
        for(int i=0;i<m;i++) cin>>price[i];
        sort(price,price+m);
        for(int i=1;i<=m;i++)
        {
            pref[i]=pref[i-1]+price[i-1];
        }
        int u,v;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        bfs(0);
        bfs(1);
        bfs(2);
        int mini=1000000007,naj;
        long long ans=1000000000000000007;
        for(int i=1;i<=n;i++)
        {
            if(dis[1][i]+dis[0][i]+dis[2][i]<=m)
                ans=min(ans,pref[dis[1][i]]+pref[dis[1][i]+dis[0][i]+dis[2][i]]);
        }
        cout<<ans<<endl;
        for(int i=0;i<=m+3;i++)
        {
            G[i].clear();
            price[i]=0;
            pref[i]=0;
            dis[0][i]=0;
            dis[1][i]=0;
            dis[2][i]=0;
            odw[0][i]=0;
            odw[1][i]=0;
            odw[2][i]=0;
        }


    }
    return 0;
}