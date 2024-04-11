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

int a[2007];
int pref[2007];

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
        for(int i=1;i<=n;i++) cin>>a[i];
        bool ok=0;
        for(int i=1;i<=n;i++) pref[i]=pref[i-1]^a[i];
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(pref[i]==(pref[j]^pref[i])&&pref[i]==(pref[n]^pref[j])) ok=1;
            }
        }
        for(int i=1;i<n;i++)
        {
            if(pref[i]==(pref[n]^pref[i])) ok=1;
        }
        if(ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}