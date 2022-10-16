#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> xd(int n)
{
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0) ans.push_back(i);
    }
    return ans;
}

int main()
{
   int n,k;
   cin>>n>>k;
   vector<int> a=xd(n);
   for(int i=0;i<a.size();i++)
   for(int i=0;i<a.size();i++)
   {
       int t=n/a[i];
       if(t<k)
       {
           cout<<a[i]*k+t; return 0;
       }
   }
    return 0;
}