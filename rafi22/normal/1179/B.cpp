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
        for(int i=1;i<=m/2;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<j<<" "<<i<<endl;
                cout<<n-j+1<<" "<<m-i+1<<endl;
            }
        }
        if(m%2)
        {
            for(int j=1;j<=n/2;j++)
            {
                cout<<j<<" "<<m/2+1<<endl;
                cout<<n-j+1<<" "<<m/2+1<<endl;
            }
            if(n%2) cout<<n/2+1<<" "<<m/2+1<<endl;
        }
    }

    return 0;
}