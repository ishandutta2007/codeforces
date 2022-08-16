#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define int long long

const int N = 4e5+10;
const int MX = 1e6;
int seg[2*N];
int seg2[2*N];
int sn;

void build()
{
    f(i,2*N) seg[i] = 0;
    f(i,2*N) seg2[i] = MX;
}

void upd(int id,pii val)
{
    id+=sn;
    seg[id] = max(seg[id],val.F);
    seg2[id] = min(seg2[id],val.S);
    for(;id>1;id>>=1) seg[id>>1] = max(seg[id],seg[id^1]),
    seg2[id>>1] = min(seg2[id],seg2[id^1]);   
}

pii query(int l,int r)
{
    r++;
    
    pii ans = {0,MX}; 
    pii saver = {l,r};
    
    for(l+=sn,r+=sn;l<r;l>>=1,r>>=1)
    {
        if(l&1) ans.F=max(ans.F,seg[l++]);
        if(r&1) ans.F=max(ans.F,seg[--r]);
    }
    
    l = saver.F; r = saver.S;
    
    for(l+=sn,r+=sn;l<r;l>>=1,r>>=1)
    {
        if(l&1) ans.S=min(ans.S,seg2[l++]);
        if(r&1) ans.S=min(ans.S,seg2[--r]);
    }
    
    return ans;
}

void solve()
{
  int n;
  cin >> n;
    
  vector<pair<pii,pii> > a(n);
  f(i,n) cin >> a[i].F.S >> a[i].F.F >> a[i].S.F >> a[i].S.S;
    
  sort(a.begin(),a.end());
  f(i,n) swap(a[i].F.F,a[i].F.S);
    
  //compress values.
  vector<int> cmp(4*n);
    
  f(i,n) cmp[i] = a[i].F.F;
  f(i,n) cmp[i+n] = a[i].F.S;
  f(i,n) cmp[i+n+n] = a[i].S.F;
  f(i,n) cmp[i+n+n+n] = a[i].S.S;
    
  sort(cmp.begin(),cmp.end());
    
  cmp.resize( distance(cmp.begin(),unique(cmp.begin(),cmp.end())) );  
   
  map<int,int> mp;  
    
  f(i,cmp.size()) mp[cmp[i]] = i;
    
  f(i,n) a[i].F.F = mp[a[i].F.F];    
  f(i,n) a[i].F.S = mp[a[i].F.S];  
  f(i,n) a[i].S.F = mp[a[i].S.F];    
  f(i,n) a[i].S.S = mp[a[i].S.S];  
   
  sn = mp.size();  
    
  build();  
 
 //case a do overlap, b don't overlap  
 upd(a[0].F.S,a[0].S);   
    
 for(int i=1;i<n;i++)
 {
  auto v = query(a[i].F.F,sn-1);   
     
  if(v.F > a[i].S.S || v.S < a[i].S.F)   
  {
      cout << "NO\n"; 
      return;
  }
        
  upd(a[i].F.S,a[i].S);   
 }
    
 //now b overlaps
 f(i,n) swap(a[i].F,a[i].S);
 f(i,n) swap(a[i].F.F,a[i].F.S);
 sort(a.begin(),a.end());
 f(i,n) swap(a[i].F.F,a[i].F.S);
    
  build();  
 
 //case a do overlap, b don't overlap  
 upd(a[0].F.S,a[0].S);   
    
 for(int i=1;i<n;i++)
 {
  auto v = query(a[i].F.F,sn-1);   
     
  if(v.F > a[i].S.S || v.S < a[i].S.F)   
  {
      cout << "NO\n"; 
      return;
  }
        
  upd(a[i].F.S,a[i].S);   
 }  
     
  cout <<"YES\n";  
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}