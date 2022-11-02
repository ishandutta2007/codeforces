#include <bits/stdc++.h>

//#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

vector<int>pos[17][300];
int n;
map<vector<int>,int>DP;
map<vector<int>,int>zkad;

int dfs(vector<int>v)
{
    if(DP[v]>0) return DP[v];
    vector<int>x(n,-1);
    int ans=1;
    zkad[v]=-1;
    for(int c='A';c<='Z';c++)
    {
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            x[i]=-1;
            for(auto a:pos[i][c])
            {
                if(a>v[i])
                {
                    x[i]=a;
                    break;
                }
            }
            if(x[i]==-1)
            {
                ok=0;
                break;
            }
        }
        if(ok)
        {
            DP[x]=dfs(x);
            if(DP[x]+1>ans)
            {
                ans=DP[x]+1;
                zkad[v]=c;
            }
        }
    }
    for(int c='a';c<='z';c++)
    {
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            x[i]=-1;
            for(auto a:pos[i][c])
            {
                if(a>v[i])
                {
                    x[i]=a;
                    break;
                }
            }
            if(x[i]==-1)
            {
                ok=0;
                break;
            }
        }
        if(ok)
        {
            DP[x]=dfs(x);
            if(DP[x]+1>ans)
            {
                ans=DP[x]+1;
                zkad[v]=c;
            }
        }
    }
    return DP[v]=ans;
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
        DP.clear(),zkad.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<200;j++) pos[i][j].clear();
            string s;
            cin>>s;
            for(int j=0;j<sz(s);j++)
            {
                pos[i][s[j]].pb(j);
            }
        }
        int ans=dfs(vector<int>(n,-1))-1;
        cout<<ans<<endl;
        vector<int>v(n,-1);
        while(true)
        {
            if(zkad[v]==-1) break;
            cout<<(char)zkad[v];
            vector<int>x(n,-1);
            for(int i=0; i<n; i++)
            {
                for(auto a:pos[i][zkad[v]])
                {
                    if(a>v[i])
                    {
                        x[i]=a;
                        break;
                    }
                }
            }
            v=x;
        }
        cout<<endl;
    }

    return 0;
}