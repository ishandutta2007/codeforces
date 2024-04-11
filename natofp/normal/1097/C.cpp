#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=1e6+5;
vector<int> suf(N,0);
vector<int> pre(N,0);
int main()
{
   int n; cin>>n;
   string * a=new string [n];
   for(int i=0;i<n;i++) cin>>a[i];
   multiset<pair<int,int> > lol;
   for(int i=0;i<n;i++)
   {
       string t=a[i];
       int wyn=0;
       bool czy=true;
       int peak=0;
       for(int j=0;j<t.length();j++)
       {
           if(t[j]=='(') wyn++;
           else wyn--;
           if(wyn<0) czy=false;
           peak=min(peak,wyn);
       }
       if(czy) pre[wyn]++;
       else if(wyn<=0)
       {
           if(abs(peak)<=abs(wyn))
           {

               suf[abs(wyn)]++;
           }
       }


   }
   int ans=0;
   for(int i=1;i<=500000;i++)
   {
       if(pre[i]>0)
       {
           ans+=min(pre[i],suf[i]);
       }
   }
   ans+=(pre[0]+suf[0])/2;
   cout<<ans;
    return 0;
}