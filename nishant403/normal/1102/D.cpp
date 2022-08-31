#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string s;
    cin >> n;
    cin >> s;
    int count[3]={0};
    for(int i=0;i<s.size();i++)
{
    count[s[i]-'0']++;
}
int repl=0;

for(int i=0;i<3;i++) repl+=abs(n/3 - count[i]);
repl/=2;

for(int i=0;i<n;i++)
{
  if(count[s[i]-'0'] > n/3 )
 {
   if(s[i]-'0' ==2)
   {
       if(count[0] < n/3)
       {
           s[i]='0';
           count[0]++;
           count[2]--;
       }
       else if(count[1] < n/3)
       {
           s[i]='1';
           count[1]++;
           count[2]--;
       }
       
   }
   else if(s[i]-'0'==1)
   {
   if(count[0] < n/3)
       {
           s[i]='0';
           count[0]++;
           count[1]--;
       }
   } 
     
     
     
 } 
}

for(int i=s.size()-1;i>=0;i--)
{
    if(count [ s[i]-'0' ] > n/3)
    {
     if(s[i]-'0'==0)
     {
         if(count[2] < n/3)
         {
             s[i]='2';
             count[2]++;
             count[0]--;
             
         }
         else if(count[1] < n/3)
         {
          s[i]='1';
          count[1]++;
          count[0]--;
         }
     }
     else if(s[i]-'0'==1)
     {
      if(count[2] < n/3)
      {
          s[i]='2';
          count[2]++;
          count[1]--;
      }
         
         
     }
        
        
        
        
        
     
     
     
     
     
        
    }
}

cout << s;

   return 0;
}