#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[100001];
int main()
{
   int n;cin>>n;
   for (int i=1;i<=n;i++){
       cin>>a[i];
   }
   for (int i=1;i<n;i++){
       if ((a[i]==3 && a[i+1]==2)||(a[i]==2 && a[i+1]==3)){
          cout<<"Infinite";
          return 0;
       }
   }
   int res=0;
   if (a[2]==1){
      if (a[1]==3) res+=4;
      else res+=3;
   } else if (a[2]==2){
       res+=3;
   } else res+=4;
   for (int i=3;i<=n;i++){
       if (a[i]==1) {
           if (a[i-1]==3) res+=4;
           else res+=3;
       }
       else if (a[i]==2) {
            if (a[i-2]==3) res+=2;
            else res+=3;
       } else res+=4;
   }
   cout<<"Finite"<<endl<<res;
   return 0;
}