#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[300001];
bool used[200001];
int p[200001];
int f(int n){
    for (int i=2;i*i<=n;i++){
        if (n%i==0) return i;
    }
    return n;
}
int32_t main() {
   int n;cin>>n;
   for (int i=2;i<=n;i++) used[i]=true;
   int cnt=0;
   for (int i=2;i*i<=n;i++){
       if (!used[i]) continue;
       p[i]=++cnt;
       for (int j=i*i;j<=n;j+=i){
           used[j]=false;
       }
   }
   for (int i=2;i<=n;i++){
       if (!used[i]) continue;
       if (p[i]) continue;
       p[i]=++cnt;
   }
   for (int i=2;i<=n;i++){
       cout<<p[f(i)]<<" ";
   }
   return 0;
}
/*
2 2 1 1 1
1 2
3 4
*/