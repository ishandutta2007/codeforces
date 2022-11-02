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

bool b[100007];

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
        for(int i=1;i<=n;i++) cin>>b[i];
        if(b[1])
        {
            cout<<n+1<<" ";
            for(int i=1;i<=n;i++) cout<<i<<" ";
        }
        else if(!b[n])
        {
            for(int i=1;i<=n;i++) cout<<i<<" ";
            cout<<n+1<<" ";
        }
        else
        {
            bool ok=0;
            for(int i=2;i<=n;i++)
            {
                if(b[i]&&!b[i-1])
                {
                    ok=1;
                    for(int j=1;j<i;j++) cout<<j<<" ";
                    cout<<n+1<<" ";
                    for(int j=i;j<=n;j++) cout<<j<<" ";
                    break;
                }
            }
            if(!ok) cout<<-1;
        }
        cout<<endl;
    }

    return 0;
}