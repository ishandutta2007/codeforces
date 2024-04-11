#include <bits/stdc++.h>

//#define int long long
#define ll long long
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

int ile[5007];
int cnt[5007];
bool p[5007];
vector<pair<int,int>>F[5007];
vector<pair<int,int>>path[5007];
int act[5007];
vector<int>pr;

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
        for(int i=2;i<=5000;i++)
        {
            if(p[i]) continue;
            F[i].pb({i,1});
            pr.pb(i);
            for(int j=2*i;j<=5000;j+=i)
            {
                p[j]=1;
                int x=j,y=0;
                while(x%i==0)
                {
                    y++;
                    x/=i;
                }
                F[j].pb({i,y});
            }
        }
        reverse(pr.begin(),pr.end());
        int n,a;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            ile[a]++;
        }
        path[1].pb({1,0});
        for(int i=1;i<=5000;i++)
        {
            for(auto x:F[i]) cnt[x.st]+=x.nd;
            int last=0;
            for(auto p:pr)
            {
                if(cnt[p]>0)
                {
                    path[i].pb({p,last+cnt[p]});
                    last+=cnt[p];
                }
            }
        }
        int d=0;
        ll ans=0;
        set<int>active;
        for(int i=1;i<=5000;i++) active.insert(i);
        for(int i=1;i<=5000;i++) ans+=(ll)ile[i]*(ll)path[i].back().nd;
        while(true)
        {
            vector<int>rem;
            for(auto x:active)
            {
                if(path[x].back().nd==d) rem.pb(x);
                else if(path[x][act[x]].nd==d) act[x]++;
            }
            for(auto x:rem) active.erase(x);
            rem.clear();
            memset(cnt,0,sizeof cnt);
            for(auto x:active) cnt[path[x][act[x]].st]+=ile[x];
            bool is=0;
            for(auto p:pr)
            {
                if(cnt[p]>n-cnt[p])
                {
                    ans-=(ll)2*cnt[p]-n;
                    is=1;
                    for(auto x:active) if(path[x][act[x]].st!=p) rem.pb(x);
                    for(auto x:rem) active.erase(x);
                    break;
                }
            }
            if(!is) break;
            d++;
        }
        cout<<ans;
    }

    return 0;
}