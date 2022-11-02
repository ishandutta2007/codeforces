#include <bits/stdc++.h>

//#define int long long
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

int a[1100007];
int x[1100007];
int p[1100007];
vector<int>vec[2][1100007];
int it[2][1100007];

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
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int j=19;j>=0;j--)
        {
            int last=0;
            memset(it,0,sizeof it);
            for(int i=0;i<=1100000;i++)
            {
                vec[0][i].clear();
                vec[1][i].clear();
                vec[0][i].resize(0);
                vec[1][i].resize(0);
            }
            vec[0][0].pb(0);
            for(int i=1;i<=n;i++)
            {
                if(!((1<<j)&a[i])) last=i;
                while(it[i%2][p[i]]<sz(vec[i%2][p[i]])&&vec[i%2][p[i]][it[i%2][p[i]]]<last) it[i%2][p[i]]++;
                if(it[i%2][p[i]]<sz(vec[i%2][p[i]])) ans=max(ans,i-vec[i%2][p[i]][it[i%2][p[i]]]);
                vec[i%2][p[i]].pb(i);
            }
            for(int i=1;i<=n;i++)
            {
                x[i]+=(1<<j)&a[i];
                p[i]=p[i-1]^x[i];
            }
        }
        cout<<ans;
    }

    return 0;
}