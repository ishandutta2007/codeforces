//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define int long long
using namespace std;
int lcm(int a,int b)
{
    return (a*b)/(__gcd(a,b));
}
int a[209];
main()
{
   int n,ans=1;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i];
   }
   for(int i=1;i<=n;i++)
   {
       int nxt=a[i];
       int cnt=1;
       while(nxt!=i)
       {
           nxt=a[nxt];
           cnt++;
           if(cnt>1000 || a[nxt]==nxt)
           {
               cout<<"-1"<<endl;
               return 0;
           }
 
       }
         if(cnt%2==0)cnt=cnt/2;
           ans=lcm(ans,cnt);
 
   }
cout<<ans<<endl;
return 0;
}