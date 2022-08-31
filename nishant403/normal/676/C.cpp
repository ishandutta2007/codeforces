#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
 int i,j,n,k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    int first = 0;
    int conv = 0;
    int ans = 0;
    
    for(int last=0;last<n;last++)
    {
     if(s[last]=='b') conv++;   
      while(conv > k) { if(s[first]=='b') conv--; first++;  }
        
         ans=max(ans,last-first+1);   
    }
    
    first = 0;
    conv = 0;
    
    for(int last=0;last<n;last++)
    {
     if(s[last]=='a') conv++;   
        while(conv > k) { if(s[first]=='a') conv--; first++;  }
         ans=max(ans,last-first+1);   
    }
    
    
    
    cout << ans;
}