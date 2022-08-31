#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define pll pair<long long,long long>
#define vl vector<long> 


ll mulmod(ll a, ll b) 
{ ll mod = 1000000007;
    ll res = 0; 
    a = (a % mod); 
    while (b) 
    { 
        if (b&1) res = (res + a) % mod; 
        a = (a * 2) % mod; 
        b = b/2; 
    } 
  
    // Return result 
    return (res % mod); 
} 
  

long long get(ll n)
{
 ll od=0,ev=0;
    ll M=1000000007;
    ll i;
    
 for(i=63;i>=0;i--)   
 {
  if(n &( (1LL) <<i))
  {
   od = ((n -( (1LL) << i) ) + 1)%M;
   if(i&1) swap(od,ev);   
      
   for(ll j=i-1;j>=0;j--)
   {
   if( (j&1) ) ev+=( ( (1LL)<<j));
   else od+= ( ((1LL) <<j));
   }
       
   break;
    
    }
 }
    
  ll a=0;
    
    
  a=(mulmod(od,od));
  a=(a+mulmod(ev,ev))%M;
  a=(a+ev)%M;  
    
  return a;
}

int main()
{
 fast;   
 ll n,k,i,j,a=0;
 string s;
    long long l,r;
    
 cin >> l >> r;   
    
 cout << ( (get(r)) - (get(l-1)) + 1000000007 )%1000000007;
}