#include <bits/stdc++.h>

#define int long long
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

const int N=200007;

int a[N];
int o[N];
map<int,int>num;
int R[N];
int ans[N];
vector<pair<int,int>>G[N];

int Find(int v)
{
    while(true)
    {
        if(o[v]==v) return v;
        v=o[v];
    }
}
void Onion(int u,int v)
{
    o[u]=v;
}

int seg[4*N],pot=1;
int que(int v,int a,int b,int l,int r)
{
    if(l>b||r<a) return inf;
    if(a<=l&&b>=r) return seg[v];
    return min(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
}
void ins(int v,int u)
{
    v+=pot-1;
    seg[v]=u;
    while(v>1)
    {
        v/=2;
        seg[v]=min(seg[2*v],seg[2*v+1]);
    }
}

void dfs(int v,int o,int val)
{
    ans[v]=val;
    for(auto u:G[v])
    {
        if(u.st==o) continue;
        dfs(u.st,v,val+u.nd);
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
        int n;
        cin>>n;
        vector<pair<int,int>>vec;
        set<int>calc;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            vec.pb({a[i],i});
            calc.insert(a[i]);
        }
        int it=0,it1=0;
        for(auto x:calc) num[x]=++it;
        while(pot<it) pot*=2;
        sort(vec.begin(),vec.end());
        for(int i=n+1;i<=2*n;i++) a[i]=a[i-n];
        for(int i=2*n;i>0;i--)
        {
            R[i]=que(1,num[a[i]]+1,it,1,pot);
            ins(num[a[i]],i);
        }
        set<int>zle;
        zle.insert(inf);
        for(int i=1;i<=n;i++)
        {
            o[i]=i;
           // cout<<R[i]<<" ";
        }
        //cout<<endl;
        memset(ans,-1,sizeof ans);
        for(auto x:vec)
        {
            while(it1<sz(vec)&&vec[it1].st<x.st/2+x.st%2)
            {
                zle.insert(vec[it1].nd);
                zle.insert(vec[it1++].nd+n);
            }
           // cout<<x.st<<" "<<x.nd<<endl;
            int p=*zle.upper_bound(x.nd);
          //  cout<<p<<" "<<R[x.nd]<<endl;
            if(p<R[x.nd])
            {
                ans[x.nd]=p;
                dfs(x.nd,-1,p-x.nd);
              //  cout<<p<<endl;
            }
            else if(R[x.nd]!=inf)
            {

                if(R[x.nd]<=n) G[R[x.nd]].pb({x.nd,R[x.nd]-x.nd});
                else G[R[x.nd]-n].pb({x.nd,R[x.nd]-x.nd});
            }
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    }

    return 0;
}