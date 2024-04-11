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

int x[207];

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
        memset(x,0,sizeof x);
        int n,k,a,b;
        cin>>n>>k;
        for(int i=1;i<=k;i++)
        {
            cin>>a>>b;
            x[a]=b;
            x[b]=a;
            x[min(a,b)]=max(a,b);
        }
        vector<int>v;
        for(int i=1;i<=2*n;i++) if(!x[i]) v.pb(i);
        for(int i=0;i<sz(v)/2;i++)
        {
            x[v[i]]=v[i+sz(v)/2];
            x[v[i+sz(v)/2]]=v[i];
        }
        int ans=0;
        for(int i=1;i<=2*n;i++)
        {
            if(x[i]<i)
            {
                for(int j=x[i]+1;j<i;j++) if(x[j]>i) ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}