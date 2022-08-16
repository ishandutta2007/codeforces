#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define F first
#define S second
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
 fast;   
 int i,j,n,k;
 string s;
    
  cin >> n;
  
   priority_queue<int,vector<int>,greater<int> > q;
  
    string s1="insert";
    string s2="getMin";
    string s3="removeMin";
    
   vector<pair<string,int> > ans; 
    
   for(int i=0;i<n;i++)
   {
       cin >> s ;
       
       if(s!=s3) cin >> k;
             
       if(s==s1) q.push(k);
       else if(s==s2)
       {
           while(!q.empty() && q.top() < k)
           {
               ans.pb({s3,q.top()});
               q.pop();
           }
           
           if(q.empty())
           {
           ans.pb({s1,k});
           q.push(k);
           }
           
           else if(q.top() > k)
           {
               ans.pb({s1,k});
               q.push(k);
               
           }
           
       }
       
      else
      {
         if(q.empty())  ans.pb({s1,1});                   
         else q.pop();
      }
       
       ans.pb({s,k});
   }
    
    
    
    cout << ans.size() << "\n";
    
    for(auto x : ans) 
    {
     cout << x.first; 
        
      if(x.first != s3) cout << " " << x.second <<"\n";  
      else cout << "\n";  
    }
    
}