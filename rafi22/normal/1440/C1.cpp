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

bool a[107][107];

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
        vector<pair<int,int>>o,t,h;
        for(int i=1;i<=n;i++)
        {
            string str;
            cin>>str;
            for(int j=1;j<=m;j++)
            {
                if(str[j-1]=='1') a[i][j]=1;
                else a[i][j]=0;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j])
                {
                    o.pb({i,j});
                    a[i][j]=0;
                    t.pb({i+1,j});
                    a[i+1][j]=!a[i+1][j];
                    if(j==m)
                    {
                        a[i+1][j-1]=!a[i+1][j-1];
                        h.pb({i+1,j-1});
                    }
                    else
                    {
                        a[i+1][j+1]=!a[i+1][j+1];
                        h.pb({i+1,j+1});
                    }
                }
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(a[n-1][j-1])
            {
                a[n-1][j-1]=0;
                a[n-1][j]=!a[n-1][j];
                a[n][j]=!a[n][j];
                o.pb({n-1,j-1});
                t.pb({n-1,j});
                h.pb({n,j});
            }
            if(a[n][j])
            {
                if(j==m)
                {
                    o.pb({n,j});
                    t.pb({n-1,j});
                    h.pb({n,j-1});
                    o.pb({n,j});
                    t.pb({n-1,j});
                    h.pb({n-1,j-1});
                    o.pb({n,j});
                    t.pb({n,j-1});
                    h.pb({n-1,j-1});
                }
                else
                {
                    a[n][j]=0;
                    a[n-1][j]=!a[n-1][j];
                    a[n-1][j+1]=!a[n-1][j+1];
                    o.pb({n,j});
                    t.pb({n-1,j});
                    h.pb({n-1,j+1});
                }
            }
        }
        cout<<o.size()<<endl;
        for(int i=0;i<o.size();i++)
        {
            cout<<o[i].st<<" "<<o[i].nd<<" "<<t[i].st<<" "<<t[i].nd<<" "<<h[i].st<<" "<<h[i].nd<<endl;
        }
    }

    return 0;
}