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

int a[200007];
int pref[200007];
vector<int>v1,v2;

int bs(int m)
{
    if(m<=0) return 0;
    int l=1,r=sz(v2),sr,res=inf;
    while(l<=r)
    {
        sr=(l+r)/2;
        if(pref[sr]>=m)
        {
            r=sr-1;
            res=sr;
        }
        else l=sr+1;
    }
    return res;
}

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
        v1.clear();
        v2.clear();
        int n,m,b,ans=inf;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            cin>>b;
            if(b==1) v1.pb(a[i]);
            else v2.pb(a[i]);
        }
        sort(v1.begin(),v1.end(),greater<int>());
        sort(v2.begin(),v2.end(),greater<int>());
        int sum=0;
        for(int i=0;i<sz(v2);i++)
        {
            pref[i+1]=pref[i]+v2[i];
        }
        for(int i=0;i<sz(v1);i++)
        {
            ans=min(ans,i+2*bs(m-sum));
            sum+=v1[i];
        }
        ans=min(ans,sz(v1)+2*bs(m-sum));
        if(ans==inf) cout<<-1<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}