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

int last[107];
pair<int,int> ans[107];

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
        int n,k,a;
        cin>>n>>k;
        vector<pair<pair<int,int>,int>>intervals;
        for(int i=1;i<=n*k;i++)
        {
            cin>>a;
            if(last[a]) intervals.pb({{i,last[a]},a});
            last[a]=i;
        }
        sort(intervals.begin(),intervals.end());
        set<pair<int,bool>>S;
        int mx=n/(k-1)+min(1LL,n%(k-1));
        for(auto x:intervals)
        {
            if(ans[x.nd].st) continue;
            S.insert({x.st.nd,0});
            S.insert({x.st.st,1});
            bool ok=1;
            int act=0;
            for(auto y:S)
            {
                if(y.nd) act--;
                else act++;
                if(act>mx) ok=0;
            }
            if(ok) ans[x.nd]={x.st.nd,x.st.st};
            else
            {
                S.erase({x.st.nd,0});
                S.erase({x.st.st,1});
            }
        }
        for(int i=1;i<=n;i++) cout<<ans[i].st<<" "<<ans[i].nd<<endl;
    }

    return 0;
}