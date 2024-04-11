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

bool DP[1007];
int take[1007];

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
        cout<<2<<endl;
        if(n==2)
        {
            cout<<1<<" "<<2<<endl;
            continue;
        }
        cout<<n<<" "<<n-2<<endl;
        cout<<n-1<<" "<<n-1<<endl;
        for(int i=0;i<n-3;i++)
        {
            cout<<n-1-i<<" "<<n-3-i<<endl;
        }

    }

    return 0;
}