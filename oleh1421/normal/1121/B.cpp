#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[200001];
int used[2000001];
int main()
{
   int n;cin>>n;
   for (int i=1;i<=n;i++) cin>>a[i];
   for (int i=1;i<n;i++){
       for (int j=i+1;j<=n;j++){
           used[a[i]+a[j]]++;
       }
   }
   int maxx=0;
   for (int i=1;i<=200000;i++) maxx=max(maxx,used[i]);
   cout<<maxx;
   return 0;
}