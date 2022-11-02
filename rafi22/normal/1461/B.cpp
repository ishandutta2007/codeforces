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

char ch[507][507];
int DP[507][507];

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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>ch[i][j];
                DP[i][j]=0;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int last=0;
            for(int j=1;j<=m;j++)
            {
                if(ch[i][j]=='.') last=j;
                int x=j-last;
                if(x&&x%2==0) x--;
                DP[i][j]=min(DP[i-1][j-1]+1,x/2+x%2);
                ans+=DP[i][j];
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}