#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[500002];
int main()
{
   int n;cin>>n;
   int ans=1000000001;
   int tans=0;
   for (int i=1;i<=n;i++) cin>>a[i];
   for (int t=1;t<=100;t++){
       int cur=0;
       for (int i=1;i<=n;i++) cur+=max(abs(a[i]-t)-1,0);
       if (cur<ans){
           ans=cur;
           tans=t;
       }
   }
   cout<<tans<<" "<<ans;
   return 0;
}
/*
4
GSGS
*/