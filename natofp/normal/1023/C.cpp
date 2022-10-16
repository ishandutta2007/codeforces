#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int k,n;
    string s;
    cin>>n>>k>>s;
   string w="";
   int a=0;
   int b=0;
   int t=n;
   n/=2;
   k/=2;
   for(int i=0;i<t;i++)
   {
       if(s[i]=='(')
       {
           if(a<k)
           {
               a++;
               w+=char('(');
           }

       }
       else
       {
           b++;
           if(b>(n-k))
           {
               w+=')';
           }
       }
   }
   cout<<w;


    return 0;
}