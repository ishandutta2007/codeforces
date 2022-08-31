
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 2e5 + 10;
const int M = 3e5 + 10;
const int Q = 5e5 + 10;

int n,m,q;
int val[N];
pii ed[M];
pii qq[Q];

//range max,point update
pii st[4*N];

void u1(int node,int ss,int se,int id,int val)
{
    if(ss == se)
    {
        st[node] = {val,id};
        return;
    }
    
    int mid = (ss + se)/2;
    
    if(id <= mid) u1(node*2+1,ss,mid,id,val);
    else u1(node*2+2,mid+1,se,id,val);
    
    st[node] = max(st[node*2+1],st[node*2+2]);
}

pii q1(int node,int ss,int se,int l,int r)
{
    if(ss > r || se < l) return {0,-1};
    
    if(l <= ss && se <= r) return st[node];
    
    int mid = (ss + se)/2;
    
    return max(q1(node*2+1,ss,mid,l,r),q1(node*2+2,mid+1,se,l,r));
}
    
//range assignment,point query
int st2[4*N];

void push(int node,int ss,int se)
{
    if(ss == se) return;
    if(st2[node] == 0) return;
    st2[node*2+1] = st2[node*2+2] = st2[node];
    st2[node] = 0;
}

void u2(int node,int ss,int se,int l,int r,int val)
{
    push(node,ss,se);  
    
    if(ss > r || se < l) return; 
    
    if(l <= ss && se <= r) 
    {
        st2[node] = val;
        push(node,ss,se);
        return;
    }
    
    int mid = (ss + se)/2;
    
    u2(node*2+1,ss,mid,l,r,val);
    u2(node*2+2,mid+1,se,l,r,val);
}

int q2(int node,int ss,int se,int id)
{
    push(node,ss,se);
    
    if(ss == se) return st2[node];
    
    int mid = (ss + se)/2;
    
    if(id <= mid) return q2(node*2+1,ss,mid,id);
    return q2(node*2+2,mid+1,se,id);
}

//we need r1,r2 and cut
//range id of larger segment ,range id of smaller segment,size of the larger segment
vector<pii> range;
int ptr = 0;
int cut[Q];
int get_id[Q];

struct node
{
    vector<int> vals;
    int sz;
    int pr;
};

node dsu[N];
int pos[N];

void init()
{
    for(int i=0;i<n;i++)
    {
        dsu[i].sz = 1;
        dsu[i].pr = i;
        dsu[i].vals.pb(i);
    }
}

int find(int x)
{
    if(dsu[x].pr == x) return x;
    return dsu[x].pr = find(dsu[x].pr);
}

void merge(int a,int b,int id)
{
     int x = find(a);
     int y = find(b);
    
     if(x == y) return;
    
     if(dsu[x].sz > dsu[y].sz) swap(x,y);
    
     if(id != -1)
     {
         cut[id] = dsu[y].sz;
         get_id[id] = dsu[y].vals[0];
     }
    
     dsu[x].pr = y;
     dsu[y].sz += dsu[x].sz;
    
     for(auto v : dsu[x].vals) dsu[y].vals.pb(v);
     dsu[x].vals.clear();
}

signed main()
{
    fast;
    
    cin >> n >> m >> q;
    
    f(i,n) cin >> val[i];
    
    f(i,m) cin >> ed[i].F >> ed[i].S;
    f(i,m) ed[i].F--,ed[i].S--;     
    
    f(i,q) cin >> qq[i].F >> qq[i].S;
    f(i,q) qq[i].S--;
    
    //process 
    vector<bool> vis(m,0);
  
    f(i,q) if(qq[i].F == 2) vis[qq[i].S] = 1;
    
    init();
    
    f(i,m) if(vis[i] == 0) merge(ed[i].F,ed[i].S,-1);
    
    for(int i=q-1;i>=0;i--)
        if(qq[i].F == 2) merge(ed[qq[i].S].F,ed[qq[i].S].S,i);
    
    int ps = 0;    
   
    range.pb({-1,-1});
    ptr++;
        
    f(i,n) if(find(i) == i)
    {
        range.pb({ps,ps+dsu[i].sz-1});
        
        for(auto x : dsu[i].vals)
        {
            u1(0,0,n-1,ps,val[x]);
            u2(0,0,n-1,ps,ps,ptr);
            pos[x] = ps;
            ps++;
        }
        
        ptr++;
    }
    
    f(i,q)
    {
        if(qq[i].F == 1)
        {
            int id = q2(0,0,n-1,pos[qq[i].S]);
            
            pii mxx = q1(0,0,n-1,range[id].F,range[id].S);
            
            cout << mxx.F << '\n';
            
            if(mxx.S != -1) u1(0,0,n-1,mxx.S,0);
        }
        else
        {
            int sz = cut[i];
            if(sz == 0) continue;
            
            int id = q2(0,0,n-1,pos[get_id[i]]);
            int l = range[id].F;
            int r = range[id].S;
            int mid = l + sz - 1;
            
            range.pb({l,mid});
            u2(0,0,n-1,l,mid,ptr++);
            
            range.pb({mid+1,r});
            u2(0,0,n-1,mid+1,r,ptr++);
        }
    }
}