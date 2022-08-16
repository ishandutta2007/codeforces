#include <bits/stdc++.h>
using namespace std;

#define int long long 

signed main()
{
 int n,i,m,k=0;   
    
 cin >> n >> m;
 
 int a[n];
 for(i=0;i<n;i++) cin >> a[i];
 
 for(i=0;i<m;i++) k+=a[i];
 
 int ans = 1;
 int sum = k;
 
 for(int i=m;i<n;i++)
 {
  sum-=a[i-m];
  sum+=a[i];
  if(sum < k) k = sum,ans=i-m+2;
     
 }
 
 cout << ans;
}