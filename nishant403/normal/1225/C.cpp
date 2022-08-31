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

int get(int n)
{
  int res = 0;
    
  for(int i=0;i<35;i++)
      if((n&(1LL<<i)) > 0) res++;
      
  return res;
}

void solve()
{
 int n,p;  
 cin >> n >> p;   
    
 int ans = -1;   
    
 for(int i=0;i<10000;i++)   
 { 
     int num = (n - (i*p)); 
     if(num <=0) continue; 
    
     int v = get(num);
     
    //v is no of bits
    //representation of bits from v to num
    //i must be inbetween
     
    if(i > num || i < v) continue;
     
    ans = i;
    break;
 }
     
     
 cout << ans; 
     
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}