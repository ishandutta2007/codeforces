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

const bool multi=1;

const int N=1007;

int r[N];
int s[N];

int Find(int v)
{
    if(r[v]==v) return v;
    return r[v]=Find(r[v]);
}
void Union(int v,int u)
{
    v=Find(v),u=Find(u);
    if(u==v) return ;
    r[u]=v;
    s[v]+=s[u];
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
        int n,d;
        cin>>n;
        vector<pair<int,int>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d;
            V.pb({d,i});
        }
        for(int i=1;i<=n;i++)
        {
            r[i]=i;
            s[i]=1;
        }
        sort(all(V),greater<pair<int,int>>());
        for(auto v:V)
        {
            if(s[Find(v.nd)]!=1) continue;
            for(int i=0;i<v.st;i++)
            {
                cout<<"? "<<v.nd<<endl;
                int u;
                cin>>u;
                if(s[Find(u)]!=1)
                {
                    Union(u,v.nd);
                    break;
                }
                Union(u,v.nd);
            }
        }
        cout<<"! ";
        for(int i=1;i<=n;i++) cout<<Find(i)<<" ";
        cout<<endl;
    }

    return 0;
}