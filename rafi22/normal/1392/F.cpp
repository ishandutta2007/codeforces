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

int h[1000007];

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
        int n,sum=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>h[i];
            h[i]-=i;
            sum+=h[i];
        }
        for(int i=0;i<n;i++)
        {
            if(i<sum%n) cout<<sum/n+1+i<<" ";
            else cout<<sum/n+i<<" ";
        }
    }

    return 0;
}