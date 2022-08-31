#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 6e5 + 1000;

int seg[4*N];
bool lazy_set[4*N];
bool lazy_unset[4*N];
bool lazy_invert[4*N];

void push(int node,int ss,int se)
{
    if(lazy_set[node] == 1)
    {
        seg[node] = se - ss + 1;
        
        if(ss != se)
        {
            lazy_set[node*2+1] = 1;
            lazy_unset[node*2+1] = 0;
            lazy_invert[node*2+1] = 0;
            
            lazy_set[node*2+2] = 1;
            lazy_unset[node*2+2] = 0;
            lazy_invert[node*2+2] = 0;
        }
        
        lazy_set[node] = 0;
    }
    
    if(lazy_unset[node] == 1)
    {
        seg[node] = 0;
        
        if(ss != se)
        {
            lazy_unset[node*2+1] = 1;
            lazy_set[node*2+1] = 0;
            lazy_invert[node*2+1] = 0;
            
            lazy_unset[node*2+2] = 1;
            lazy_set[node*2+2] = 0;
            lazy_invert[node*2+2] = 0;
        }
        
        lazy_unset[node] = 0;
    }
    
    if(lazy_invert[node] == true)
    {
        seg[node] = (se - ss + 1) - seg[node];
        
        if(ss != se)
        {
            lazy_invert[node*2+1] ^=1;
            lazy_invert[node*2+2] ^=1;
        }
        
        lazy_invert[node] = false;
    }
}

void update(int node,int ss,int se,int l,int r,int t)
{
    push(node,ss,se);
    
    if(ss > r || se < l) return;
    
    if(l <= ss && se <= r)
    {
        if(t == 1)
        {
            lazy_set[node] = true;
            lazy_unset[node] = false;
            lazy_invert[node] = false;
        }
        else if(t == 2)
        {
            lazy_unset[node] = true;
            lazy_set[node] = false;
            lazy_invert[node] = false;
        }
        else lazy_invert[node]^=1;
        
        push(node,ss,se);
       
        return;
    }
    
    int mid = (ss + se)/2;
    
    update(node*2+1,ss,mid,l,r,t);
    update(node*2+2,mid+1,se,l,r,t);
    
    seg[node] = seg[node*2+1] + seg[node*2+2];
}

int query(int node,int ss,int se)
{
    push(node,ss,se);
    
    if(seg[node] == se - ss + 1) return -1;
    
    if(ss == se) return ss;
    
    int mid = (ss + se)/2;
    
    int q1 = query(node*2+1,ss,mid);
    
    if(q1 != -1) return q1;
    else return query(node*2+2,mid+1,se);
}

int query2(int node,int ss,int se,int id)
{
    push(node,ss,se);
    
    if(ss == se) return seg[node];
    
    int mid = (ss + se)/2;
    
    if(id <= mid) return query2(node*2+1,ss,mid,id);
    else return query2(node*2+2,mid+1,se,id);
}

void solve()
{
   int n;
    cin >> n;
    
   pair<int,pii> qq[n];
   f(i,n) cin >> qq[i].F>> qq[i].S.F >> qq[i].S.S;
    
   vector<int> vs;
    
   for(int i=0;i<=2;i++) vs.pb(i);
   for(int i=-1;i<=1;i++) vs.pb((int)1e18 + i);
   
   f(i,n) 
   {
       vs.pb(qq[i].S.F);
       vs.pb(qq[i].S.F-1);
       vs.pb(qq[i].S.F+1);
       
       vs.pb(qq[i].S.S);
       vs.pb(qq[i].S.S-1);
       vs.pb(qq[i].S.S+1);
   }
    
   sort(all(vs));
   vs.resize(unique(all(vs)) - vs.begin());
    
   reverse(all(vs));
    while(!vs.empty() && vs.back() <= 0) vs.pop_back();
   reverse(all(vs));
   
   int NN = vs.size(); 
   
   f(i,n)
   {
       qq[i].S.F = lower_bound(all(vs),qq[i].S.F) - vs.begin();
       qq[i].S.S = lower_bound(all(vs),qq[i].S.S) - vs.begin();
       
       update(0,0,NN-1,qq[i].S.F,qq[i].S.S,qq[i].F);
      
       cout << vs[query(0,0,NN-1)] <<'\n';
   }
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}