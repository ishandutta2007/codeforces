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
    
 sort(a,a+n);
    
 int last = 0;
 
  map<int,int> mp;  
    
 mp[0] = 1;   
    
 f(i,n)
 {
   if(mp.find(a[i]-1) == mp.end())
   {
     mp[a[i]-1] = 1;   
   }
   else if(mp.find(a[i]) == mp.end())
   {
     mp[a[i]]=1;   
   }
   else if(mp.find(a[i]+1) == mp.end())
   {
     mp[a[i]+1] = 1;   
   }
     
 }
    cout << (int)mp.size()-1;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}