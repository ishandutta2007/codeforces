#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(i,n) for(i=0;i<n;i++)
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main()
{
    fio;
    ll n,i,j,ans=0;
    cin >> n ;
     int a[n];
    
    f(i,n) cin >> a[i];
    
    sort(a,a+n);
    
    ll l,r,temp;

    
    for(i=a[0]+a[1] ;i<=a[n-1]+a[n-2];i++)
    {
    temp=l=0;
    r=n-1; 
      
    while(l<r)
    {
        if(a[l] + a[r] == i) { temp++;  l++; r--;  }   
    else if(a[l] + a[r] > i )  r--;
        else l++;
    }
        
    ans=max(ans,temp);
    
    }
    
         cout << ans;
    
    
 return 0;   
}