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

int ans[200007];

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
        for(int i=1;i<=n;i++) ans[i]=m/n;
        int x=m%n;
        bool ok=1;
        if(m<n) ok=0;
        if(n%2==1) ans[n]+=x;
        else
        {
            if(x%2==0)
            {
                ans[n]+=x/2;
                ans[n-1]+=x/2;
            }
            else ok=0;
        }
        if(ok)
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
        else cout<<"No"<<endl;
    }

    return 0;
}