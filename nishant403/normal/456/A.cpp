#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define vi vector<int>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


signed main()
{
Fast;    
    
  int n;
  string A = "Happy Alex";
  string B = "Poor Alex";
    
  int flag = 0;  
    
    cin >> n;
    
  vector<pii> a(n);  
    
  f(i,n) cin >> a[i].F >> a[i].S;
  
   sort(a.begin(),a.end());
      
   int q = a[0].S;
    
    for(int i=1;i<n;i++) if(a[i].S < q ) { flag = 1; break; }  
    else q = max(q,a[i].S);
  
    
   if(flag) cout << A;
    else cout << B;
    
}