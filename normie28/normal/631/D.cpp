#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
const int mx=1e6+10;
const int mxt=mx+mx;
pair<uli,char>a[mx],b[mx];
pair<uli,char>t[mxt];
int z[mxt];
 
void zeta(int n){
   int l = -1, r = -1;
   for(int i=1;i<n;i++){
      if(r<i){
         l = r = i;
         while(r<n && t[r]==t[r-i]) r++;
         r--;
         z[i] = r-l+1;
      }
      else{
         int rr = min(i+z[i-l],r);
         while(rr<n && t[rr]==t[rr-i]) rr++;
         rr--;
         z[i] = rr-i+1;
         if(rr>r) l = i, r = rr;
      }
   }
}
 
int main(){
   int n,m;
   cin>>n>>m;
   for(int i=0;i<n;i++)scanf("%lld-%c",&a[i].first,&a[i].second);
   for(int i=0;i<m;i++)scanf("%lld-%c",&b[i].first,&b[i].second);
   int c=0;
   for(int i=0;i<n;){
      char ch=a[i].second;
      uli len=0;
      while(i<n && a[i].second==ch)len+=a[i++].first;
      a[c++]=pair<uli,char>(len,ch);
   }
   n=c;
   c=0;
   for(int i=0;i<m;){
      char ch=b[i].second;
      uli len=0;
      while(i<m && b[i].second==ch)len+=b[i++].first;
      b[c++]=pair<uli,char>(len,ch);
   }
   m=c;
   uli ans=0;
   if(m==1){
      for(int i=0;i<n;i++){
         if(a[i].first>=b[0].first && a[i].second==b[0].second){
            ans+=a[i].first-b[0].first+1ll;
         }
      }
   }
   else{
      c=0;
      for(int i=1;i<m-1;i++)t[c++]=b[i];
      for(int i=0;i<n;i++)t[c++]=a[i];
      //    for(int i=0;i<c;i++)cout<<t[i].first<<"("<<t[i].second<<")"<<" ";cout<<endl;
      zeta(c);
      for(int i=m-2;i+m<=c;i++){
         if(t[i].first>=b[0].first && t[i].second==b[0].second){
            if(z[i+1]>=m-2){
               int j=i+m-1;
               if(t[j].first>=b[m-1].first && t[j].second==b[m-1].second){
                  ans++;
               }
            }
         }
      }
   }
   cout<<ans;
}