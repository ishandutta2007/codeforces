#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push
int main()
{
 fast;   
 ll n,k,i,an=0;
 string l,r;
    
  cin >> n;
  cin >> l;
  cin >> r;
    
  queue<int> a[27];
  queue<int> b[27];  
    
  f(i,n)
  {
   if(l[i]=='?') a[26].pb(i+1);
   else a[l[i]-'a'].pb(i+1);   
      
   if(r[i]=='?') b[26].pb(i+1);
   else b[r[i]-'a'].pb(i+1);   
      
  }   
    
   vector<pair<int,int> > z; 
    
  f(i,26)
  {
   while(a[i].size() && b[i].size() ) 
   {
       z.push_back({a[i].front(),b[i].front()});
       a[i].pop();
       b[i].pop();
       
       an++;
   }
  } 
    
   f(i,26)
   {
    while(b[i].size() && a[26].size() )
    {
        z.push_back({a[26].front(),b[i].front() } );
        a[26].pop();
        b[i].pop();
        an++;
    }
   }
  

   f(i,27)
   {
      
    while(a[i].size() && b[26].size() )
    {
        z.push_back({a[i].front(),b[26].front() } );
        a[i].pop();
        b[26].pop();
        an++;
    }
    
   }
   
    cout << an << "\n";
    
    f(i,an) cout << z[i].F << "  " << z[i].S << "\n";
    
    
    return 0;
}