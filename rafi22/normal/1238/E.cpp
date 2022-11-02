#include <bits/stdc++.h>

//#define int long long
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

int cnt[27][27];
int DP[1100007];

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
        string str;
        cin>>str;
        for(int i=1;i<n;i++)
        {
            cnt[str[i]-'a'][str[i-1]-'a']++;
            cnt[str[i-1]-'a'][str[i]-'a']++;
        }
        for(int mask=1;mask<=1100000;mask++) DP[mask]=mod;
        for(int i=0;i<m;i++) DP[(1<<i)]=0;
        for(int mask=1;mask<(1<<m);mask++)
        {
            for(int i=0;i<m;i++)
            {
                if(((1<<i)&mask)==0)
                {
                    int act=0,pos=__builtin_popcount(mask);
                    for(int j=0;j<m;j++)
                    {
                        if(i==j) continue;
                        if(((1<<j)&mask)>0) act+=cnt[i][j]*pos;
                        else act-=cnt[i][j]*pos;
                    }
                    DP[mask+(1<<i)]=min(DP[mask+(1<<i)],DP[mask]+act);
                }
            }
        }
        cout<<DP[(1<<m)-1];


    }

    return 0;
}