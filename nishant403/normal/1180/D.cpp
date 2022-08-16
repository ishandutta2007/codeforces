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
  int n,m;
  
  cin >> n >> m;
  
  int l1 =1,r1 = 1;  
   
  int lt = 1 , rt = n;
      
 for(int i=1;i<=n/2;i++)
 {
    int a1 = i;
    int a2 = n-(i-1);     
    
    int l1 = 1; 
     
   for(int j=1;j<=2*m;j++)
   {
       if(j%2 ==1)
       {
         cout << a1 << " " << l1 << "\n";   
       }
       else
       {
        cout << a2 <<" " << l1 << "\n";   
       }
       
      if(j%2 ==1) l1+=(m-j);
      else l1-=(m-j);
   } 
 }
 
 if(n%2 == 1)
 {
  int tak = (n+1)/2;
  int de = 1;  
     
   for(int i=1;i<=m;i++)
   {
    cout << tak << " " << de << "\n";
       
     if(i%2==1) de+=(m-i);
     else de-=(m-i);
   }
 }
    
    
    
}

signed main()
{
    fast;
    solve();
}