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

const int N = 1e5+10;
const int inf = 1e9+10;

map<int,vector<pii> > x,y;
vector< pair<int,pii> > a,b;
int n,x1,yy1,x2,y2;
pair<vi,vi> seg[4*N];
pii tag[4*N];

void build(int node,int ss,int se)
{
    if(ss == se)
    {
        tag[node].F = tag[node].S = b[ss].F;
        seg[node].F.pb(b[ss].S.F);
        seg[node].S.pb(b[ss].S.S);
        return;
    }
    
    int mid = (ss+se)/2;
    
    build(node*2+1,ss,mid);
    build(node*2+2,mid+1,se);
    
    tag[node].F = tag[node*2+1].F;
    tag[node].S = tag[node*2+2].S;
    
    merge(all(seg[node*2+1].F),all(seg[node*2+2].F),back_inserter(seg[node].F));
    merge(all(seg[node*2+1].S),all(seg[node*2+2].S),back_inserter(seg[node].S));
}

int query(int node,int ss,int se,int ly,int ry,int lx)
{     
    if(tag[node].S < ly) return 0;
    if(tag[node].F > ry) return 0;
    
    //find how many segment in the segtree have lx in them.
    //starting less or equal to lx - ending less than lx.
    if(ly <= tag[node].F && tag[node].S <= ry)
    {
       int res = upper_bound(all(seg[node].F),lx)-1-seg[node].F.begin();
       res-=(lower_bound(all(seg[node].S),lx)-1-seg[node].S.begin()); 
         
       return res;
    }
    
    int mid = (ss+se)/2;
 
    return query(node*2+1,ss,mid,ly,ry,lx) + 
           query(node*2+2,mid+1,se,ly,ry,lx);
}

void solve()
{
   cin >> n;
   
   f(i,n)
   {
       cin >> x1 >> yy1 >> x2 >> y2;
       if(x1 == x2)
       {
           if(yy1 > y2) swap(y2,yy1);
           x[x1].pb({yy1,y2});
       }
       else if(yy1 == y2) 
       {
           if(x1 > x2) swap(x1,x2);
           y[yy1].pb({x1,x2});
       }
   }
     
   int res = 0; 
   
   for(auto z : x)
   {
       int best = -inf;
       
       if(z.S.empty()) continue;
       
       sort(z.S.begin(),z.S.end());
       
       for(auto v : z.S) 
          if(v.F > best) a.pb({z.F,v}),best = v.S,res+=(v.S-v.F+1);
         else if(v.S > best) a.pb({z.F,{best+1,v.S}}),res+=(v.S-best),best = v.S;
   }
    
   n = 0; 
    
   for(auto z : y)
   {
       int best = -inf;
    
       if(z.S.empty()) continue;
       
       sort(z.S.begin(),z.S.end());
       
       for(auto v : z.S) 
          if(v.F > best) b.pb({z.F,v}),res+=(v.S-v.F+1),best=v.S,n++;
          else if(v.S > best) b.pb({z.F,{best+1,v.S}}),res+=(v.S-best),best=v.S,n++;
   }
    
    sort(b.begin(),b.end());
   
  if(n>0)
  {
  build(0,0,n-1);   
  for(auto v : a) res-=query(0,0,n-1,v.S.F,v.S.S,v.F);
  }
    
   cout << res;
}

signed main()
{
    fast;        
    solve();
}