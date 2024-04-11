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
int x[207];
int y[207];
int d[207];
bool odw[207];
deque<int>q;

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
        int n,k,ans=-1;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
        for(int i=1;i<=n;i++)
        {
            bool b=1;
            for(int j=1;j<=n;j++) if(abs(x[i]-x[j])+abs(y[i]-y[j])>k) b=0;
            if(b) ans=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}