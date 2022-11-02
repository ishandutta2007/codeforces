#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
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

int deg[1007];
int rep[1007];

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
        int n,d,x,y;
        cin>>n>>d;
        for(int i=1;i<=n;i++) rep[i]=i;
        int free=0;
        for(int i=1;i<=d;i++)
        {
            cin>>x>>y;
            int u=rep[x],v=rep[y];
            if(u==v) free++;
            else
            {
                if(deg[u]<deg[v]) swap(u,v);
                deg[u]+=deg[v]+1;
                deg[v]=0;
            }
            vector<int>vec;
            for(int j=1;j<=n;j++)
            {
                vec.pb(deg[j]);
               // cout<<deg[j]<<" ";
                if(rep[j]==v) rep[j]=u;
            }
           // cout<<endl;
            sort(all(vec),greater<int>());
            int ans=0;
            for(int i=0;i<free+1;i++) ans+=vec[i];
            cout<<ans+free<<endl;
        }
    }

    return 0;
}