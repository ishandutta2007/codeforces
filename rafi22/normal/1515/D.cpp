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

int ile[200007];

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
        int n,l,r,x,ans=0;
        cin>>n>>l>>r;
        vector<int>L,R;
        for(int i=1;i<=l;i++)
        {
            cin>>x;
            L.pb(x);
        }
        for(int i=1;i<=r;i++)
        {
            cin>>x;
            R.pb(x);
        }
        if(sz(L)<sz(R)) swap(L,R);
        for(auto x:L) ile[x]++;
        for(auto x:R)
        {
            if(ile[x]>0) ile[x]--;
            else ans++;
        }
        int xd=(sz(L)-sz(R))/2;
        for(int i=1;i<=n;i++)
        {
            while(xd>0&&ile[i]>1)
            {
                ile[i]-=2;
                xd--;
                ans++;
            }
        }
        ans+=2*xd;
        cout<<ans<<endl;
        for(int i=1;i<=n;i++) ile[i]=0;
    }

    return 0;
}