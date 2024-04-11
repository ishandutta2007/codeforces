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

int DP[127][127];
int DP1[127][127];

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
        int t,x,y;
        cin>>t>>x>>y;
        int k=t-x-y;
        if(k<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        memset(DP,0,sizeof DP);
        memset(DP1,0,sizeof DP1);
        DP[0][0]=k;
        DP1[0][0]=k+1;
        for(int i=0;i<120;i++)
        {
            for(int j=0;j<120;j++)
            {
                DP[i][j+1]+=DP[i][j]/2+DP[i][j]%2;
                DP[i+1][j]+=DP[i][j]/2;
                DP1[i][j+1]+=DP1[i][j]/2+DP1[i][j]%2;
                DP1[i+1][j]+=DP1[i][j]/2;
            }
        }
        if(DP[x][y]!=DP1[x][y]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}