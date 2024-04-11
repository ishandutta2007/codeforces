#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n; cin>>n;
   int * a;
   a=new int[n+1];
   for(int i=1;i<=n;i++) cin>>a[i];
   vector<int> ans;
   int akt=1;
   vector<bool> czy(n+1,1);
   for(int i=0;i<n;i++)
   {
       int x; cin>>x;
       if(czy[x]==false) {ans.push_back(0); continue;}
       else
       {
           int odp=0;
           while(a[akt]!=x) {odp++; czy[a[akt]]=false; akt++;}
           czy[a[akt]]=false; akt++; odp++;
           ans.push_back(odp);
       }
   }
   for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    return 0;
}