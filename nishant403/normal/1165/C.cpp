#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
    
    int l;
    cin >> l;
    
    string a,b;
    cin >> a;
    
    int x = 0;
  
    queue<char>q,q2;
    
    for(auto c : a)q.push(c);
    
    while(!q.empty() )
    {
     char p = q.front();
     q.pop();
        
      while(!q.empty() && p==q.front() )
      q.pop();
          
      if(q.empty() ) break;    
      
          q2.push(p);
          q2.push(q.front());
          q.pop();
    }
     
    cout <<  (int)a.length() - q2.size() << "\n";
  
    
    while(!q2.empty())
    {
     cout << q2.front() ;
        q2.pop();   
    }
}