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

int DP[2007][2007][2][2];
int DP1[2007][2007][2][2];
bool a[2007][2];
bool b[2007][2];

void add(int i,int j,int c,int d,int x,int y)
{
    DP[i][j][c][d]=(DP[i][j][c][d]+x)%mod;
    DP1[i][j][c][d]=(DP1[i][j][c][d]+y)%mod;
}

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
        string x;
        cin>>n>>x;
        for(int i=1;i<=n;i++)
        {
            if(x[i-1]!='1') a[i][0]=1;
            if(x[i-1]!='0') a[i][1]=1;
        }
        cin>>x;
        for(int i=1;i<=n;i++)
        {
            if(x[i-1]!='1') b[i][0]=1;
            if(x[i-1]!='0') b[i][1]=1;
        }
        for(int x=0;x<2;x++) for(int y=0;y<2;y++) if(a[1][x]&&b[1][y]) DP[1][1][x][y]=1;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                for(int c=0;c<2;c++)
                {
                    for(int d=0;d<2;d++)
                    {
                        int t=DP[i][j][c][d],z=DP1[i][j][c][d];
                        if(c==d)
                        {
                            if(i==j)
                            {
                                if(i==n) ans=(ans+z)%mod;
                                for(int x=0;x<2;x++) for(int y=0;y<2;y++) if(a[i+1][x]&&b[i+1][y]) add(i+1,i+1,x,y,t,z);
                            }
                            else
                            {
                                for(int y=0;y<2;y++) if(b[i+1][y]) add(i+1,j,!c,y,t,z);
                            }
                        }
                        else
                        {
                            int e=(c^((j-i)%2));
                            if(a[j+1][e])
                            {
                                for(int y=0;y<2;y++) if(b[i+1][y]) add(i+1,j+1,d,y,t,z+(j+1-i)*t%mod);
                            }
                            if(a[j+1][!e]) add(i,j+1,c,d,t,z);
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<=n+1;i++)
        {
            for(int x=0;x<2;x++) a[i][x]=0;
            for(int x=0;x<2;x++) b[i][x]=0;
            for(int j=0;j<=n+1;j++)
            {
                for(int x=0;x<2;x++) for(int y=0;y<2;y++) DP[i][j][x][y]=0;
                for(int x=0;x<2;x++) for(int y=0;y<2;y++) DP1[i][j][x][y]=0;
            }
        }
    }

    return 0;
}