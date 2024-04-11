#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int k;
   cin>>k;
   if(k>36) {cout<<"-1"; return 0;}
   string odp="";
   while(k>1)
   {
       odp+='8'; k-=2;
   }
   if(k==1) odp+='4';
   cout<<odp;
       
   
    return 0;
}