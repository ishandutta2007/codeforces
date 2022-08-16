#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define F first
#define S second

signed main()
{
 ios_base::sync_with_stdio(0);   
 cin.tie(0);
 cout.tie(0);
  
  int n,x;   
  cin >> n;   
 
  map<int,int> mp;
  mp[4]=1;
  mp[8]=2;
  mp[15]=3;
  mp[16]=4;
  mp[23]=5;
  mp[42]=6;
  
  queue<int> q;  
    
  f(i,n)
  {
  cin >> x;    
  q.push(mp[x]);    
  }
    
    int ans[7] = { 0 };
    
   while(!q.empty())
   {
    x = q.front(); q.pop();
       
       if(x>1 && ans[x-1] > 0) {ans[x]++; ans[x-1]--;}   
       else if(x==1) ans[1]++;      
   }
    
   cout << n-(ans[6]*6); 
    
}