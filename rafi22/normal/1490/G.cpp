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

int a[200007];
int pref[200007];
int mx[200007];

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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            pref[i]=pref[i-1]+a[i];
            mx[i]=max(mx[i-1],pref[i]);
        }
        while(m--)
        {
            int x;
            cin>>x;
            int ile=0;
            if(pref[n]<=0&&mx[n]<x) cout<<-1<<" ";
            else
            {
                if(mx[n]<x) ile=(x-mx[n])/pref[n]+min(1LL,(x-mx[n])%pref[n]);
                int l=1,r=n,sr;
                while(l<r)
                {
                    sr=(l+r)/2;
                    if(mx[sr]>=x-pref[n]*ile) r=sr;
                    else l=sr+1;
                }
                cout<<ile*n+l-1<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}