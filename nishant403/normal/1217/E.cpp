#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N =2e5+10;
const int inf = 1e9+10;

pii seg[2*N][10];
int n,q,x,typ,l,r;

const pii def = {inf,inf};

pii merge(pii & a,pii & b)
{
    pii res = def;
    
    res.F = min(a.F,b.F);
    
    if(a.F < b.F) res.S = min(a.S,b.F);
    else res.S = min(b.S,a.F);
        
    return res;
}

int query(int L,int R)
{
    pii final = def;   
    
    f(i,10)
    {
     pii ans = def;   
        
     for(int lh=L+n,rh=R+n;lh<rh;lh>>=1,rh>>=1)
     {
      if(lh&1) ans = merge(ans,seg[lh++][i]);   
      if(rh&1) ans = merge(ans,seg[--rh][i]);   
     }  
        
      if(ans.F >= inf || ans.S >= inf) continue;
      if(ans.F + ans.S < final.F + final.S) final = ans;
    }

    if(final.F >= inf || final.S >= inf) return -1;
    return (final.F+final.S);
}

void update(int id,int val)
{
    int cop = val,len=0;
    vi digit(10,0);
    
    id+=n;
    
    while(cop)
    {
      digit[len++] = cop%10;
      cop/=10;
    }
    
    f(i,10)
    {  
        seg[id][i]=def;
        
        if(digit[i]>0) seg[id][i].F = val;
        
        for(int j=id;j>=1;j>>=1) 
            seg[j>>1][i] = merge(seg[j][i],seg[j^1][i]);
    }
}

void build()
{
 f(j,10)   
  for(int i=n-1;i;i--) seg[i][j] = merge(seg[i<<1][j],seg[i<<1^1][j]);   
}

signed main()
{
    fast;
    
  cin >> n >> q;
    
  f(i,n)
  {
    cin >> x;
      
    int cop = x,len=0;
    vi digit(10,0);
    
    int id = i+n;
    
    while(cop)
    {
      digit[len++] = cop%10;
      cop/=10;
    }
    
    f(j,10)
    {  
        seg[id][j]=def;     
        if(digit[j]) seg[id][j].F = x;
    }
      
  }
    
  build();  
    
  while(q--)
  {
   cin >> typ >> l >> r;
      
   if(typ == 1) update(l-1,r);
   else cout << query(l-1,r) << "\n";
  }
    
}