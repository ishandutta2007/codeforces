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

int c[300007];
int ile[300007];

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
        int n,m,a;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            ile[a]++;
        }
        for(int i=1;i<=m;i++) cin>>c[i];
        multiset<int> s;
        for(int i=m;i>0;i--)
        {
            if(!s.empty())
            {
                int x=*(--s.end());
                if(c[i]<x)
                {
                    s.erase(s.find(x));
                    s.insert(c[i]);
                }
            }
            for(int j=0;j<ile[i];j++) s.insert(c[i]);
        }
        int ans=0;
        for(auto x:s) ans+=x;
        cout<<ans<<endl;
        for(int i=1;i<=m;i++) ile[i]=0;

    }

    return 0;
}