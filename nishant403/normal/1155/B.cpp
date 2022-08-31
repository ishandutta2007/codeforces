#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
int main()
{
 string s;
    int n;
   cin >> n; 
   cin >> s;
   
  int m = (n - 11)/2;
  int i,t=m;  
  int way = 0;
    
    f(i,n)
    {
      if(s[i]!='8')
      {
       if(t==0) break;
       else t--;
      }
      else way++;  
    }
    
    if(way > m) cout << "YES\n";
    else cout << "NO\n";
}