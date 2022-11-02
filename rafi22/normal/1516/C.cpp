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

int a[107];
bool DP[200007];


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
        for(int i=1;i<=n;i++) cin>>a[i];
        DP[0]=1;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i];
            for(int j=200000;j>=0;j--)
            {
                if(DP[j]&&j+a[i]<=200000) DP[j+a[i]]=1;
            }
        }
        if(sum%2||!DP[sum/2]) cout<<0<<endl;
        else
        {
            cout<<1<<endl;
            while(true)
            {
                for(int i=1;i<=n;i++)
                {
                    if(a[i]%2)
                    {
                        cout<<i<<endl;
                        return 0;
                    }
                    a[i]/=2;
                }
            }
        }
    }
    return 0;
}