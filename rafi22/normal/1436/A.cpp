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
        int n,m,a,sum=0;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            sum+=a;
        }
        if(sum==m) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}