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
    ll a[101]={0};
    ll int n,i,l,r;
    pll x;
    
    cin >> n;
   
    
    f(i,n)
    {
    cin >> l >> r;
   
    for(int j=l;j<r;j++) a[j]++;
        
    if(i==0)x={l,r};   
        
    }

cout << count(a+x.F,a+x.S,1);
    }