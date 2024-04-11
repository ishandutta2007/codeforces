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
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        s='#'+s;
        int c0=0,c1=0;
        for(int i=2;i<=n;i++)
        {
            if(s[i]!=s[i-1])
            {
                if(s[i-1]=='0') c0++;
                else c1++;
            }
        }
        if(s[n]=='0') c0++;
        else c1++;
        if(b>=0) cout<<(a+b)*n<<endl;
        else cout<<a*n+(min(c0,c1)+1)*b<<endl;
    }

    return 0;
}