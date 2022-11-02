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

int h[200007];

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
        vector<pair<int,int>>ans;
        int ls=n;
        for(int i=n-1;i>0;i--)
        {
            int sq=sqrt(ls);
            if(i>1&&i==sq)
            {
                ans.pb({n,i});
                ls=ls/i+min((int)1,ls%i);
            }
            if(i>2)
            {
                ans.pb({i,n});
            }
        }
        while(ls>1)
        {
            ans.pb({n,2});
            ls=ls/2+min((int)1,ls%2);
        }
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x.st<<" "<<x.nd<<endl;

    }

    return 0;
}