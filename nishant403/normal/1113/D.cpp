#include <bits/stdc++.h>
#define over return 0;
#define f(i,n) for(i=0;i<n;i++)
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    faster

    string s;
    cin >> s;
    int i,j=0,n=s.size(),k1,k2;
 
   f(i,n/2-1) if(s[i]!=s[i+1]) break;
    
    if(i==n/2-1 || n<=3) { 
        cout << "Impossible"; over
    }
  
  f(i,n/2)
  {
     if(s[i]!=s[i+1]) continue;    
     k1=k2=0;
     
     f(j,n/2)
     {
         if(s[(i-j+n)%n]!=s[(i+j+1)%n]) k1=1;
         if(s[j]!=s[(i+j+1)%n]) k2=1;
     }   
        if(!k1 & k2) {
            cout << 1; over }
  }
 cout << 2;
}