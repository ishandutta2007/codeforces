#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

vector<int>G[407];
int d[407][407];
deque<int>Q;
vector<int>dif[807];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        memset(d,-1,sizeof d);
        for(int i=1;i<=n;i++)
        {
            Q.pb(i);
            d[i][i]=0;
            while(!Q.empty())
            {
                int v=Q[0];
                Q.pop_front();
                for(auto u:G[v])
                {
                    if(d[i][u]==-1)
                    {
                        d[i][u]=d[i][v]+1;
                        Q.pb(u);
                    }
                }
            }
        }
        int ans;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ans=1;
                for(int l=1;l<=n;l++)
                {
                    if(l==i||l==j) continue;
                    if(abs(d[i][l]-d[j][l])>d[i][j]||d[i][j]%2!=abs(d[i][l]-d[j][l])%2) ans=0;
                    dif[d[i][l]-d[j][l]+d[i][j]].pb(l);
                }
                int last=i;
                for(int l=0;l<=2*d[i][j];l+=2)
                {
                    if(l!=0&&l!=d[i][j]*2&&sz(dif[l])==0) ans=0;
                    for(auto v:dif[l])
                    {
                        int ile=0;
                        if(d[i][v]+d[v][j]==d[i][j])
                        {
                            if(i==j) return 2137;
                            //if(i==4&&j==2) cout<<v<<endl;
                            if((d[i][v]-d[j][v])-(d[i][last]-d[j][last])!=2) ans=0;
                            for(auto u:G[v]) if(u==last) ile=1;
                            last=v;
                        }
                        else
                        {
                           // if(i==4&&j==2) cout<<v<<" "<<l<<endl;
                            for(auto u:G[v])
                            {
                                if(d[i][u]-d[j][u]==d[i][v]-d[j][v]&&d[i][v]-1==d[i][u]&&d[j][v]-1==d[j][u]) ile++;
                            }

                            //if(i==4&&j==2) cout<<v<<" "<<ile<<endl;
                        }
                        if(n>=300&&i==1&&j==1&&ile==0) return 7312;
                        ans=ans*ile%mod1;
                    }
                    dif[l].clear();
                    dif[l+1].clear();
                }
                cout<<ans<<" ";
            }
            cout<<endl;
        }

    }

    return 0;
}