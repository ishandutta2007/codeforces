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

pair<int,int> h[200007];
int ans[200007];
int sum[200007];

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
        int n,m,x;
        cin>>n>>m>>x;
        for(int i=1;i<=n;i++)
        {
            cin>>h[i].st;
            h[i].nd=i;
        }
        sort(h+1,h+n+1,greater<pair<int,int>>());
        int it=1,xd=1;
        while(true)
        {
            if(xd%2)
            {
                for(int i=1;i<=m;i++)
                {
                    if(it>n) break;
                    ans[h[it].nd]=i;
                    sum[i]+=h[it].st;
                    it++;
                }
            }
            else
            {
                for(int i=m;i>0;i--)
                {
                    if(it>n) break;
                    ans[h[it].nd]=i;
                    sum[i]+=h[it].st;
                    it++;
                }
            }
            xd++;
            if(it>n) break;
        }
        int mx=0,mn=inf;
        for(int i=1;i<=m;i++)
        {
            mx=max(mx,sum[i]);
            mn=min(mn,sum[i]);
        }
        if(mx-mn>x) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
        for(int i=0;i<=m;i++) sum[i]=0;
    }

    return 0;
}