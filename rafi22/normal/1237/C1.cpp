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

//pair<pair<int,int>,pair<int,int>>p[500007];
int x[50007];
int y[50007];
int z[50007];
bool odw[50007];

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
        for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>z[i];
        for(int i=1;i<=n;i++)
        {
            if(odw[i]) continue;
            int mn=inf,p=-1;
            for(int j=1;j<=n;j++)
            {
                if(odw[j]||j==i) continue;
                int d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]);
                if(d<mn)
                {
                    mn=d;
                    p=j;
                }
            }
            cout<<i<<" "<<p<<endl;
            odw[i]=1;
            odw[p]=1;
        }
    }

    return 0;
}