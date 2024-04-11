#include <bits/stdc++.h>

using namespace std;

char tab[1007][1007];
bool odw[1007][1007];
int dis[1007][1007];
deque <pair<int,int> > kolejka;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>tab[i][j];
            dis[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(tab[i+1][j]==tab[i][j]||tab[i-1][j]==tab[i][j]||tab[i][j+1]==tab[i][j]||tab[i][j-1]==tab[i][j])
            {
                odw[i][j]=1;
                dis[i][j]=0;
                kolejka.push_back(make_pair(i,j));
            }
        }
    }
    while(!kolejka.empty())
    {
        int x=kolejka[0].first;
        int y=kolejka[0].second;
        kolejka.pop_front();
        if(x==0||x>n||y==0||y>m) continue;
        if(!odw[x+1][y])
        {
            odw[x+1][y]=1;
            dis[x+1][y]=dis[x][y]+1;
            kolejka.push_back(make_pair(x+1,y));
        }
        if(!odw[x-1][y])
        {
            odw[x-1][y]=1;
            dis[x-1][y]=dis[x][y]+1;
            kolejka.push_back(make_pair(x-1,y));
        }
        if(!odw[x][y+1])
        {
            odw[x][y+1]=1;
            dis[x][y+1]=dis[x][y]+1;
            kolejka.push_back(make_pair(x,y+1));
        }
        if(!odw[x][y-1])
        {
            odw[x][y-1]=1;
            dis[x][y-1]=dis[x][y]+1;
            kolejka.push_back(make_pair(x,y-1));
        }
    }
    long long x,y,t;
    for(int i=0;i<q;i++)
    {
        cin>>x>>y>>t;
        if(tab[x][y]=='0')
        {
            if(dis[x][y]==-1)
            {
                cout<<0<<endl;
                continue;
            }
            if((t-dis[x][y])%2==1)
                cout<<1<<endl;
            else cout<<0<<endl;
        }
        else
        {
            if(dis[x][y]==-1)
            {
                cout<<1<<endl;
                continue;
            }
            if((t-dis[x][y])%2==1)
                cout<<0<<endl;
            else cout<<1<<endl;
        }
    }
    return 0;
}