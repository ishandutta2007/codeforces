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

ll gcd(ll a,ll b)
{
 if(b==0) return a;   
    return gcd(b,a%b);
}

int main()
{
 fast;   
 ll n,k,i,m,j,a=0;
 string s;
    
 cin >> n >> m;
    
 ll x[n];
 ll p[m];
    
    
    f(i,n) cin >> x[i];
    f(i,m) cin >> p[i];
    
    long long int gc = (x[1]-x[0]);
    
   f(i,n-1)
   {
    gc=gcd(gc,x[i+1]-x[i]);      
   }
    
 long long    int dd = -1;
    
    
   f(i,m)
   {
       if((gc % p[i]) == 0) {dd=i; break;}    
   }
    
    
    if(dd==-1) cout << "NO";
    else {
        cout << "YES\n";
    cout << x[0] <<" ";
        cout << dd+1;
            
    }
    
}