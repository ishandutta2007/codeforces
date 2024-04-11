#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
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

vector<int>G[1007];
int ile[1007];
bool odw[1007];

int lca(int a,int b)
{
    cout<<"? "<<a<<" "<<b<<endl;
    int x;
    cin>>x;
    return x;
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
        int n,a,b;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
            ile[a]++;
            ile[b]++;
        }
        while(true)
        {
            int x=-1,y=-1;
            for(int i=1;i<=n;i++)
            {
                if(!odw[i]&&ile[i]==1)
                {
                    odw[i]=1;
                    x=i;
                    break;
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(!odw[i]&&ile[i]==1)
                {
                    odw[i]=1;
                    y=i;
                    break;
                }
            }
            if(y==-1)
            {
                for(int i=1;i<=n;i++)
                {
                    if(!odw[i]) x=i;
                }
                cout<<"! "<<x<<endl;
                return 0;
            }
            int l=lca(x,y);
            if(l==x)
            {
                cout<<"! "<<x<<endl;
                return 0;
            }
            if(l==y)
            {
                cout<<"! "<<y<<endl;
                return 0;
            }
            for(auto u:G[x]) ile[u]--;
            for(auto u:G[y]) ile[u]--;
        }

    }

    return 0;
}