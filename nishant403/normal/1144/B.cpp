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
    
  vector<ll> o,e;
    f(i,n) if(a[i]%2) o.pb(a[i]);
        else e.pb(a[i]);
   
        sort(o.begin(),o.end());
    sort(e.begin(),e.end());
    
   if( abs ( o.size() -e.size() ) <= 1 ) 
   {
    cout << 0 ;   
   }
       else
       {
         ll sum=0;
           if(e.size() > o.size() )
         f(i,e.size()-o.size() -1) sum+=  e[i];
        
        else f(i,o.size()-e.size() - 1) sum+=o[i];   
           cout << sum ;
       }
        
        
}