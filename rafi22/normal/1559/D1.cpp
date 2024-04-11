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

int o[1007][2];
int s[1007][2];

int Find(int v,bool b)
{
    if(o[v][b]==v) return v;
    return Find(o[v][b],b);
}
void Union(int u,int v,bool b)
{
    if(s[u][b]<s[v][b])
    {
        o[u][b]=v;
        s[v][b]+=s[u][b];
    }
    else
    {
        o[v][b]=u;
        s[u][b]+=s[v][b];
    }
}


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
        int n,m1,m2;
        cin>>n>>m1>>m2;
        for(int i=1;i<=n;i++)
        {
            o[i][0]=i;
            o[i][1]=i;
            s[i][0]=1;
            s[i][1]=1;
        }
        while(m1--)
        {
            int u,v;
            cin>>u>>v;
            u=Find(u,0),v=Find(v,0);
            Union(u,v,0);
        }
        while(m2--)
        {
            int u,v;
            cin>>u>>v;
            u=Find(u,1),v=Find(v,1);
            Union(u,v,1);
        }
        vector<pair<int,int>>ans;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int u=Find(i,0),v=Find(j,0),u1=Find(i,1),v1=Find(j,1);
                if(u!=v&&u1!=v1)
                {
                    Union(u,v,0);
                    Union(u1,v1,1);
                    ans.pb({i,j});
                }
            }
        }
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x.st<<" "<<x.nd<<endl;
    }

    return 0;
}