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

const bool multi=0;

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
        set<pair<int,int>>S;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            s='#'+s;
            int k=sz(s);
            int p1=1,p2=1;
            int h1=0,h2=0;
            for(int i=1;i<=k;i++)
            {
                h1=(h1+p1*s[i])%mod;
                h2=(h2+p2*s[i])%mod;
                p1=p1*131%mod;
                p2=p2*137%mod;
            }
            p1=1,p2=1;
            for(int i=1;i<=k;i++)
            {
                if(s[i]=='a')
                {
                    S.insert({(h1+1*p1)%mod,(h2+1*p2)%mod});
                    S.insert({(h1+2*p1)%mod,(h2+2*p2)%mod});
                }
                if(s[i]=='b')
                {
                    S.insert({(h1+(-1)*p1+mod)%mod,(h2+(-1)*p2+mod)%mod});
                    S.insert({(h1+1*p1)%mod,(h2+1*p2)%mod});
                }
                if(s[i]=='c')
                {
                    S.insert({(h1+(-1)*p1+2*mod)%mod,(h2+(-1)*p2+2*mod)%mod});
                    S.insert({(h1+(-2)*p1+2*mod)%mod,(h2+(-2)*p2+2*mod)%mod});
                }
                p1=p1*131%mod;
                p2=p2*137%mod;
            }
        }
        for(int i=1;i<=m;i++)
        {
            string s;
            cin>>s;
            s='#'+s;
            int k=sz(s);
            int p1=1,p2=1;
            int h1=0,h2=0;
            for(int i=1;i<=k;i++)
            {
                h1=(h1+p1*s[i])%mod;
                h2=(h2+p2*s[i])%mod;
                p1=p1*131%mod;
                p2=p2*137%mod;
            }
            if(S.count({h1,h2})) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}