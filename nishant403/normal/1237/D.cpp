#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

void solve()
{
 int n;
 cin >> n;
    
 int a[n];   
 f(i,n) cin >> a[i];
    
 int mx = a[0];
 int mn = a[0];
    
 f(i,n) mx=max(mx,a[i]);
 f(i,n) mn=min(mn,a[i]);
    
 if( mn*2 >= mx)
 {
   f(i,n) cout << -1 <<" "; return;   
 }
 
 int b[2*n];
 f(i,n) b[i] = a[i];
 f(i,n) b[i+n] = a[i];
    
    
    
 stack<int> s;
 vi nge(2*n,-1);
  
 f(i,2*n)
 {
   while(!s.empty() && b[s.top()] < b[i])
   {
     nge[s.top()] = i; s.pop();
   }
   s.push(i);  
 }
    
 vi nse(2*n,-1);  
 multimap<int,int> mp;   
    
 f(i,2*n)
 {
    while(!mp.empty())
    {
       auto v = mp.upper_bound((2*b[i]));
        
       if(v==mp.end()) break;
       
       nse[v->S] = i; 
        
       mp.erase(v); 
    }
     
   mp.insert({b[i],i}); 
     
 }
    
 pii process[n];
    
 f(i,n) process[i].F = a[i],process[i].S = i;
    
 sort(process,process+n);   
 reverse(process,process+n);   
    
 //process them in this order
 int ans[2*n];   
    
 f(i,n) ans[i] = 1e10;   
    
 f(i,n)
 {
     
   if(nse[process[i].S] != -1)  
ans[process[i].S] =  
    min(ans[process[i].S],nse[process[i].S] - process[i].S);  
    
     
if(nge[process[i].S] != -1)
    ans[process[i].S] =
        min(ans[process[i].S],nge[process[i].S]-process[i].S+
               ans[nge[process[i].S]]);
     
  ans[process[i].S + n] = ans[process[i].S];
     
 }
    
  f(i,n) cout << ans[i] <<" ";  
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}