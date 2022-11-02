#include <bits/stdc++.h>

//#define int long long
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

int g[87][87];
int n,k,ans=mod;
vector<int>act;
vector<pair<int,int>>d[87][87];
bool is[87];

void bt(int j)
{
    if(j>k)
    {
        act.pb(1);
        for(auto x:act)
        {
            is[x]=1;
        //    cout<<x<<" ";
        }
       // cout<<endl;
        int xd=0;
        for(int i=1;i<sz(act);i++)
        {
            int c=-1,it=0;
            while(it<sz(d[act[i-1]][act[i]]))
            {
                if(!is[d[act[i-1]][act[i]][it].nd])
                {
                    c=d[act[i-1]][act[i]][it].st;
                    break;
                }
                it++;
            }
            if(c==-1)
            {
                xd=mod;
                break;
            }
            xd+=c;
        }
        for(auto x:act) is[x]=0;
        ans=min(ans,xd);
        act.pop_back();
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        act.pb(i);
        bt(j+2);
        act.pop_back();
    }
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
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>g[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int l=1;l<=n;l++)
                {
                    if(l!=i&&l!=j) d[i][j].pb({g[i][l]+g[l][j],l});
                }
                sort(d[i][j].begin(),d[i][j].end());
            }
        }
        act.pb(1);
        bt(3);
        cout<<ans;
    }

    return 0;
}