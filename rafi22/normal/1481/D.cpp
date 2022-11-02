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

char G[1007][1007];

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
            string s;
            cin>>s;
            for(int j=1;j<=n;j++)
            {
                G[i][j]=s[j-1];
            }
        }
        bool xd=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j&&(G[i][j]==G[j][i]||m%2))
                {
                    cout<<"YES"<<endl;
                    for(int l=0;l<=m;l++)
                    {
                        if(l%2) cout<<j<<" ";
                        else cout<<i<<" ";
                    }
                    cout<<endl;
                    xd=1;
                    break;
                }
            }
            if(xd) break;
        }
        if(xd) continue;
        for(int i=1;i<=n;i++)
        {
            int a=0,b=0,a1=0,b1=0;
            for(int j=1;j<=n;j++)
            {
                if(G[i][j]=='a') a=j;
                if(G[i][j]=='b') b=j;
            }
            for(int j=1;j<=n;j++)
            {
                if(G[j][i]=='a') a1=j;
                if(G[j][i]=='b') b1=j;
            }
            if(a&&a1)
            {
                cout<<"YES"<<endl;
                xd=1;
                if(m%4!=0)
                {
                    for(int j=0; j<m/2+1; j++)
                    {
                        if(j%2) cout<<i<<" ";
                        else cout<<a<<" ";
                    }
                }
                else
                {
                    for(int j=0; j<m/2+1; j++)
                    {
                        if(j%2) cout<<a<<" ";
                        else cout<<i<<" ";
                    }
                }
                for(int j=0;j<m/2;j++)
                {
                    if(j%2) cout<<i<<" ";
                    else cout<<a1<<" ";
                }
                cout<<endl;
                break;
            }
            if(b&&b1)
            {
                cout<<"YES"<<endl;
                xd=1;
                if(m%4!=0)
                {
                    for(int j=0; j<m/2+1; j++)
                    {
                        if(j%2) cout<<i<<" ";
                        else cout<<b<<" ";
                    }
                }
                else
                {
                    for(int j=0; j<m/2+1; j++)
                    {
                        if(j%2) cout<<b<<" ";
                        else cout<<i<<" ";
                    }
                }
                for(int j=0;j<m/2;j++)
                {
                    if(j%2) cout<<i<<" ";
                    else cout<<b1<<" ";
                }
                cout<<endl;
                break;
            }
        }
        if(xd) continue;
        cout<<"NO"<<endl;
    }

    return 0;
}