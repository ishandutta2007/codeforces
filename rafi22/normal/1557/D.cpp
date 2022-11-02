#include <bits/stdc++.h>

#define int long long
#define ld long double
//#define double long double
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

vector<pair<int,int>>vec[300007];
pair<int,int> seg[8*300007];
int lazy[8*300007];
int pot=1;
unordered_map<int,int>pos;
int DP[300007];
int zkad[300007];
bool is[300007];

void push(int v)
{
    if(lazy[v]>seg[2*v].st) seg[2*v]={lazy[v],seg[v].nd};
    lazy[2*v]=max(lazy[2*v],lazy[v]);
    if(lazy[v]>seg[2*v+1].st) seg[2*v+1]={lazy[v],seg[v].nd};
    lazy[2*v+1]=max(lazy[2*v+1],lazy[v]);
}

void ins(int u,int a,int b,int l,int r,int v,int x)
{
    if(a<=l&&b>=r)
    {
        lazy[u]=max(lazy[u],v);
        if(v>seg[u].st) seg[u]={v,x};
        return ;
    }
    if(l>b||r<a) return ;
    push(u);
    ins(2*u,a,b,l,(l+r)/2,v,x);
    ins(2*u+1,a,b,(l+r)/2+1,r,v,x);
    seg[u]=max(seg[2*u],seg[2*u+1]);
}

pair<int,int> que(int u,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[u];
    if(l>b||r<a) return {0,0};
    push(u);
    return max(que(2*u,a,b,l,(l+r)/2),que(2*u+1,a,b,(l+r)/2+1,r));
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
        int n,m;
        cin>>n>>m;
        set<int>S;
        for(int i=0;i<m;i++)
        {
            int x,l,r;
            cin>>x>>l>>r;
            vec[x].pb({l,r});
            S.insert(l);
            S.insert(r);
        }
        pos.reserve(sz(S)+7);
        int it=0;
        for(auto x:S) pos[x]=++it;
        while(pot<it) pot*=2;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<sz(vec[i]);j++) vec[i][j]={pos[vec[i][j].st],pos[vec[i][j].nd]};
        }
        for(int i=1;i<=n;i++)
        {
            for(auto x:vec[i])
            {
                pair<int,int>p=que(1,x.st,x.nd,1,pot);
                if(p.st>DP[i])
                {
                    DP[i]=p.st;
                    zkad[i]=p.nd;
                }
            }
            DP[i]++;
            for(auto x:vec[i]) ins(1,x.st,x.nd,1,pot,DP[i],i);
        }
        int mx=0,p=-1;
        for(int i=1;i<=n;i++)
        {
            if(DP[i]>mx)
            {
                mx=DP[i];
                p=i;
            }
        }
        cout<<n-DP[p]<<endl;
        while(p>0)
        {
            is[p]=1;
            p=zkad[p];
        }
        for(int i=1;i<=n;i++) if(!is[i]) cout<<i<<" ";
    }

    return 0;
}