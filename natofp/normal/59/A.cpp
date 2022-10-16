#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   string s; cin>>s;
   int ile=0;
   for(int i=0;i<s.length();i++)
   {
       if(s[i]>='a' && s[i]<='z') ile++;
   }
   if(ile*2>=s.length())
   {
       for(int i=0;i<s.length();i++)
       {
           if(s[i]>='A' && s[i]<='Z') s[i]+=32;
       }
   }
   else
   {
       for(int i=0;i<s.length();i++)
       {
           if(s[i]>='a' && s[i]<='z') s[i]-=32;
       }
   }
   cout<<s;
    return 0;
}