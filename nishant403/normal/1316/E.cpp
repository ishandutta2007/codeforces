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

const int N = 1e5+10;
const int inf = 1e15;

int n,p,k;
vector<int> dat[N];

vector<int> cur,nex;

void solve()
{
   cin >> n >> p >> k;
   
   f(i,n) dat[i].resize(p+1); 
   
   f(i,n) cin >> dat[i][0]; 
   f(i,n) f(j,p) cin >> dat[i][j+1];
    
   sort(dat,dat+n);
   reverse(dat,dat+n);
  
   cur.resize((1LL<<p));
   nex.resize((1LL<<p));
    
   f(i,(1LL<<p)) cur[i] = -inf;
   cur[0] = 0;
   
   f(i,n)
   {
      f(j,(1LL<<p))
      {  
          nex[j] = cur[j];
          if(i-__builtin_popcount(j) < k) nex[j]+=dat[i][0];
          
          f(v,p)
          {
              if((j&(1LL<<v)) == 0) continue;
              nex[j] = max(nex[j],cur[j^(1LL<<v)] + dat[i][v+1]);
          }
      }
       
      swap(cur,nex); 
   }
    
   cout << cur[(1LL<<p)-1]; 
}

signed main()
{
    fast;
    solve();
}