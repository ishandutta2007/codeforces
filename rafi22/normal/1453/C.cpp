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

vector<int>col[10][2007];
vector<int>row[10][2007];

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
        int n,l;
        cin>>n;
        char ch;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>ch;
                l=ch-'0';
                col[l][j].pb(i);
                row[l][i].pb(j);
            }
        }
        for(int i=0;i<10;i++)
        {
            int ans=0;
            for(int j=1;j<=n;j++)
            {
                if(row[i][j].size()>1)
                {
                    int p=row[i][j].back()-row[i][j][0];
                    ans=max(ans,(j-1)*p);
                    ans=max(ans,(n-j)*p);
                }
            }
            for(int j=1;j<=n;j++)
            {
                if(col[i][j].size()>1)
                {
                    int p=col[i][j].back()-col[i][j][0];
                    ans=max(ans,(j-1)*p);
                    ans=max(ans,(n-j)*p);
                }
            }
            int rmx=0,rmn=n+1,cmx=0,cmn=n+1;
            for(int j=1;j<=n;j++)
            {
                if(row[i][j].size()>0)
                {
                    rmx=max(rmx,j);
                    rmn=min(rmn,j);
                }
            }
            for(int j=1;j<=n;j++)
            {
                if(col[i][j].size()>0)
                {
                    cmx=max(cmx,j);
                    cmn=min(cmn,j);
                }
            }
            for(int j=1;j<=n;j++)
            {
                for(auto x:row[i][j])
                {
                    int p=max(x-1,n-x);
                    ans=max(ans,(j-rmn)*p);
                    ans=max(ans,(rmx-j)*p);
                }
            }
            for(int j=1;j<=n;j++)
            {
                for(auto x:col[i][j])
                {
                    int p=max(x-1,n-x);
                    ans=max(ans,(j-cmn)*p);
                    ans=max(ans,(cmx-j)*p);
                }
            }
            cout<<ans<<" ";
        }
        cout<<endl;
        for(int i=0;i<10;i++)
        {
            for(int j=1;j<=n;j++)
            {
                row[i][j].clear();
                col[i][j].clear();
            }
        }
    }

    return 0;
}