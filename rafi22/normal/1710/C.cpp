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

int DP[200007][8][8];


signed main()
{
    mod=mod1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        string s;
        cin>>s;
        int n=sz(s);
        DP[0][0][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int x=0;x<8;x++)
            {
                for(int y=0;y<8;y++)
                {
                    for(int z=0;z<8;z++)
                    {
                        if(s[i]=='0')
                        {
                            if((y&1)==0&&(z&1)>0) continue;
                            if((y&2)==0&&(z&2)>0) continue;
                            if((y&4)==0&&(z&4)>0) continue;
                        }
                        int c=__builtin_popcount(z);
                        int X=x,Y=y;
                        if(s[i]=='1')
                        {
                            if((z&1)==0) Y|=1;
                            if((z&2)==0) Y|=2;
                            if((z&4)==0) Y|=4;
                        }
                        if(c==1||c==2)
                        {
                            int Z=z;
                            if(c==1) Z=7-Z;
                            if((Z&1)==0) X|=1;
                            if((Z&2)==0) X|=2;
                            if((Z&4)==0) X|=4;
                        }
                        DP[i+1][X][Y]=(DP[i+1][X][Y]+DP[i][x][y])%mod;
                    }
                }
            }
        }
        int ans=0;
        for(int y=0;y<8;y++) ans=(ans+DP[n][7][y])%mod;
        cout<<ans;
    }

    return 0;
}