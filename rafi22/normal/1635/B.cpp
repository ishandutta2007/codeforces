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

int a[200007];

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
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(a[i]>a[i-1]&&a[i]>a[i+1])
            {
                int j=i+2;
                bool b=0;
                while(j<n&&a[j]>a[j-1]&&a[j]>a[j+1])
                {
                    b=1;
                    ans++;
                    a[j-1]=max(a[j],a[j-2]);
                }
                if(!b)
                {
                    a[i+1]=a[i];
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }

    return 0;
}