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
        char g[n+3][m+3];
        char ans[n+3][m+3];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>g[i][j];
            }
        }
        int L=0,R=min(n,m),sr,res=-1;
        while(L<=R)
        {
            sr=(L+R)/2;
            int l=2*sr+1;
            char act[n+3][m+3];
            int last[n+3][m+3];
            int last1[n+3][m+3];
            bool is[n+3][m+3];
            for(int j=m;j>0;j--) last[n+1][j]=inf;
            for(int i=n;i>0;i--)
            {
                int prev=inf;
                for(int j=m;j>0;j--)
                {
                    act[i][j]='.';
                    is[i][j]=0;
                    if(g[i][j]=='.') last[i][j]=i;
                    else last[i][j]=last[i+1][j];
                    if(last[i][j]<=i+l-1) prev=j;
                    if(i+l-1<=n&&j+l-1<=m&&prev>j+l-1)
                    {
                        is[i][j]=1;
                        act[i+sr][j+sr]='X';
                    }
                }
            }
            bool ok=1;
            for(int j=m; j>0; j--) last1[0][j]=-inf;
            for(int i=1; i<=n; i++)
            {
                int prev=-inf;
                for(int j=1; j<=m; j++)
                {
                    if(is[i][j]) last1[i][j]=i;
                    else last1[i][j]=last1[i-1][j];
                    if(last1[i][j]>=i-l+1) prev=j;
                    if(g[i][j]=='X'&&prev<j-l+1) ok=0;
                }
            }
            if(ok)
            {
                L=sr+1;
                res=sr;
                for(int i=1; i<=n; i++)
                {
                    for(int j=1; j<=m; j++)
                    {
                        ans[i][j]=act[i][j];
                    }
                }
            }
            else R=sr-1;
        }
        cout<<res<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }

    return 0;
}