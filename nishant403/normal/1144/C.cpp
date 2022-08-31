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
 ll n,k,i,j;
 string s;
    
cin >> n;
    
 ll a[n];
    f(i,n) cin >> a[i];
   
  sort(a,a+n);  
    
   f(i,n-2)
   {
       if(a[i]==a[i+1] && a[i+1] == a[i+2])
       {
           cout << "NO";
           return 0;
       }
   }
    
   cout << "YES\n"; 
   
    cout << (n+1)/2 << "\n";
    
   f(i,(n+1)/2 ) cout << a[i*2] << " "; 
     cout << "\n";
    
   cout << n - (n+1)/2 << "\n"; 
    
    ll z=n-1;
    if(n%2 == 1 ) z--;
    
   f(i,n-((n+1)/2) )
   {
    cout << a[z-(2*i)] << " " ;   
   }
    
}