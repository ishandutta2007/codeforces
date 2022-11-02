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

int DP[100007];

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
        int n,k;
        cin>>n>>k;
        int sum=1;
        DP[0]=1;
        for(int i=1;i<=n;i++)
        {
            DP[i]=sum;
            sum=min(inf,2*sum);
        }
        if(k>DP[n])
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=n;)
        {
            for(int j=i;j<=n;j++)
            {
                if(k<=DP[n-j])
                {
                    for(int l=j;l>=i;l--) cout<<l<<" ";
                    i=j+1;
                    break;
                }
                k-=DP[n-j];
            }
        }
        cout<<endl;
    }

    return 0;
}