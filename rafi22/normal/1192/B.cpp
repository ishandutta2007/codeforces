#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ll long long
ll mod=1000000007;
int inf=1000000007;
ll infl=1000000000000000007;

const int N=100007,pot=1<<17;

pair<ll,int> seg[2*pot+7][3];
ll lzy[2*pot+7][3];
void push(int v,int c)
{
    seg[2*v][c].st+=lzy[v][c];
    seg[2*v+1][c].st+=lzy[v][c];
    lzy[2*v][c]+=lzy[v][c];
    lzy[2*v+1][c]+=lzy[v][c];
    lzy[v][c]=0;
}
void ins(int v,int a,int b,int l,int r,ll x,int c)
{
    if(r<a||l>b) return ;
    if(a<=l&&b>=r)
    {
        seg[v][c].st+=x;
        lzy[v][c]+=x;
        return ;
    }
    push(v,c);
    ins(2*v,a,b,l,(l+r)/2,x,c);
    ins(2*v+1,a,b,(l+r)/2+1,r,x,c);
    seg[v][c]=max(seg[2*v][c],seg[2*v+1][c]);
}
pair<ll,int> que(int v,int a,int b,int l,int r,int c)
{
    if(r<a||l>b) return {-infl,l};
    if(a<=l&&b>=r) return seg[v][c];
    push(v,c);
    return max(que(2*v,a,b,l,(l+r)/2,c),que(2*v+1,a,b,(l+r)/2+1,r,c));
}

vector<pair<int,int>>G[N];
ll W[N];
int head[N];
int s[N];
int id[N];
int id1[N];
int co[N];
int E[N];
int H[N];
int o[N];

void dfs_pre(int v)
{
    s[v]=1;
    for(auto u:G[v])
    {
        if(u.st==o[v]) continue;
        o[u.st]=v;
        E[u.nd]=u.st;
        dfs_pre(u.st);
        s[v]+=s[u.st];
    }
}
int it=0;
void dfs_hld(int v,ll d)
{
    id[v]=++it;
    co[it]=v;
    ins(1,it,it,1,pot,d,0);
    pair<int,ll>heavy={-1,0};
    int mx=0;
    for(auto u:G[v])
    {
        if(u.st==o[v]) continue;
        if(s[u.st]>mx)
        {
            mx=s[u.st];
            heavy=u;
        }
    }
    if(heavy.st!=-1)
    {
        head[heavy.st]=head[v];
        dfs_hld(heavy.st,d+W[heavy.nd]);
        for(auto u:G[v])
        {
            if(u.st==o[v]||u.st==heavy.st) continue;
            head[u.st]=u.st;
            dfs_hld(u.st,d+W[u.nd]);
        }
    }
    H[v]=heavy.st;
    id1[v]=it;
    ll D=0;
    if(H[v]!=-1) D=max(que(1,id[v],id[H[v]]-1,1,pot,0).st,que(1,id1[H[v]]+1,id1[v],1,pot,0).st);
    else D=que(1,id[v],id1[v],1,pot,0).st;
    ins(1,id[v],id[v],1,pot,D-2*que(1,id[v],id[v],1,pot,0).st,1);
}

ll res;
void brut(int v,int O,ll d)
{
    res=max(res,d);
    for(auto u:G[v])
    {
        if(u.st==O) continue;
        brut(u.st,v,d+W[u.nd]);
    }
}

int main()
{
   // srand(time(NULL));
  // freopen( "plik1.txt", "w", stdout );
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll w,c;
    int n,q;
    cin>>n>>q>>w;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b>>W[i];
        G[a].pb({b,i});
        G[b].pb({a,i});
    }
    dfs_pre(1);
    head[1]=1;
    for(int i=1;i<=pot;i++) seg[i+pot-1][0].nd=i;
    for(int i=pot-1;i>0;i--) seg[i][0].nd=seg[2*i][0].nd;
    dfs_hld(1,0);
    ll last=0;
    while(q--)
    {
        int a;
        ll c;
        cin>>a>>c;
        a=((ll)a+last)%(ll)(n-1);
        c=(c+last)%w;
        int v=E[a];
        ins(1,id[v],id1[v],1,pot,c-W[a],0);
        ins(1,id[v],id1[v],1,pot,-1*(c-W[a]),1);
        W[a]=c;
        while(v)
        {
            ll D=0;
            if(H[v]!=-1) D=max(que(1,id[v],id[H[v]]-1,1,pot,0).st,que(1,id1[H[v]]+1,id1[v],1,pot,0).st);
            ll was=que(1,id[v],id[v],1,pot,1).st;
            ll X=D-2*que(1,id[v],id[v],1,pot,0).st-was;
            ins(1,id[v],id[v],1,pot,X,1);
            v=o[head[v]];
        }
        pair<ll,int>P=que(1,1,n,1,pot,0);
        v=co[P.nd];
        ll ans=P.st;
        int pre=-1;
        while(v)
        {
            ans=max(ans,P.st+que(1,id[head[v]],id[v]-1,1,pot,1).st);
            ll D=0;
            if(pre!=-1) D=max(que(1,id[v],id[pre]-1,1,pot,0).st,que(1,id1[pre]+1,id1[v],1,pot,0).st);
            else D=que(1,id[v],id1[v],1,pot,0).st;
            ans=max(ans,P.st+D-2*que(1,id[v],id[v],1,pot,0).st);
            pre=head[v];
            v=o[head[v]];
        }
        cout<<ans<<endl;
        last=ans;
    }

    return 0;
}