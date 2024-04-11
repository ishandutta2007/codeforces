#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
typedef long long ll;
using namespace std;

bool is_c(ll a){
   ll x=sqrt(a);
   return (x*x==a);
}
int main()
{
   int ans,k,n;
   cin>>n;bool a[n+1];
   for (int i=1;i<=n;i++) cin>>a[i];
   k=0;
   ans=0;
   for (int i=2;i<n;i++){
       if (a[i-1]==1 && a[i+1]==1 && a[i]==0){
           k++;
       }
   }
   while (k>0){
     int minx=k;
     int index=-1;
      for (int j=1;j<=n;j++){
        if (a[j]==1){
           a[j]=0;
           int m=0;
           for (int i=2;i<n;i++){
                //cout<<a[i-1]<<" "<<a[i]<<" "<<a[i+1]<<endl;
                if (a[i-1]==1 && a[i+1]==1 && a[i]==0){
                    m++;
                }
           }
           //cout<<m<<endl;
           if (m<minx){
               minx=m;
               index=j;
           }
           a[j]=1;
        }
      }
      a[index]=0;
     // cout<<index<<" "<<minx<<endl;
      k=minx;
      ans++;
   }
   cout<<ans;
   return 0;
}