#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
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
        int x;
        string s;
        cin>>x>>s;
        s='#'+s;
        int ans=sz(s)-1;
        for(int i=1;i<=x;i++)
        {
            string c="";
            if(s[i]!='1')
            {
                for(int j=i+1;j<sz(s);j++)
                {
                    if(sz(s)+sz(c)>x) break;
                    c+=s[j];
                }
            }
            int sc=(ans-i+mod)%mod;
            ans=(ans+(s[i]-'1')*sc)%mod;
            for(int j=0;j<s[i]-'1';j++)
            {
                if(sz(s)>x) break;
                s+=c;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}