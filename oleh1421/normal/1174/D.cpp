#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool used[400001];
int32_t main() {
   int n,x;cin>>n>>x;
   if (n==1){
      if (x==1) cout<<0;
      else cout<<1<<endl<<1;
      return 0;
   }
   for (int i=0;i<(1<<n);i++){
       int j=(i^x);
       if (j>i) used[j]=true;
   }
   int k=n;
   vector<int>v;
   int sum=0;
   for (int i=1;i<(1<<n);i++){
       if (used[i]) continue;
       v.push_back(i^sum);
       sum=i;
   }
   cout<<v.size()<<endl;
   for (auto i:v) cout<<i<<" ";
   return 0;
}
/*
2 2 1 1 1
1 2
3 4
*/