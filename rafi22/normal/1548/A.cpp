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

bool is[200007];
set<int>G[200007];
int ans=0;

void upd(int v)
{
    if(is[v])
    {
        ans--;
        is[v]=0;
    }
    if(-(*G[v].begin())<=v)
    {
        ans++;
        is[v]=1;
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
        int n,m,a,b;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            G[a].insert(-b);
            G[b].insert(-a);
        }
        for(int i=1;i<=n;i++)
        {
            G[i].insert(0);
            upd(i);
        }
        int q;
        cin>>q;
        while(q--)
        {
            int t,a,b;
            cin>>t;
            if(t==1)
            {
                cin>>a>>b;
                G[a].insert(-b);
                G[b].insert(-a);
                upd(a);
                upd(b);
            }
            else if(t==2)
            {
                cin>>a>>b;
                G[a].erase(-b);
                G[b].erase(-a);
                upd(a);
                upd(b);
            }
            else cout<<ans<<endl;
        }
    }

    return 0;
}