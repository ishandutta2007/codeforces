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

int a[207];

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
        int n,s=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            s+=a[i];
        }
        bool ok=0;
        for(int i=2;i<s;i++) if(s%i==0) ok=1;
        if(ok)
        {
            cout<<n<<endl;
            for(int i=1;i<=n;i++) cout<<i<<" ";
        }
        else
        {
            cout<<n-1<<endl;
            for(int i=1;i<=n;i++)
            {
                if(a[i]%2==1)
                {
                    for(int j=1;j<i;j++) cout<<j<<" ";
                    for(int j=i+1;j<=n;j++) cout<<j<<" ";
                    break;
                }
            }
        }
        cout<<endl;
    }

    return 0;
}