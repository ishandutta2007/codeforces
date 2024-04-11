#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
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
        int n,q,l,p;
        cin>>n>>q;
        string s;
        cin>>s;
        s='#'+s;
        while(q--)
        {
            cin>>l>>p;
            int it=l,kon=inf;
            bool c=0;
            int poc=inf;
            for(int i=1;i<=n;i++)
            {
                if(s[i]==s[it])
                {
                    it++;
                    poc=min(poc,i);
                }
                if(it==p)
                {
                    kon=i;
                    break;
                }
            }
            if(kon-poc>p-l-1) c=1;
            bool ok=0;
            for(int i=kon+2-c;i<=n;i++) if(s[i]==s[p]) ok=1;
            if(ok) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

    }

    return 0;
}