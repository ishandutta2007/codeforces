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

bool is[200007][67];
int ile[100007];
int sum[100007];
bool xd[67];

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,m,p;
        cin>>n>>m>>p;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<m;j++)
            {
                if(s[j]=='1') is[i][j+1]=1;
            }
        }
        vector<int> res;
        int ans=0;
        for(int l=0;l<40;l++)
        {
            int k=rand()*rand()%n+1;
            vector<int>v;
            for(int j=1;j<=m;j++) if(is[k][j]) v.pb(j);
            for(int i=1;i<=n;i++)
            {
                int msk=0;
                for(int j=0;j<sz(v);j++) if(is[i][v[j]]) msk+=(1<<j);
                msk=(1<<sz(v))-1-msk;
                ile[msk]++;
            }
            for(int i=0;i<(1<<sz(v));i++) sum[i]=ile[i];
            for(int i=0;i<sz(v);i++)
            {
                for(int j=0;j<(1<<sz(v));j++)
                {
                    if((j&(1<<i)))
                    {
                        sum[j]+=sum[j^(1<<i)];
                    }
                }
            }
            for(int i=0;i<(1<<sz(v));i++)
            {
                if(sum[i]>=n/2+n%2&&__builtin_popcountll((1<<sz(v))-1-i)>ans)
                {
                    ans=__builtin_popcountll((1<<sz(v))-1-i);
                    res.clear();
                    for(int j=0;j<sz(v);j++)
                    {
                        if(!(i&(1<<j))) res.pb(v[j]);
                    }
                }
                sum[i]=0;
                ile[i]=0;
            }
        }
       // cout<<ans<<endl;
        for(auto x:res) xd[x]=1;
        for(int i=1;i<=m;i++) cout<<xd[i];
    }

    return 0;
}