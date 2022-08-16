#include <bits/stdc++.h>
using namespace std;

#define int long long 

int check(int start,string &s)
{
   int mm = s.length();
   
  
   return mm;
}

signed main()
{
    string s;
    getline(cin,s);
    
    int ans =0;
    int i,j,k;
    int t =0;
    int n = s.length();
    
    for(i=0;i<n;i++)
    {
    
    int val = n;
    
   for(j=i ;j<min(n,i+8);j++)
   {
       for(k=1;j+2*k<n && k<10;k++)
       {
           if(s[j] == s[j+k] && s[j]==s[j+2*k])
              val = min(val,j+2*k);
       }
   }
     
     ans+=(n-val);
    }
    
    cout << ans;
}