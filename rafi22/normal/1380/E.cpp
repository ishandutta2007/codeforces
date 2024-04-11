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

const bool multi=0;

int tower[200007];
int rep[200007];
vector <int> v[200007];

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
        int n,m,ans=0,last,a,b;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>tower[i];
            v[tower[i]].pb(i);
            rep[i]=i;
        }
        last=tower[1];
        for(int i=2;i<=n;i++)
        {
            if(tower[i]!=last)
            {
                last=tower[i];
                ans++;
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<m;i++)
        {
            cin>>a>>b;
            bool x=0;
            if(v[rep[a]].size()<v[rep[b]].size())
            {
                x=1;
                swap(a,b);
            }
            for(int j=0;j<v[rep[b]].size();j++)
            {
                if(tower[v[rep[b]][j]-1]==rep[a]) ans--;
                if(tower[v[rep[b]][j]+1]==rep[a]) ans--;
            }
            for(int j=0;j<v[rep[b]].size();j++)
            {
                tower[v[rep[b]][j]]=rep[a];
                v[rep[a]].pb(v[rep[b]][j]);
            }
            if(x) rep[b]=rep[a];
            cout<<ans<<endl;
        }

    }

    return 0;
}