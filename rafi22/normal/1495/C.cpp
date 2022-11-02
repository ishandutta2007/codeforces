#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define double long double
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

char g[507][507];
char ans[507][507];


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
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>g[i][j];
                ans[i][j]=g[i][j];
            }
        }
            for(int i=1;i<=n;i++)
            {
                if(i%3==2&&n-i<=1) break;
                ans[i][1]='X';
            }
            if(m>1)
            {
                for(int i=1;i<=n;i++)
                {
                    if(i%3==2&&n-i<=1) break;
                    if(g[i][2]=='X'&&i%3==2)
                    {
                        ans[i][1]='.';
                        ans[i+1][1]='.';
                        ans[i+1][2]='X';
                    }
                    if(g[i][2]=='X'&&i%3==0)
                    {
                        ans[i][1]='.';
                        ans[i-1][1]='.';
                        ans[i-1][2]='X';
                    }
                }
            }

            for(int i=1;i<=n;i+=3)
            {
                for(int j=1;j<=m;j++)
                {
                    ans[i][j]='X';
                }
            }

            if(n%3==0)
            {
                bool was=0;
                int last=inf;
                for(int i=m;i>0;i--)
                {
                    if(g[n][i]=='X'&&last!=i+1) was=1;
                    if(was) ans[n][i]='X';
                    if(g[n-1][i]=='X')
                    {
                        was=0;
                        last=i;
                    }
                }
                if(was) ans[n-1][1]='X';
            }
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