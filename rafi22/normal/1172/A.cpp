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
int b[200007];
int pos[200007];

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
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
            pos[b[i]]=i;
        }
        bool ok=1;
        if(pos[1]==0) ok=0;
        for(int i=pos[1];i<=n;i++) if(b[i]!=i-pos[1]+1) ok=0;
        for(int i=1;i<pos[1];i++) if(b[i]!=0&&i>=b[i]-b[n]) ok=0;
        if(ok)
        {
            cout<<pos[1]-1;
            return 0;
        }
        int mx=0;
        for(int i=1;i<=n;i++) if(b[i]!=0) mx=max(mx,i-b[i]+1);
        cout<<n+mx;
    }

    return 0;
}