#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
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

int ans[5007];


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
        int n,m,sum=0,act=1000000000;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            ans[i]=i;
            sum+=(i-1)/2;
        }
        if(sum<m)
        {
            cout<<-1;
            return 0;
        }
        for(int i=n;i>0;i--)
        {
            if(sum-(i-1)/2>=m)
            {
                ans[i]=act;
                act-=n+3;
                sum-=(i-1)/2;
            }
            else
            {
                sum-=(i-1)/2;
                int x=0;
                while(true)
                {
                    if(sum+(i-1-x)/2==m)
                    {
                        ans[i]+=x;
                        break;
                    }
                    x++;
                }
                break;
            }
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    }

    return 0;
}