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
   
    cin >> n >> m;
 
    ll a[n];
    ll b[n];
    f(i,n) cin >> a[i];
        
    set<ll> s;
    f(i,n) 
    {
     s.insert(a[n-i-1]);
     b[n-i-1]=s.size();
    }   
     
    f(i,m)
    {
        cin >> j;
        cout << b[j-1] << "\n";
    }
   
}