#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
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

int ile[1000007];

signed main()
{
    mod=mod1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,m,k,ans=0,x,y;
        cin>>n>>m>>k;
        vector<pair<pair<int,int>,int>>Vx,Vy;
        set<int>SX;
        set<int>SY;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            SX.insert(x);
            Vx.pb({{x,2},0});
        }
        for(int i=1;i<=m;i++)
        {
            cin>>y;
            SY.insert(y);
            Vy.pb({{y,2},0});
        }
        for(int i=1;i<=k;i++)
        {
            cin>>x>>y;
            Vx.pb({{x,1},y});
            Vy.pb({{y,1},x});
        }
        sort(Vx.begin(),Vx.end());
        sort(Vy.begin(),Vy.end());
        int act=0;
        vector<int>xd;
        for(auto x:Vx)
        {
            if(x.st.nd==1&&!SX.count(x.st.st))
            {
                //cout<<"xddd"<<endl;
                ans+=act;
                act++;
                ans-=ile[x.nd];
                ile[x.nd]++;
                xd.pb(x.nd);
            }
            else
            {
                for(auto lol:xd) ile[lol]--;
                xd.clear();
                act=0;
            }
        }
        act=0;
        for(auto x:Vy)
        {
            if(x.st.nd==1&&!SY.count(x.st.st))
            {
                ans+=act;
                act++;
                ans-=ile[x.nd];
                ile[x.nd]++;
                xd.pb(x.nd);
            }
            else
            {
                for(auto lol:xd) ile[lol]--;
                xd.clear();
                act=0;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}