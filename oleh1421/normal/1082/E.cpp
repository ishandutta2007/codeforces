#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[500002];
int numk[500001];
int main()
{
   int n,c;cin>>n>>c;
   int cnt=0;
   for (int i=1;i<=n;i++){
       cin>>a[i];
       if (a[i]==c) cnt++;
   }
   int ans=0;
   int cur=0;
   for (int i=1;i<=n;i++){
       if (a[i]==c){
           cur++;
           continue;
       }
       int k=a[i];
       numk[k]=max(numk[k],cur)+1;
       ans=max(ans,numk[k]-cur);
   }
   cout<<ans+cnt;
   return 0;
}
/*
4
GSGS
*/