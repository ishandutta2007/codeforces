#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int last[300007];
int maxi[300007];
vector<int> v[300007];

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
        int n,a;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            maxi[i]=-inf;
            last[i]=0;
            v[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            maxi[a]=max(maxi[a],i-last[a]-1);
            last[a]=i;
        }
        for(int i=1;i<=n;i++)
        {
            maxi[i]=max(maxi[i],n-last[i]);
        }
        int mini=inf;
        for(int i=1;i<=n;i++)
        {
            v[maxi[i]].pb(i);
        }
        for(auto u:v[0]) mini=min(mini,u);
        for(int i=1;i<=n;i++)
        {
            if(mini==inf) cout<<-1<<" ";
            else cout<<mini<<" ";
            for(auto u:v[i]) mini=min(mini,u);
        }
        cout<<endl;
    }

    return 0;
}