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
 ll n,k,i,j,m,an=99999;
 string s;
    
    cin >> n >> m;
    
   ll a[m];
    
    f(i,m) cin >> a[i];
    
    sort(a,a+m);
    
    f(i,m-n+1)
      an=min(an,a[i+n-1]-a[i]);
    
    cout << an;
}