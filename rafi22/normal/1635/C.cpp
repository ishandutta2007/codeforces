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

int a[200007];

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
        if(a[n]<a[n-1])
        {
            cout<<-1<<endl;
            continue;
        }
        bool zle=0;
        vector<pair<int,pair<int,int>>>ans;
        for(int i=n-2;i>0;i--)
        {
            if(a[i+1]-a[n]>a[i+1])
            {
                if(a[i]>a[i+1])
                {
                    zle=1;
                }
            }
            else
            {
                a[i]=a[i+1]-a[n];
                ans.pb({i,{i+1,n}});
            }
        }
        if(zle) cout<<-1<<endl;
        else
        {
            cout<<sz(ans)<<endl;
            for(auto x:ans) cout<<x.st<<" "<<x.nd.st<<" "<<x.nd.nd<<endl;
        }
    }

    return 0;
}