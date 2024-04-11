#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[200001];
int main() {
   int n,z;cin>>n>>z;
   for (int i=1;i<=n;i++) cin>>x[i];
   sort(x+1,x+n+1);
   int i=1;
   int j=n/2+1;
   int cnt=0;
   while (j<=n && i<=n/2){
       if (x[j]-x[i]>=z){
          cnt++;
          i++;
          j++;
       } else j++;
   }
   cout<<cnt;
   return 0;
}
/*
6 7
1 2
2 3
1 3
4 5
5 6
4 6
3 4
*/