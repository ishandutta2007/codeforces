#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[300001];
int32_t main() {
   int n;cin>>n;
   for (int i=1;i<=2*n;i++) cin>>a[i];
   sort(a+1,a+1+n+n);

   if (a[1]==a[n+n]) cout<<-1;
   else for (int i=1;i<=n+n;i++) cout<<a[i]<<" ";
   return 0;
}
/*
2 2 1 1 1
1 2
3 4
*/