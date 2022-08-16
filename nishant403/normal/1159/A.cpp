#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define pll pair<long long,long long>
#define vl vector<ll> 
#define int long long  

signed main()
{
 fast;   
 ll n,k,i,j;
 string s;
    
    
  cin >> n;
    cin >> s;
    
    ll a=0;
    ll b=0;
    for(i=0;i<n;i++){
     if(s[i]=='+') b++; 
     else if(b>0) b--;
        
    }
    cout << b;
}