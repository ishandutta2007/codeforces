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

vector<int> isprime(1015,1);

void sieve()
{
    isprime[1] = isprime[0] = 0;
    
    for(int i=2;i<1015;i++)
    {
     if(isprime[i] == 1)
         for(int j=2*i;j<1015;j+=i) isprime[j] = 0;
    }
}

void solve()
{
  sieve();  
    
  int n;
  cin >> n;
    
  int h = n;  
    
  while(isprime[h]==0) h++;  
   
  //we need h edges
    
  cout << h << "\n";
    
  f(i,n-1) cout << (i+1) << " " << (i+2) << "\n";
  cout << (1) << " " << n << "\n";
    
  vector<bool> vis(n+1,0);  
    
  int cnt = 0;  
    
  for(int i=1;i<=n;i++)
  {
   if(vis[i] || vis[i+2]) continue;
   if(cnt == (h-n) ) break;
      
    cnt++;  
      
    vis[i] = vis[i+2] = i;
      
   cout << (i)  << " " << (i+2) << "\n";
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