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

int a[200007];
int p[200007];

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
        int mx=-inf;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>mx)
            {
                mx=a[i];
                p[i]=i;
            }
            else p[i]=p[i-1];
        }
        vector<int> ans;
        int x=n;
        while(x>0)
        {
            for(int i=p[x];i<=x;i++) ans.pb(a[i]);
            x=p[x]-1;
        }
        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}