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

int a[100007];
int b[100007];
int c[100007];
int is[100007];
int cnt1[100007];
int cnt2[100007];
vector<int>pos[100007];
int ans[100007];

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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=m;i++) cin>>c[i];
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=b[i])
            {
                cnt1[b[i]]++;
                pos[b[i]].pb(i);
            }
        }
        for(int i=1;i<=n;i++) is[b[i]]=i;
        for(int i=1;i<=m;i++) cnt2[c[i]]++;
        bool ok=1;
        for(int i=1;i<=n;i++) if(cnt1[i]>cnt2[i]) ok=0;
        if(!is[c[m]]) ok=0;
        if(ok)
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=m;i++)
            {
                if(!is[c[i]]) continue;
                else if(sz(pos[c[i]])>0)
                {
                    ans[i]=pos[c[i]].back();
                    pos[c[i]].pop_back();
                }
                else ans[i]=is[c[i]];
            }
            for(int i=1;i<=m;i++)
            {
                if(!is[c[i]]) ans[i]=ans[m];
            }
            for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
        for(int i=1;i<=n;i++)
        {
            cnt1[i]=0;
            cnt2[i]=0;
            is[i]=0;
            pos[i].clear();
            ans[i]=0;
        }
    }

    return 0;
}