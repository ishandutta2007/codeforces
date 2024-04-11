#include <bits/stdc++.h>
#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

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
int inf=1000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int N=200007,pot=1<<18;

int a[N],pos[N];
vector<pair<int,int>>V[N];
vector<pair<int,int>>Q[N];
ll ans[1000007];
int nx[N];
int last[N];
int mx[N];
vector<pair<pair<int,int>,bool>>Z[N];

void add(int l,int r,int x,int y)
{
    if(l>r||x>y) return ;
   // cout<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
    Z[y+1].pb({{l,r},0});
    Z[x].pb({{l,r},1});
}

struct segtree
{
    ll seg[2*pot+7],lzy[2*pot+7];
    segtree()
    {
        memset(seg,0,sizeof seg);
        memset(lzy,0,sizeof lzy);
    }
    void push(int v,ll s)
    {
        lzy[2*v]+=lzy[v];
        lzy[2*v+1]+=lzy[v];
        seg[2*v]+=lzy[v]*s;
        seg[2*v+1]+=lzy[v]*s;
        lzy[v]=0;
    }
    void ins(int v,int a,int b,int l,int r,ll x)
    {
        if(r<a||l>b) return ;
        if(a<=l&&b>=r)
        {
            seg[v]+=(ll)(r-l+1)*x;
            lzy[v]+=x;
            return;
        }
        push(v,(r-l+1)/2);
        ins(2*v,a,b,l,(l+r)/2,x);
        ins(2*v+1,a,b,(l+r)/2+1,r,x);
        seg[v]=seg[2*v]+seg[2*v+1];
    }
    ll que(int v,int a,int b,int l,int r)
    {
        if(r<a||l>b) return 0;
        if(a<=l&&b>=r) return seg[v];
        push(v,(r-l+1)/2);
        return que(2*v,a,b,l,(l+r)/2)+que(2*v+1,a,b,(l+r)/2+1,r);
    }
};

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
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pos[a[i]]=i;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j+=i)
            {
                if(i<j/i)
                {
                    int l=pos[i],r=pos[j/i];
                    if(l>r) swap(l,r);
                    V[r].pb({l,j});
                }
            }
        }
        for(int i=1;i<=q;i++)
        {
            int l,r;
            cin>>l>>r;
            Q[r].pb({l,i});
        }
        vector<int>S;
        for(int i=1;i<=n;i++) nx[i]=inf;
        for(int i=1;i<=n;i++)
        {
            while(sz(S)>0&&S.back()<a[i])
            {
                add(nx[S.back()]+1,min(pos[S.back()],mx[S.back()]),last[S.back()],i-1);
                nx[S.back()]=inf;
                S.pop_back();
            }
            if(sz(S)==0) nx[a[i]]=0;
            else nx[a[i]]=pos[S.back()];
            last[a[i]]=i;
            S.pb(a[i]);
            for(auto x:V[i])
            {
                add(nx[x.nd]+1,min(pos[x.nd],mx[x.nd]),last[x.nd],i-1);
                mx[x.nd]=max(mx[x.nd],x.st);
                last[x.nd]=i;
            }
        }
        for(int i=1;i<=n;i++) add(nx[i]+1,min(pos[i],mx[i]),last[i],n);
        segtree X,Y;
        for(int i=1;i<=n;i++)
        {
            for(auto x:Z[i])
            {
                if(x.nd)
                {
                    X.ins(1,x.st.st,x.st.nd,1,pot,1);
                    Y.ins(1,x.st.st,x.st.nd,1,pot,-i+1);
                }
                else
                {
                    X.ins(1,x.st.st,x.st.nd,1,pot,-1);
                    Y.ins(1,x.st.st,x.st.nd,1,pot,i-1);
                }
            }
            for(auto x:Q[i]) ans[x.nd]=X.que(1,x.st,i,1,pot)*(ll)i+Y.que(1,x.st,i,1,pot);
        }
        for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
    }

    return 0;
}