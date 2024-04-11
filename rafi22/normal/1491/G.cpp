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

int p[200007],pos[200007];
vector<int>cycle[200007];
bool odw[200007];
vector<pair<int,int>>ans;

void go(int v,int c)
{
    if(odw[v]) return;
    odw[v]=1;
    if(p[v]!=v) cycle[c].pb(v);
    go(p[v],c);
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
            pos[p[i]]=i;
        }
        int c=0,free=-1;
        for(int i=1;i<=n;i++)
        {
            if(odw[i]) continue;
            go(i,++c);
            if(sz(cycle[c])==0)
            {
                c--;
                free=pos[i];
            }
        }
        for(int i=2;i<=c;i+=2)
        {
            ans.pb({pos[cycle[i-1][0]],pos[cycle[i][0]]});
            for(int j=1;j<sz(cycle[i-1]);j++) ans.pb({pos[cycle[i][0]],pos[cycle[i-1][j]]});
            for(int j=1;j<sz(cycle[i]);j++) ans.pb({pos[cycle[i-1][0]],pos[cycle[i][j]]});
            ans.pb({pos[cycle[i-1][0]],pos[cycle[i][0]]});
            free=cycle[i-1][0];
        }
        if(c%2)
        {
            if(free>0)
            {
                for(int j=0;j<sz(cycle[c]);j++) ans.pb({pos[cycle[c][j]],free});
                ans.pb({pos[cycle[c][0]],free});
            }
            else
            {
                ans.pb({pos[cycle[c][0]],pos[cycle[c][1]]});
                ans.pb({pos[cycle[c][1]],pos[cycle[c][2]]});
                ans.pb({pos[cycle[c][2]],pos[cycle[c][0]]});
                for(int j=3;j<sz(cycle[c]);j++) ans.pb({pos[cycle[c][1]],pos[cycle[c][j]]});
                ans.pb({pos[cycle[c][1]],pos[cycle[c][0]]});
            }
        }
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x.st<<" "<<x.nd<<endl;
    }

    return 0;
}