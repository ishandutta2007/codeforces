#include<bits/stdc++.h>
#define int long long
#define MAXN 999999
using namespace std;

int a[10010];
int n,m,ans,minn=MAXN,k,sum;

signed main()
{
   cin>>n>>m>>k;
   for(int i=1;i<=n;++i)
   {
      cin>>a[i];
      if(minn>a[i]&&i%2==1)
          minn=a[i];
   }
   sum=n/2+1;
   if(n%2==0||sum>m);
   else
   {
       ans=m/sum*k;
       ans=min(minn,ans);
   }
   cout<<ans<<endl;
   return 0;
}