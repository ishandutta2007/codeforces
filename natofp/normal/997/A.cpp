#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
   long long int n,x,y;
   cin>>n>>x>>y;
   string s;
   cin>>s;
   int w=0;
   int a=0;
   int b=0;
   for(int i=0;i<n;i++)
   {
       if(s[i]=='0')
       {
           if(a==0) w++;
           a++;
           b=0;
       }
       else
       {
           a=0;
           b++;
       }

   }

   long long e,f;
   e=x*(w-1)+y;
   f=w*y;
   if(min(e,f)<0) cout<<"0";
   else cout<<min(e,f);
    return 0;
}