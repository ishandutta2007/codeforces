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

int main()
{
 fast;   
 ll n,k,i,j,an=0;
 string s;
    
 cin >> n;
    
  ll a[n];
  f(i,n) cin >> a[i]; 
   
    
  ll temp=a[n-1];  
  an+=temp;  
    
   for(i=n-2;i>=0;i--)
   {
       if(temp==0) break;
       
    if(a[i] < temp )
    { 
      temp=a[i];
    }
    else if(a[i]>=temp)
    {
      temp=temp-1;
    }
       an+=temp;
    }
    
    cout << an;
}