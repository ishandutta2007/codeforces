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

int l[2007],r[2007];
int c[2007][2007];

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
        int n,m,k,a,ans=0;
        cin>>n>>m>>k;
        vector<pair<int,int>>vec;
        for(int i=1;i<=m;i++)
        {
            cin>>l[i]>>r[i];
            vec.pb({l[i]+r[i]-1,i});
        }
        sort(vec.begin(),vec.end());
        for(int i=1;i<=n;i++)
        {
            for(int j=sz(vec)-1;j>=0;j--) c[i][j]=c[i][j+1]+max(0LL,min(r[vec[j].nd],i)-max(l[vec[j].nd],i-k+1)+1);
        }
        for(int i=1;i<=n;i++)
        {
            if(i-k<0) continue;
            int act=0;
            for(int j=1;j<=m;j++) act+=max(0LL,min(r[j],i)-max(l[j],i-k+1)+1);
            int it=sz(vec)-1;
            for(int j=n;j>=i;j--)
            {
                while(it>=0&&abs(vec[it].st-(2*j-k-1))<abs(vec[it].st-(2*i-k-1)))
                {
                    int x=vec[it--].nd;
                    act-=max(0LL,min(r[x],i)-max(l[x],i-k+1)+1);
                }
                ans=max(ans,act+c[j][it+1]);
            }
        }
        cout<<ans;
    }

    return 0;
}