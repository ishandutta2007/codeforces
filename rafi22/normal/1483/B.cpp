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
int pre[100007];
int nx[100007];
int a[100007];

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
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n;i++)
        {
            pre[i+1]=i;
            nx[i]=i+1;
        }
        pre[1]=n;
        nx[n]=1;
        set<int>Q;
        for(int i=1;i<=n;i++) if(__gcd(a[i],a[pre[i]])==1) Q.insert(i);
        int ban=1;
        vector<int>ans;
       // for(auto x:Q) cout<<x<<" ";
       // cout<<endl;
        Q.insert(inf);
        while(sz(Q)>1)
        {
            int act=*Q.upper_bound(ban);
            ban=0;
            if(act==inf) ban=0;
            else
            {
                Q.erase(act);
                ans.pb(act);
                Q.erase(nx[act]);
                if(nx[act]==act) break;
                nx[pre[act]]=nx[act];
                pre[nx[act]]=pre[act];
                if(__gcd(a[nx[act]],a[pre[act]])==1) Q.insert(nx[act]);
                ban=nx[act];
            }
        }
        cout<<sz(ans)<<" ";
        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}