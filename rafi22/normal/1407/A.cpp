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

int a[1007];


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
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            cnt+=a[i];
        }

        if(cnt>n/2)
        {
            if((n/2)%2==0)
            {
                cout<<n/2<<endl;
                for(int i=1;i<=n/2;i++) cout<<1<<" ";
                cout<<endl;
            }
            else
            {
                cout<<n/2+1<<endl;
                for(int i=1;i<=n/2+1;i++) cout<<1<<" ";
                cout<<endl;
            }
        }
        else
        {
            cout<<n/2<<endl;
            for(int i=1;i<=n/2;i++) cout<<0<<" ";
            cout<<endl;
        }
    }

    return 0;
}