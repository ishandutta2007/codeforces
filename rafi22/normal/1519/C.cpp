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

int u[200007];
int s[200007];
vector<int>vec[200007];
vector<int>pref[200007];
int was[200007];

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
        int n,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>u[i];
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            sum+=s[i];
        }
        for(int i=1;i<=n;i++) vec[u[i]].pb(s[i]);
        for(int i=1;i<=n;i++) sort(vec[i].begin(),vec[i].end());
        vector<int>a;
        for(int i=1;i<=n;i++)
        {
            if(!was[sz(vec[i])])
            {
                was[sz(vec[i])]=i;
                a.pb(i);
                continue;
            }
            for(int j=0;j<sz(vec[i]);j++) vec[was[sz(vec[i])]][j]+=vec[i][j];
        }
        for(auto i:a)
        {
            pref[i].pb(0);
            for(auto x:vec[i]) pref[i].pb(pref[i].back()+x);
        }
        for(int j=1;j<=n;j++)
        {
            int sub=0;
            for(auto i:a) sub+=pref[i][sz(vec[i])%j];
            cout<<sum-sub<<" ";
        }
        cout<<endl;
        for(int i=0;i<=n;i++)
        {
            was[i]=0;
            pref[i].clear();
            vec[i].clear();
        }
    }

    return 0;
}