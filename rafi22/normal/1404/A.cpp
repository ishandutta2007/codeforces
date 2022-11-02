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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        s='#'+s;
        bool ok=1;
        for(int i=1;i<=k;i++)
        {
            char z='?';
            for(int j=i;j<=n;j+=k)
            {
                if(s[j]!='?'&&z!='?'&&s[j]!=z) ok=0;
                else if(s[j]!='?') z=s[j];
            }
            for(int j=i;j<=n;j+=k) s[j]=z;
        }
        int c0=0,c1=0;
        for(int i=1;i<=k;i++)
        {
            if(s[i]=='0') c0++;
            if(s[i]=='1') c1++;
        }
        if(c0>k/2||c1>k/2) ok=0;
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}