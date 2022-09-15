#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool used[1000001];
int main()
{
   int n;cin>>n;

   for (int i=2;i<=1000000;i++) used[i]=true;

   for (int i=2;i<=1000;i++){
       if (used[i]){
          for (int j=i*i;j<=1000000;j+=i){
              used[j]=false;
          }
       }
   }
   int cnt1=0;
   int cnt2=0;
   for (int i=0;i<n;i++){
       int a;cin>>a;
       cnt1+=(a==1);
       cnt2+=(a==2);
   }
   vector<int>ans;
   int cur=0;
   for (int i=0;i<n;i++){
       if (cnt1==0) ans.push_back(2);
       else if (cnt2==0) ans.push_back(1);
       else if (used[cur+1]>used[cur+2]){
          ans.push_back(1);
          cnt1--;
          cur++;
       } else {
          ans.push_back(2);
          cnt2--;
          cur+=2;
       }
   }
   for (auto i:ans) cout<<i<<" ";


   return 0;
}