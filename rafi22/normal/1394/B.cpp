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

vector<pair<int,int>>G[200007];
vector<pair<int,int>>RG[200007];
bitset<100>bad;
bitset<100>ok[100];
int n,m,k,ans=0;
bitset<100>T;

void bt(int j)
{
    if(j==k+1)
    {
        ans++;
        return ;
    }
    for(int i=1;i<=j;i++)
    {
        bitset<100>S=(T&ok[j*(j-1)/2+i]);
        if(S.any()||bad[j*(j-1)/2+i]) continue;
        T[j*(j-1)/2+i]=1;
        bt(j+1);
        T[j*(j-1)/2+i]=0;
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
        cin>>n>>m>>k;
        for(int i=0;i<m;i++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            G[a].pb({w,b});
        }
        for(int i=1;i<=n;i++)
        {
            sort(G[i].begin(),G[i].end());
            for(int j=0;j<sz(G[i]);j++) G[i][j]={j+1,G[i][j].nd};
            for(auto u:G[i]) RG[u.nd].pb({sz(G[i]),u.st});
        }
        for(int i=1;i<=n;i++)
        {
            bitset<100>act;
            act.reset();
            for(auto x:RG[i])
            {
                if(act[x.st*(x.st-1)/2+x.nd]==1) bad[x.st*(x.st-1)/2+x.nd]=1;
                act[x.st*(x.st-1)/2+x.nd]=1;
            }
            for(int j=1;j<=k*(k+1)/2;j++)
            {
                if(act[j]==1) ok[j]=(ok[j]|act);
            }
        }
        bt(1);
        cout<<ans;
    }

    return 0;
}