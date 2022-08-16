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
 ll n,k,i,h,j,ans=0;
 string s;
    
 cin >> n >> h;
    
 ll a[n];
    f(i,n) cin >> a[i];
    
   for(i=1;i<=n;i++)
   {
        sort(a,a+i);
    ll sum=0;
   
    if(i%2)
    {
     for(j=i-1;j>0;j-=2) sum+=max(a[j],a[j-1]); 
    sum+=a[0];
    }
    else for(j=i-1;j>=0;j-=2) sum+=max(a[j],a[j-1]);
      
       if(sum>h) break;
       ans=i;
   }
    cout << ans;
}