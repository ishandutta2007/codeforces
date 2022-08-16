#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define f(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define F first
#define S second

bool comp(const pair<pair<int,int>,int> & a,const pair<pair<int,int>,int> &b)
{
  return a.F.S > b.F.S;     
}

signed main()
{
 int n;
 vector< pair<pair<int,int>,int> > a,b;
  
  cin >> n;  
    
 pair<int,int> c;   
    
 f(i,n)
 {
  cin >> c.F >> c.S;
     
   if(c.F  > c.S) a.pb({c,i+1});
   else b.pb({c,i+1});
 }
  sort(a.begin(),a.end(),comp);  
  sort(b.begin(),b.end(),comp);  
    
 
  if(b.size() > a.size())
  {
      cout << b.size() << "\n";
      for(auto x : b) cout << x.S << " ";
      
  }
  else
  {
      reverse(a.begin(),a.end());
      
    cout << a.size() << "\n";  
    for(auto x : a) cout << x.S << " ";  
  }
    
    
}