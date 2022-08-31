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
    int n,p,k;
    cin >> n >> p >> k;
    
    int r=min(n,p+k);
    int l=max(1,p-k);
    
    if(l!=1) cout << "<< ";
    
    for(int i=l;i<=r;i++)
    {
     if(i==p) cout << "(" << i << ")" << " ";
     else cout << i << " " ;
    }
    
    if(r!=n) cout << ">>";
    
}