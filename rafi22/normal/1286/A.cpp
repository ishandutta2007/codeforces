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

const bool multi=0;

int a[107];
int DP[107][107][2];
bool is[107];

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
        int c=0,p=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            is[a[i]]=1;
            if(a[i]==0) c++;
        }
        for(int i=2;i<=n;i+=2) if(!is[i]) p++;
        //cout<<c<<" "<<p<<endl;
        for(int i=0;i<=n;i++) for(int j=0;j<=n+1;j++) DP[i][j][0]=inf;
        for(int i=0;i<=n;i++) for(int j=0;j<=n+1;j++) DP[i][j][1]=inf;
        DP[0][p][0]=0;
        DP[0][p][1]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=c;j++)
            {
                if(a[i]==0)
                {
                    DP[i][j][0]=min(DP[i-1][j+1][0],DP[i-1][j+1][1]+1);
                    DP[i][j][1]=min(DP[i-1][j][0]+1,DP[i-1][j][1]);
                }
                else
                {
                    bool b=a[i]%2;
                    DP[i][j][b]=min(DP[i-1][j][b],DP[i-1][j][!b]+1);
                }
            }
        }
        cout<<min(DP[n][0][0],DP[n][0][1]);
    }

    return 0;
}