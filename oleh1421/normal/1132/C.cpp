
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const long long mod=1000000007ll;
int s0[5002];
int s1[5002];
int s2[5002];
int a[5002];
int fs0(int l,int r){
    return s0[r]-s0[l-1];
}
int fs1(int l,int r){
    return s1[r]-s1[l-1];
}
int fs2(int l,int r){
    return s2[r]-s2[l-1];
}
int main()
{
   int n,q;cin>>n>>q;
   vector<pair<int,int> >v;
   for (int i=1;i<=q;i++){
       int l,r;cin>>l>>r;
       v.push_back({l,r});
       for (int j=l;j<=r;j++) a[j]++;
   }
   sort(v.begin(),v.end());
   for (int j=1;j<=n;j++){
           s0[j]=s0[j-1]+(a[j]>0);
           s1[j]=s1[j-1]+(a[j]>1);
           s2[j]=s2[j-1]+(a[j]>2);
   }
   int res=0;
   for (int i=0;i<q-1;i++){
       for (int j=i+1;j<q;j++){
            int l1=v[i].first;
            int r1=v[i].second;
            int l2=v[j].first;
            int r2=v[j].second;
            int cur=0;
            if (r1<l2){
                cur=(fs0(1,l1-1)+fs1(l1,r1)+fs0(r1+1,l2-1)+fs1(l2,r2)+fs0(r2+1,n));
            } else if (l1<=l2 && r2<=r1){
                cur=(fs0(1,l1-1)+fs1(l1,l2-1)+fs2(l2,r2)+fs1(r2+1,r1)+fs0(r1+1,n));
            } else {
                cur=(fs0(1,l1-1)+fs1(l1,l2-1)+fs2(l2,r1)+fs1(r1+1,r2)+fs0(r2+1,n));
            }
            res=max(res,cur);
       }
   }
   cout<<res;
   return 0;
}