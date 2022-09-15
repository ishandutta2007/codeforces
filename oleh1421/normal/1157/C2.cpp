#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[1000001];
int maxl(int l,int r){
    for (int i=l+1;i<=r;i++){
        if (a[i]<=a[i-1]) return (i-l);
    }
    return (r-l+1);
}
int maxr(int l,int r){
    for (int i=r-1;i>=l;i--){
        if (a[i]<=a[i+1]) return r-i;
    }
    return (r-l+1);
}
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
          int cur1=maxl(l,r);
          int cur2=maxr(l,r);
          if (cur1>cur2){
              for (int i=0;i<cur1;i++) ans+="L";
          } else for (int i=0;i<cur2;i++) ans+="R";
          break;
       }
   }
   cout<<ans.size()<<endl;
   cout<<ans;
   return 0;
}