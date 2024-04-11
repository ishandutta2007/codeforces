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

int c[507][507];
int ans[1007];
int root[1007];
vector<pair<int,int>>p[5007];
vector<pair<int,int>>edge;


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
        int n,mx=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>c[i][j];
                if(i==j) ans[i]=c[i][i];
                else p[c[i][j]].pb({i,j});
            }
        }
        int it=n;
        for(int i=1;i<=n;i++) root[i]=i;
        for(int i=1;i<=5000;i++)
        {
            vector<vector<int>>neww;
            set<int>s1;
            for(auto x:p[i])
            {
                s1.insert(x.st);
                s1.insert(x.nd);
            }
            for(auto x:s1)
            {
                bool t=0;
                for(int j=0;j<sz(neww);j++)
                {
                    vector<int>a=neww[j];
                    bool ok=1;
                    for(auto b:a)
                    {
                        if(root[b]!=root[x]&&c[b][x]!=i) ok=0;
                    }
                    if(ok)
                    {
                        neww[j].pb(x);
                        t=1;
                        break;
                    }
                }
                if(!t)
                {
                    vector<int>lol;
                    lol.pb(x);
                    neww.pb(lol);
                }
            }
            for(auto a:neww)
            {
                set<int>s;
                for(auto b:a)
                {
                    s.insert(root[b]);
                }
                if(sz(s)>1)
                {
                    it++;
                    ans[it]=i;
                    for(auto x:s) edge.pb({x,it});
                    for(auto b:a) root[b]=it;
                }
            }
        }
        cout<<it<<endl;
        for(int i=1;i<=it;i++) cout<<ans[i]<<" ";
        cout<<endl<<it<<endl;
        for(auto x:edge) cout<<x.st<<" "<<x.nd<<endl;

    }

    return 0;
}