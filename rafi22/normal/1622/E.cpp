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

bool is[17][10007];
int p[10007];
int res[10007];
int x[17];

vector<int>bucket[27];

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
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if(c=='1')is[i][j]=1;
                else is[i][j]=0;
            }
        }
        int ans=-inf;
        for(int s=0;s<1<<n;s++)
        {
            for(int i=2*n;i>=0;i--) bucket[i].clear();
            for(int j=1;j<=m;j++)
            {
                int d=0;
                for(int i=1;i<=n;i++)
                {
                    if(!is[i][j]) continue;
                    if((s&(1<<(i-1)))) d++;
                    else d--;
                }
                bucket[d+n].pb(j);
            }
            int it=m;
            for(int i=2*n;i>=0;i--)
            {
                for(auto c:bucket[i]) p[c]=it--;
            }
            int act=0;
            for(int i=1;i<=n;i++)
            {
                int c=0;
                for(int j=1;j<=m;j++) if(is[i][j]) c+=p[j];
                act+=abs(c-x[i]);
            }
            if(act>ans)
            {
                ans=act;
                for(int i=1;i<=m;i++) res[i]=p[i];
            }
        }
        for(int i=1;i<=m;i++) cout<<res[i]<<" ";
        cout<<endl;
    }

    return 0;
}