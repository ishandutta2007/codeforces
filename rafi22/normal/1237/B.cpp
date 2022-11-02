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

const bool multi=0;

int a[200007];
int pos[200007];
int b[200007];

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
        int n,ans=0,mn=inf;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pos[a[i]]=i;
        }
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=n;i>0;i--)
        {
            if(pos[b[i]]>mn) ans++;
            mn=min(pos[b[i]],mn);
        }
        cout<<ans;
    }

    return 0;
}