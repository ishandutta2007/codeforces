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

void solve()
{
   int n,k,l;
    cin >> n >> k >> l;
    
   int a[n];
    f(i,n) cin >> a[i];
   
   pii cur = {0,k+k-1};
    
   f(i,n)
   {
       if(a[i] > l)
       {
           cout <<"No\n";
           return;
       }
       
       int val = min(k,l - a[i]);
       
       cur.F++;
       cur.F %= (k + k);
       cur.S++;
       cur.S %= (k + k);
       
       pii L = {0,0};
       pii R = {0,0};
       
       if(cur.F <= cur.S) L = R = cur;
       else 
       {
           L = {0 , cur.S};
           R = {cur.F , k + k - 1};
       }
       
       pii nex = {-1,-1};
       
       if(val == 0)
       {
           if(L.F == 0) nex = {0,0};
       }
       else if(val == k) nex = {0,k + k - 1};
       else 
       {
          pii L2 = {0,val};
          pii R2 = {k+k-val,k+k-1};
          
          if(R.S < R2.F)
          {
              if(L.F <= val)
              {
                  nex.F = L.F;
                  nex.S = val;
              }
          }
          else
          {
              nex.F = max(R2.F , R.F);
              nex.S = val;
          }
       }
       
       swap(cur,nex);
       
       if(cur.F == -1)
       {
           cout <<"No\n";
           return;
       }
   }
    
   cout <<"Yes\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
   
    while(t--)
        
    solve();
}