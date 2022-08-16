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
 ll n,k,i,j,ans=0;
 string s;
    
 cin >> n;
    ll a[n];
 f(i,n)    cin >> a[i];
    
 f(i,n)
 {
     if(a[i]!=a[0]) ans=max(ans,i);
     if(a[i]!=a[n-1]) ans=max(ans,n-i-1);
 }
  cout << ans;  
}