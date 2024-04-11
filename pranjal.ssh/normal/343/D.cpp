#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define ntr(x,it) for(auto it = x.rbegin();it!=x.rend();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define MP make_pair
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)




vvi g;
vi pos,p;

struct leaf
{
    int mn;
    bool one;
};

vector<leaf> tree;


int query(int node, int i, int j, int u, int v)
{
    
    if(tree[node].one)
    {
        tree[node].one=0;
        tree[node].mn=1;
        if(i!=j)
        {
            tree[2*node+1].one=1;
            tree[2*node+2].one=1;
        }
    }
    if(i>j||v<i||u>j)return 1;
    
    if(i>=u&&j<=v)return tree[node].mn;
    
    return min(query(2*node+1,i,(i+j)/2,u,v),query(2*node+2,(i+j)/2+1,j,u,v));
    
}
void update1(int node, int i, int j, int u, int v)
{
    
    if(tree[node].one)
    {
        tree[node].one=0;
        tree[node].mn=1;
        if(i!=j)
        {
            tree[2*node+1].one=1;
            tree[2*node+2].one=1;
        }
    }
    
    if(i>j||v<i||u>j)return;
    if(i>=u&&j<=v)
    {
        tree[node].one=1;
        if(tree[node].one)
        {
            tree[node].one=0;
            tree[node].mn=1;
            if(i!=j)
            {
                tree[2*node+1].one=1;
                tree[2*node+2].one=1;
            }
        }
        return;
    
    }
    
    update1(2*node+1,i,(i+j)/2,u,v);
    update1(2*node+2,(i+j)/2+1,j,u,v);
    
    tree[node].mn=min(tree[2*node+1].mn, tree[2*node+2].mn);
}
void update2(int node, int i, int j, int u)
{
    
    if(tree[node].one)
    {
        tree[node].one=0;
        tree[node].mn=1;
        if(i!=j)
        {
            tree[2*node+1].one=1;
            tree[2*node+2].one=1;
        }
    }
    
    if(i>j||u<i||u>j)return;
    if(i==j)
    {
        tree[node].mn=0;
        return;
    }
    
    update2(2*node+1,i,(i+j)/2,u);
    update2(2*node+2,(i+j)/2+1,j,u);
    
    tree[node].mn=min(tree[2*node+1].mn, tree[2*node+2].mn);
}
vi sub;
int ctr;
void dfs(int u)
{
    
    pos[u]=ctr;
    ctr++;
    sub[u]=1;
    tr(g[u],it)
    {
        if(*it==p[u])continue;
        p[*it]=u;
        dfs(*it);
        sub[u]+=sub[*it];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n;
    cin>>n;
    g.resize(n);
    sub.resize(n);
    pos.resize(n);
    p.resize(n);
    p[0]=-1;
    FOR(i,0,n-2)
    {
        int u,v;
        cin>>u>>v;
        --u,--v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0);
    
    tree.resize(4*n+4);
    int q;
    cin>>q;
    while(q--)
    {
        int c,v;
        cin>>c>>v;
        --v;
        if(c==1)
        {
            if(query(0,0,n-1,pos[v],pos[v]+sub[v]-1)==0)
            if(v!=0) update2(0,0,n-1,pos[p[v]]);
            update1(0,0,n-1,pos[v],pos[v]+sub[v]-1);
        }
        else if(c==2)
        {
            update2(0,0,n-1,pos[v]);
        }
        else
        {
            cout<<query(0,0,n-1,pos[v],pos[v]+sub[v]-1)<<"\n";
        }
    }
  
    
    return 0;
}