#include <bits/stdc++.h>
typedef long long lll;
using namespace std;
lll a[100001];

lll n,k,c,b;
lll sum(lll l,lll r){
   lll ll=1ll;
   lll rr=k;
   while (rr-ll>1ll){
      lll m=(rr+ll)/2ll;
      if (a[m]>=l) rr=m*1ll;
      else ll=m*1ll;
   }
   lll index1;
   if (a[ll]>=l) index1=ll*1ll;
   else if (a[rr]>=l) index1=rr*1ll;
   else index1=rr+1ll;
   ll=1ll;
   rr=k*1ll;
   while (rr-ll>1ll){
      lll m=(rr+ll)/2ll;
      if (a[m]<=r) ll=m*1ll;
      else rr=m*1ll;
     // cout<<ll<<" "<<rr<<endl;
   }
   //cout<<"OK";
   lll index2;
   if (a[rr]<=r) index2=rr*1ll;
   else if (a[ll]<=r) index2=ll*1ll;
   else index2=ll-1ll;
  // cout<<l<<" "<<r<<" "<<max(index2-index1+1ll,0ll)<<endl;
   return max(index2-index1+1ll,0ll);
}

lll f(lll l,lll r){
  // cout<<l<<" "<<r<<endl;
   lll p=sum(l,r);
   if (p==0ll) return c*1ll;
   if (l==r) return p*b*1ll;
   lll f1=f(l,l+(r-l+1ll)/2ll-1ll);
   if (f1>p*b*(r-l+1ll)) return p*b*(r-l+1ll);
   f1+=f(l+(r-l+1ll)/2ll,r);
   if (f1>p*b*(r-l+1ll)) return p*b*(r-l+1ll);
   return f1;
}

int main()
{

    cin>>n>>k>>c>>b;
    a[0]=-1ll;
    for (int i=1;i<=k;i++){
         cin>>a[i];
         a[i]*=1ll;
    }
    sort(a,a+k+1ll);
    cout<<f(1ll,(1ll<<n));

   /* int maxn=30;
    dp[0]=1;
    dp1[1]=2;
    for (int i=2;i<=maxn;i++){
        if (i%2==0){
            dp[i]=dp1[i-1]+dp[i-2];
        } else dp1[i]=2ll*dp[i-1]+dp1[i-2];
    }
    int n;cin>>n;
    while (n!=-1){
        cout<<dp[n]<<endl;
        cin>>n;
    }*/
    return 0;
}