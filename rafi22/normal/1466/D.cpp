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

const bool multi=1;

int a[100007];
vector<int> G[100007];
int ile[100007];

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
        int n,u,v,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        set<pair<int,int>>s;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        for(int i=1;i<=n;i++)
        {
            ile[i]=sz(G[i])-1;
            if(sz(G[i])>1) s.insert({a[i],i});
        }
        cout<<sum<<" ";
        for(int i=2;i<n;i++)
        {
            pair<int,int> p=*(--s.end());
            sum+=p.st;
            s.erase(p);
            ile[p.nd]--;
            if(ile[p.nd]>0) s.insert(p);
            cout<<sum<<" ";
        }
        cout<<endl;
        for(int i=1;i<=n;i++) G[i].clear();
    }

    return 0;
}