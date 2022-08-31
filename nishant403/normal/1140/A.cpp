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
#define N 


int main()
{
 fast;   
 ll n,k,i,j,an=0;
 string s;
  
   cin >> n;
    
   ll a[n+1]; 
    
    f(i,n) cin >> a[i+1];
    
    ll ma=0;
    i=1;
    while(i<=n)
    {
        ma=max(ma,a[i]);
    while(i!=ma && i<n)
    {
       i++;
        ma=max(ma,a[i]);
    }
      an++;
      i++;  
    }
    cout << an;
}