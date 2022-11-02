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

int a[100007];
set<int>pos[100007];

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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<int>v;
        a[n+1]=inf;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=a[i+1]) v.pb(a[i]);
        }
        for(int i=0;i<=n;i++) pos[i].insert(inf);
        for(int i=0;i<sz(v);i++) pos[v[i]].insert(i);

        int l1=0,l2=0,ans=0;
        for(int i=0;i<sz(v);i++)
        {
            if(l1==v[i]) ;
            else if(l2==v[i]) ;
            else
            {
                ans++;
                if(*pos[l1].upper_bound(i)<*pos[l2].upper_bound(i)) l2=v[i];
                else l1=v[i];
            }
        }
        cout<<ans;
    }

    return 0;
}