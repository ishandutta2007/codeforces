#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[300001];
int32_t main() {
   int n;cin>>n;
   for (int i=1;i<=n;i++) cin>>a[i];
   int sum=0;
   for (int i=1;i<=n;i++) sum+=a[i]%2;
   if (sum<n && sum>0) sort(a+1,a+n+1);
   for (int i=1;i<=n;i++) cout<<a[i]<<" ";
   return 0;
}
/*
2 2 1 1 1
1 2
3 4
*/