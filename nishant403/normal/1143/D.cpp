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

ll int gcd(ll int a, ll int b) 
{ 
  if(b==0 ) return a;
  return gcd(b,a%b);
} 

int main()
{
 fast;   
 ll n,k,a,b,j,ans=0;
 string s;
    
  cin >> n >> k >> a >> b;
      
  ll mi=99999999999999;
  ll ma=0;
    
  ll temp=a+b;
  temp=(temp)%k;
    
   while( temp<= (n*k) )
   {
      ma=max(ma,(n*k)/gcd(n*k,temp)); 
      mi=min(mi,(n*k)/gcd(n*k,temp));
      temp+=k;    
   }
    
   temp=a-b;
   temp=((temp%k)+k)%k;
    
    while( temp<= (n*k) )
   {
      ma=max(ma,(n*k)/gcd(n*k,temp)); 
      mi=min(mi,(n*k)/gcd(n*k,temp));
      temp+=k;    
   }
     
    
    
    cout << mi << " " << ma;
}