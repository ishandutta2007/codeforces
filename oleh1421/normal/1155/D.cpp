#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[300003];
ll lefts[300003];
ll rights[300003];
ll maxl[300003];
ll s[300003];
int main()
{
   int n,x;cin>>n>>x;
   for (int i=1;i<=n;i++) cin>>a[i];
   ll sum=0ll;
   s[0]=0ll;
   ll maxx=0ll;
   for (int i=1;i<=n;i++){
        sum+=a[i]*1ll;
        sum=max(sum,0ll);
        maxx=max(maxx,sum);
        lefts[i]=sum;
        s[i]=(s[i-1]+a[i])*1ll;
   }
   sum=0ll;
   for (int i=n;i>=1;i--){
        sum+=a[i]*1ll;
        sum=max(sum,0ll);
        rights[i]=sum;
   }
   maxl[0]=0;
   for (int l=1;l<=n;l++){
       maxl[l]=max(maxl[l-1],lefts[l-1]-x*s[l-1]);
   }
   ll res=maxx*1ll;
   for (int r=1;r<=n;r++){
        res=max(res,rights[r+1]+s[r]*x+maxl[r]);
   }
   cout<<res;
   return 0;
}