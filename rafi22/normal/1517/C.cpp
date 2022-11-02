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
        int n,a;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            int x=i,y=i,c=a-1;
            ans[i][i]=a;
            while(c>0)
            {
               // cout<<x<<" "<<y<<endl;
                if(x>1&&ans[y][x-1]==0)
                {
                    x--;
                    ans[y][x]=a;
                   // cout<<x<<" "<<y<<endl;
                }
                else if(y<n&&ans[y+1][x]==0)
                {
                    y++;
                   // cout<<x<<" "<<y<<endl;
                    ans[y][x]=a;
                }
                else return 2137;
                c--;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}