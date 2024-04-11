#include <bits/stdc++.h>

#define int long long
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

const bool multi=0;

const int N=10007;

bool is[N];
int a[107];
int d[N];
int D[25][25];
int DP[1<<21];

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
        int n,k,l,x;
        cin>>n>>k>>l;
        for(int i=1;i<=k;i++)
        {
            cin>>x;
            is[x]^=1;
            is[x+1]^=1;
        }
        vector<int>V;
        for(int i=1;i<=n+1;i++) if(is[i]) V.pb(i);
        for(int i=1;i<=l;i++) cin>>a[i];
        for(int i=0;i<sz(V);i++)
        {
            for(int j=1;j<=n+1;j++) d[j]=inf;
            deque<int>Q;
            Q.pb(V[i]);
            d[V[i]]=0;
            while(!Q.empty())
            {
                int v=Q[0];
                Q.pop_front();
                for(int j=1;j<=l;j++)
                {
                    if(v-a[j]>0&&d[v-a[j]]==inf)
                    {
                        d[v-a[j]]=d[v]+1;
                        Q.pb(v-a[j]);
                    }
                    if(v+a[j]<=n+1&&d[v+a[j]]==inf)
                    {
                        d[v+a[j]]=d[v]+1;
                        Q.pb(v+a[j]);
                    }
                }
            }
            for(int j=0;j<sz(V);j++) D[i][j]=d[V[j]];
        }
        int s=1<<sz(V);
        for(int i=1;i<s;i++) DP[i]=inf;
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<sz(V);j++)
            {
                if(!(i&(1<<j)))
                {
                    for(int l=j+1;l<sz(V);l++)
                    {
                        if(!(i&(1<<l)))
                        {
                            DP[i^(1<<j)^(1<<l)]=min(DP[i^(1<<j)^(1<<l)],DP[i]+D[j][l]);
                        }
                    }
                    break;
                }
            }
        }
        if(DP[s-1]==inf) cout<<-1;
        else cout<<DP[s-1];
    }

    return 0;
}