#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

vector<int>a[500007];
vector<char>ans[500007];
multiset<int>wez[500007];
unordered_map<int,int>M;
vector<pair<int,int>>G[500007];
bool odw[500007];

int c=0;
void edge(int u,int v)
{
    c++;
    G[u].pb({v,c});
    G[v].pb({u,c});
}
vector<int>V;
void euler(int v)
{
    while(sz(G[v])>0)
    {
        pair<int,int> u=G[v].back();
        G[v].pop_back();
        if(odw[u.nd]) continue;
        odw[u.nd]=1;
        euler(u.st);
    }
    V.pb(v);
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
        int m;
        cin>>m;
        set<int>S;
        for(int i=1;i<=m;i++)
        {
            int n;
            cin>>n;
            a[i].resize(n);
            ans[i].resize(n);
            for(int j=0;j<n;j++)
            {
                ans[i][j]='L';
                cin>>a[i][j];
                S.insert(a[i][j]);
            }
        }
        int it=0;
        for(auto x:S) M[x]=++it;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<sz(a[i]);j++)
            {
                edge(M[a[i][j]]+m,i);
            }
        }
        for(int i=1;i<=m+it;i++)
        {
            if(sz(G[i])%2==1)
            {
                cout<<"NO";
                return 0;
            }
        }
        for(int i=1;i<=m+it;i++)
        {
            if(sz(G[i])==0) continue;
            V.clear();
            euler(i);
            V.pop_back();
            for(int j=0;j<sz(V);j++)
            {
                if(V[j]<=m)
                {
                    wez[V[j]].insert(V[(j+1)%sz(V)]-m);
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<sz(a[i]);j++)
            {
                if(wez[i].count(M[a[i][j]]))
                {
                    ans[i][j]='R';
                    wez[i].erase(wez[i].find(M[a[i][j]]));
                }
            }
        }
        cout<<"YES"<<endl;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<sz(ans[i]);j++) cout<<ans[i][j];
            cout<<endl;
        }
    }

    return 0;
}