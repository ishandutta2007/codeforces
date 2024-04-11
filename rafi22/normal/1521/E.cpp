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

int ans[1007][1007];
int a[200007];
bool take[200007];

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
        vector<pair<int,int>>c;
        int m,k,mx=0;
        cin>>m>>k;
        for(int i=1;i<=k;i++)
        {
            cin>>a[i];
            if(a[i]>0) c.pb({a[i],i});
            mx=max(mx,a[i]);
        }
        sort(c.begin(),c.end());
        int n=1;
        while(n*n-(n/2)*(n/2)<m||mx>((n+1)/2)*((n+1)/2)+((n+1)/2)*(n/2)) n++;
        vector<int>color;
        int sum=0;
        for(auto x:c)
        {
            if(sum>=((n+1)/2)*(n/2)) break;
            sum+=x.st;
            color.pb(x.nd);
            take[x.nd]=1;
            if(sum>=((n+1)/2)*(n/2)) break;
        }
        reverse(color.begin(),color.end());
        for(int i=sz(color)-1;i>=0;i--)
        {
            if(sum-a[color[i]]>=((n+1)/2)*(n/2))
            {
                sum-=a[color[i]];
                take[color[i]]=0;
                color.pop_back();
            }
            else break;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ans[i][j]=0;
            }
        }
        for(int i=1;i<=n;i+=2)
        {
            for(int j=2;j<=n;j+=2)
            {
                ans[i][j]=color.back();
                a[color.back()]--;
                if(a[color.back()]==0) color.pop_back();
            }
        }
        color.clear();
        for(int i=1;i<=k;i++) if(!take[i]) while(a[i]-->0) color.pb(i);
        for(int i=1;i<=k;i++) if(take[i]) while(a[i]-->0) color.pb(i);
        for(int i=1;i<=n;i+=2)
        {
            for(int j=1;j<=n;j+=2)
            {
                if(sz(color)>0)
                {
                    ans[i][j]=color.back();
                    color.pop_back();
                }
            }
        }
        for(int i=2;i<=n;i+=2)
        {
            for(int j=1;j<=n;j+=2)
            {
                if(sz(color)>0)
                {
                    ans[i][j]=color.back();
                    color.pop_back();
                }
            }
        }
        if(sz(color)>0) return 2137;
        cout<<n<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=1;i<=k;i++) take[i]=0;
    }

    return 0;
}