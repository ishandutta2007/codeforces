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
  int n;
    cin >> n;
    
  int a[n];  
  f(i,n) cin >> a[i];
    
  int pos = 0;
  int neg = 0;
  int posans = 0;
  int negans = 0 ;
    
  if(a[0] > 0) pos++;
  else neg++;
   
  posans+=pos;
  negans+=neg;
    
  for(int i=1;i<n;i++)
  {
    if(a[i] > 0) 
    {   
        pos++;
        posans+=pos;
        negans+=neg;
    }
    else
    {
        pos++;
        swap(neg,pos);   
        posans+=pos;
        negans+=neg;
     
    }
      
      
  }
    
    
  cout << negans << " "<<posans;  
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}