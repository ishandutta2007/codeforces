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

map<vector<pair<int,int>>,int>ile;

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
        int n,k,a,ans=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            vector<pair<int,int>>fac,rev;
            int p=2,s=sqrt(a);
            while(p<=s&&a>1)
            {
                int l=0;
                while(a%p==0)
                {
                    l++;
                    a/=p;
                }
                l%=k;
                if(l!=0) fac.pb({l,p});
                p++;
            }
            if(a>1) fac.pb({1,a});
            for(auto x:fac) rev.pb({k-x.st,x.nd});
            ans+=ile[rev];
            ile[fac]++;
        }
        cout<<ans;
    }

    return 0;
}