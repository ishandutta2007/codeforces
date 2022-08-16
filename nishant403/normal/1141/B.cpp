#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second

int main()
{
 fast;   
 ll n,k,an=0;
 string s;
    ll i,j;
 
 cin >> n;
  int a[n];
    
  f(i,n) cin >> a[i];
    
    ll temp=0;
    
  f(i,n)
  {
    if(a[i]==0)
    {
        an=max(an,temp);
        temp=0;
    }
      else temp++;
      
  }
    an=max(an,temp);
    
    ll b=0;
    
  f(i,n) if(a[i]==1) b++;
      else break;
    
  for(i=n-1;i;i--) if(a[i]==1) b++;
      else break;
      
      cout << max(b,an);
      
    
    return 0;
}