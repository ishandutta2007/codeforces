#include <bits/stdc++.h>

#define int long long
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

const bool multi=1;

int tab[107][107];
int DP[107][107];
int n,m;

int f(int sr)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x=sr+i+j-2;
            if(x>tab[i][j]) DP[i][j]=inf;
            else if(i==1&&j==1) DP[i][j]=tab[i][j]-x;
            else DP[i][j]=min(DP[i-1][j],DP[i][j-1])+tab[i][j]-x;
        }
    }
    return DP[n][m];
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
    for(int i=0;i<=100;i++)
    {
        DP[i][0]=inf;
        DP[0][i]=inf;
    }
    while(tt--)
    {
        cin>>n>>m;
        vector <int> v;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>tab[i][j];
                v.pb(tab[i][j]-i-j+2);
            }
        }
        int ans=inf;
        for(int i=0;i<v.size();i++)
        {
            ans=min(ans,f(v[i]));
            //cout<<v[i]<<" "<<f(v[i])<<endl;
        }
        cout<<ans<<endl;
    }

    return 0;
}