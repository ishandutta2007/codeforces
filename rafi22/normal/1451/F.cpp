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

int sum[10007];

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
        memset(sum,0,sizeof sum);
        int n,m,a;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a;
                sum[i+j]^=a;
            }
        }
        bool ans=0;
        for(int i=2;i<=n+m;i++) ans|=(sum[i]>0);
        if(ans) cout<<"Ashish"<<endl;
        else cout<<"Jeel"<<endl;
    }

    return 0;
}