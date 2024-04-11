#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[500002];
int c[33];
int main()
{
   int n,k;cin>>n>>k;
   string s;cin>>s;
   int res=0;
   for (int d=0;d<='z'-'a';d++){
       int cnt=0;
       int cur=0;
       for (int i=0;i<n;i++){
           if ((s[i]-'a')==d){
               cnt++;
               if (cnt==k){
                   cur++;
                   cnt=0;
               }
           }
           else cnt=0;
       }
       res=max(res,cur);
   }
   cout<<res;
   return 0;
}
/*
4
GSGS
*/