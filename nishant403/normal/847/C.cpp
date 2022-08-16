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

void solve()
{
int n,k;
    
cin >> n >> k;
    
if( k > (n*(n-1))/2) { cout << "Impossible\n";  return;}    
       
int cnt = 1;
int sum = 0; 
 
int open = 1;
int close = 0;
    
vector<int> c(2*n,0);
      
int i = 1;
 
c[0] = 1;    
    
while(sum < k)    
{
  if(sum + cnt <= k)
  {
   c[i] = 1;
   sum+=cnt;   
   cnt++ ;   
      
   open++;   
  }
  else
  {
   c[i]= -1;   
   cnt--; 
   close++;   
  }
    
  i++;  
}
    
while(open > close)
{
 c[i++] = -1;   
 close++;   
}
    
while(open < n)
{
 c[i++] = 1;
 c[i++] = -1;
 open++;   
}
    
f(i,2*n)
{
 if(c[i] == 1) cout << '(';
 else cout << ')';   
}
    
    
    
}

signed main()
{
    fast;
    solve();
}