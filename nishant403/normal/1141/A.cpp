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
 
 ll a,b;
    
    cin >> a >> b;
    
  ll x = b / a;
    
    if(b%a!=0)
    {cout << "-1";
    return 0;
    }
    
    
    while(x!=1)
    {
     if(x%2==0) x/=2;
      else if(x%3==0) x/=3;  
     else
      {
       cout << -1;
          return 0;
          
      }
          
        an++;  
    }
    
    
    cout << an;
    
    
    return 0;
}