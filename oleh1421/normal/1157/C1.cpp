#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[1000001];

int main()
{
   int n;cin>>n;
   for (int i=1;i<=n;i++) cin>>a[i];
   int l=1;
   int r=n;
   string ans="";
   int last=0;
   while (l<=r && (a[l]>last || a[r]>last)){
       //cout<<l<<" "<<r<<" "<<last<<endl;
       if (a[l]<a[r]){
           if (a[l]>last){
              last=a[l];
              ans+="L";
              l++;
           } else {
              last=a[r];
              ans+="R";
              r--;
           }
       } else if (a[l]>a[r]){
          if (a[r]>last) {
              last=a[r];
              ans+="R";
              r--;
           }
           else {
              last=a[l];
              ans+="L";
              l++;
           }
       } else {
          ans+="L";
          l++;
       }
   }
   cout<<ans.size()<<endl;
   cout<<ans;
   return 0;
}