#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long int mod=1000000007;

int main()
{
   string s; cin>>s;
   string res="";
   for(int i=0;i<s.length();i++)
   {
       if(s[i]=='a' || s[i]=='b') res+=s[i];
   }
   s=res;
   int n=s.length();
   int lastb=-1;
   int lasta=-1;
   long long int akt=0;
   int wsk=-1;
   vector<long long int> dp(n,0);
   for(int i=0;i<n;i++)
   {
       if(s[i]=='a')
       {
           lasta=i;

            if(lastb==-1) dp[i]=1;
            else
            {
                dp[i]=1+akt;
            }


       }
       else
       {
           lastb=i;
           while(wsk<lastb-1)
           {
               wsk++;
               if(s[wsk]=='a')
               {
                   akt+=dp[wsk];
                   akt%=mod;
               }
           }
           if(lasta!=-1)
           {
               dp[i]=dp[lasta];
           }
           else
           {
               dp[i]=0;
           }


       }
   }
   long long int ans=0;
   for(int i=0;i<n;i++)
   {
       if(s[i]=='a')
       {
           ans+=dp[i];
           ans%=mod;
       }
   }
   cout<<ans;

    return 0;
}