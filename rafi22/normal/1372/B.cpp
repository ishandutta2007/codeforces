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
        int n,res=inf;
        cin>>n;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                res=i;
                break;
            }
        }
        if(res==inf) cout<<1<<" "<<n-1<<endl;
        else cout<<n/res<<" "<<n-n/res<<endl;
    }

    return 0;
}