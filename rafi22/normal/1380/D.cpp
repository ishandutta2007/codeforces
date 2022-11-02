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

const bool multi=0;

int a[200007];
int b[200007];
vector <pair<int,int> > v;

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
        int n,m,x,y,k,it=1,maxi=0;
        cin>>n>>m>>x>>k>>y;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>b[i];
        v.pb({0,0});
        for(int i=1;i<=n;i++)
        {
            if(a[i]==b[it])
            {
                v.pb({i,maxi});
                it++;
                maxi=0;
            }
            else maxi=max(maxi,a[i]);
        }
        v.pb({n+1,maxi});
        if(v.size()-2<m)
        {
            cout<<-1;
            return 0;
        }
        int ans=0;
        for(int i=1;i<v.size();i++)
        {
            int d=v[i].st-v[i-1].st-1;
            if(d<=0) continue;
            else if(d/k==0)
            {
                if(v[i].nd>a[v[i].st]&&v[i].nd>a[v[i-1].st])
                {
                    cout<<-1;
                    return 0;
                }
                ans+=d*y;
            }
            else
            {
                if(v[i].nd<a[v[i].st]||v[i].nd<a[v[i-1].st])
                    ans+=(d/k)*min(x,y*k)+(d%k)*y;
                else ans+=min((d/k)*x+(d%k)*y,x+(d-k)*y);
            }
        }
        cout<<ans;
    }

    return 0;
}