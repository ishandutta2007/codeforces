#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   long long int a,b;
   cin>>a>>b;
   long long int n=a+b;
   long long int i=0;
   while(i*(i+1)/2<=n) i++;
   if(i*(i+1)/2>n) i--;
   vector<int> ans;
   vector<int> ans2;
   for(int x=i;x>=1;x--)
   {
       if(x<=a) {ans.push_back(x); a-=x;}
       else
       {
           ans2.push_back(x); b-=x;
       }
   }
   cout<<ans.size()<<endl;
   for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
   cout<<endl;
   cout<<ans2.size()<<endl;
   for(int i=0;i<ans2.size();i++) cout<<ans2[i]<<" ";

    return 0;
}