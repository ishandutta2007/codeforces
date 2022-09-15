#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
int d[200001];
int32_t main()
{
   int H,n;cin>>H>>n;
   for (int i=0;i<n;i++) cin>>d[i];
   int s=H;
   int minx=H;
   for (int i=0;i<n;i++){
       s+=d[i];
       minx=min(minx,s);
       if (s<=0){
          cout<<i+1;
          return 0;
       }
   }
   if (s>=H){
      cout<<-1;
      return 0;
   }
   int sum=H-s;
   int res=((minx)/sum)*n;
   H-=((minx)/sum)*sum;
   if (H>0){
   for (int i=0;i<n*100;i++){
       H+=d[i%n];
       res++;
       if (H<=0) break;
   }
   }
   cout<<res;
   return 0;
}