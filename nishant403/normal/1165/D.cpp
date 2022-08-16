#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
    int t;
    cin>> t;
    while(t--)
    {
        
     int n,k;
        cin >> n;
     set<int> div;
        
        for(int i=0;i<n;i++) { cin >> k; div.insert(k); } 
            
       
        
        int guess = *div.begin();
        guess*=(*div.rbegin());
        
        for(int i = 2 ; i*i<=guess;i++)
        {
          if(guess % i == 0 )
          {
              if(div.find(i)==div.end())  { guess = -1; break; } 
              if(i*i != guess && div.find(guess/i)==div.end() ){ guess = -1; break; }
              
              div.erase(i);
              div.erase(guess/i);
          }
        }
        
        
        if(!div.empty()) guess = -1 ;
        
        cout <<guess << "\n";
       
    }
}