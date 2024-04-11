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

const bool multi=0;

bool DP[507][507];

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
        int n,k,a,b,sum=0,ans=0;
        cin>>n>>k;
        DP[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a>>b;
            sum+=a+b;
            for(int j=0;j<k;j++)
            {
                for(int l=0;l<k;l++)
                {
                    if(!DP[i-1][l]) continue;
                    int x;
                    if(l<=j) x=j-l;
                    else x=k-l+j;
                    if((a-x)%k==0||(a>=x&&(a-x)%k+b>=k)) DP[i][j]=1;
                }
            }
        }
        for(int i=0;i<k;i++)
        {

            if(DP[n][i]) ans=max(ans,(sum-i)/k);
        }
        cout<<ans;
    }

    return 0;
}