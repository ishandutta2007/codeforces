#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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

const int N=200007,pot=1<<18;

struct segtree
{
    struct S
    {
        int mn,ile;
    };
    int lzy[2*pot+7];
    S seg[2*pot+7];
    segtree()
    {
        memset(lzy,0,sizeof lzy);
        memset(seg,0,sizeof seg);
    }
    S Merge(S l,S r)
    {
        if(l.mn<r.mn) return l;
        if(l.mn>r.mn) return r;
        return {l.mn,l.ile+r.ile};
    }
    void bulid()
    {
        for(int i=pot-1;i>0;i--) seg[i]=Merge(seg[2*i],seg[2*i+1]);
    }
    void push(int v)
    {
        lzy[2*v]+=lzy[v];
        lzy[2*v+1]+=lzy[v];
        seg[2*v].mn+=lzy[v];
        seg[2*v+1].mn+=lzy[v];
        lzy[v]=0;
    }
    void ins(int v,int a,int b,int l,int r,int x)
    {
        if(r<a||l>b) return ;
        if(a<=l&&b>=r)
        {
            seg[v].mn+=x;
            lzy[v]+=x;
            return ;
        }
        push(v);
        ins(2*v,a,b,l,(l+r)/2,x);
        ins(2*v+1,a,b,(l+r)/2+1,r,x);
        seg[v]=Merge(seg[2*v],seg[2*v+1]);
    }
    S que(int v,int a,int b,int l,int r)
    {
        if(r<a||l>b) return {inf,0};
        if(a<=l&&b>=r) return seg[v];
        push(v);
        return Merge(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
    }
};
segtree O,E;

vector<pair<int,int>>G[N];
int s[N],k[N],o[N];
int id[N],head[N];

void dfs_init(int v)
{
    s[v]=1;
    for(auto u:G[v])
    {
        if(u.st==o[v]) continue;
        k[u.st]=u.nd;
        o[u.st]=v;
        dfs_init(u.st);
        s[v]+=s[u.st];
    }
}
int it=0;
void dfs_hld(int v)
{
    id[v]=++it;
 //   cout<<v<<" ";
    O.seg[it+pot-1].ile=k[v];
    E.seg[it+pot-1].ile=k[v];
    if(it%2) E.seg[it+pot-1].mn=inf;
    else O.seg[it+pot-1].mn=inf;
    int heavy=-1,mx=-1;
    for(auto u:G[v])
    {
        if(u.st==o[v]) continue;
        if(s[u.st]>mx)
        {
            heavy=u.st;
            mx=s[u.st];
        }
    }
    if(heavy==-1) return ;
    head[heavy]=head[v];
    dfs_hld(heavy);
    for(auto u:G[v])
    {
        if(u.st==o[v]||u.st==heavy) continue;
        head[u.st]=u.st;
        dfs_hld(u.st);
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
        int n,a,b;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb({b,i});
            G[b].pb({a,i});
        }
        dfs_init(1);
        head[1]=1;
        dfs_hld(1);
        O.bulid(),E.bulid();
        O.ins(1,1,1,1,pot,1);
        while(true)
        {
            int t,v;
            cin>>t;
            if(t==3) return 0;
            if(t==1)
            {
                cin>>v;
                bool b=0;
                while(v)
                {
                    int x=1-2*b;
                    bool c=(id[v]-id[head[v]]+1)%2;
                    if(id[head[v]]%2==0) x=-x;
                    if(!c) x=-x;
                    O.ins(1,id[head[v]],id[v],1,pot,x);
                    E.ins(1,id[head[v]],id[v],1,pot,-x);
                    v=o[head[v]];
                    b^=c;
                }
                if(min(O.seg[1].mn,E.seg[1].mn)<0||O.que(1,1,1,1,pot).mn==1) cout<<0<<endl;
                else
                {
                    int x=n*(n-1)/2;
                    if(O.seg[1].mn==0) x-=O.seg[1].ile;
                    if(E.seg[1].mn==0) x-=E.seg[1].ile;
                    cout<<x<<endl;
                }
            }
            if(t==2)
            {
                if(min(O.seg[1].mn,E.seg[1].mn)<0||O.que(1,1,1,1,pot).mn==1) cout<<0<<endl;
                else
                {
                    vector<int>ans;
                    for(int i=2;i<=n;i++)
                    {
                        if(id[i]%2==1&&O.que(1,id[i],id[i],1,pot).mn==1) ans.pb(k[i]);
                        if(id[i]%2==0&&E.que(1,id[i],id[i],1,pot).mn==1) ans.pb(k[i]);
                    }
                    sort(all(ans));
                    cout<<sz(ans)<<" ";
                    for(auto x:ans) cout<<x<<" ";
                    cout<<endl;
                }
            }
        }
    }

    return 0;
}