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

int x[300007];
int y[300007];
int r[4];

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
        for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
        for(int i=1;i<=n;i++) if(r[0]==0||x[i]<x[r[0]]) r[0]=i;
        for(int i=1;i<=n;i++) if(r[1]==0||x[i]>x[r[1]]) r[1]=i;
        for(int i=1;i<=n;i++) if(r[2]==0||y[i]<y[r[2]]) r[2]=i;
        for(int i=1;i<=n;i++) if(r[3]==0||y[i]>y[r[3]]) r[3]=i;
        int ans=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(r[i]!=r[j])
                {
                    for(int k=1;k<=n;k++)
                    {
                        if(k!=r[i]&&k!=r[j])
                        {
                            int x0=min(min(x[r[i]],x[r[j]]),x[k]);
                            int x1=max(max(x[r[i]],x[r[j]]),x[k]);
                            int y0=min(min(y[r[i]],y[r[j]]),y[k]);
                            int y1=max(max(y[r[i]],y[r[j]]),y[k]);
                            ans=max(ans,2*(x1-x0)+2*(y1-y0));
                        }
                    }
                }
            }
        }
        cout<<ans<<" ";
        for(int i=4;i<=n;i++) cout<<2*(x[r[1]]-x[r[0]])+2*(y[r[3]]-y[r[2]])<<" ";
    }

    return 0;
}