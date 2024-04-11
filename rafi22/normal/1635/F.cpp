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
int inf=4000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int N=300007,pot=1<<19;

int x[N],w[N];
vector<pair<int,int>>V[N];
vector<pair<int,int>>Q[N];
int ans[N];

int dis(int i,int j)
{
    return abs(x[i]-x[j])*(w[i]+w[j]);
}

int seg[2*pot+7];

void ins(int v,int x)
{
    v+=pot-1;
    seg[v]=min(seg[v],x);
    while(v>1)
    {
        v/=2;
        seg[v]=min(seg[2*v],seg[2*v+1]);
    }
}
int que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(r<a||l>b) return inf;
    return min(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
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
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>x[i]>>w[i];
        vector<pair<int,int>>S;
        for(int i=1;i<=n;i++)
        {
            while(sz(S)>0&&S.back().st>=w[i])
            {
                V[i].pb({S.back().nd,dis(S.back().nd,i)});
                S.pop_back();
            }
            S.pb({w[i],i});
        }
        S.clear();
        for(int i=n;i>0;i--)
        {
            while(sz(S)>0&&S.back().st>=w[i])
            {
                V[S.back().nd].pb({i,dis(i,S.back().nd)});
                S.pop_back();
            }
            S.pb({w[i],i});
        }
        for(int i=1;i<=q;i++)
        {
            int l,r;
            cin>>l>>r;
            Q[r].pb({l,i});
        }
        for(int i=1;i<2*pot;i++) seg[i]=inf;
        for(int i=1;i<=n;i++)
        {
            for(auto x:V[i]) ins(x.st,x.nd);
            for(auto x:Q[i]) ans[x.nd]=que(1,x.st,i,1,pot);
        }
        for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
    }

    return 0;
}