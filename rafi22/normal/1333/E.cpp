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

int ans[507][507];

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
        if(n<3)
        {
            cout<<-1;
            return 0;
        }
        int it=1;
        for(int i=1;i<=n-3;i++)
        {
            if(i%2) for(int j=1;j<=n;j++) ans[i][j]=it++;
            else for(int j=n;j>0;j--) ans[i][j]=it++;
        }
        if((n-3)%2==1)
        {
            ans[n-2][n]=it++;
            for(int i=1;i<n;i++) ans[n-2][i]=it++;
        }
        else
        {
            for(int i=1;i<n-1;i++) ans[n-2][i]=it++;
            ans[n-2][n]=it++;
            ans[n-2][n-1]=it++;
        }
        for(int i=n-1;i>1;i--) ans[n-1][i]=it++;
        for(int i=1;i<n;i++) ans[n][i]=it++;
        ans[n-1][n]=it++;
        ans[n][n]=it++;
        ans[n-1][1]=it++;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }


    return 0;
}