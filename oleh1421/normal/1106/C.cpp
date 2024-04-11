#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[300000];
int main()
{
   int n;cin>>n;
   for (int i=0;i<n;i++) cin>>a[i];
   sort(a,a+n);
   ll sum=0;
   for (int i=0;i<(n/2);i++){
       sum+=(a[i]+a[n-i-1])*(a[i]+a[n-i-1])*1ll;
   }
   cout<<sum;
   return 0;
}