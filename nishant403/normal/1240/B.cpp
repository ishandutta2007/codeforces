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

//find longest increasing subsequence of complete elements.
//we need not to move those elements
//answer = n - length of lis
//but it can be calculated in two ways.
//either take the portion of first and last and one block
//or ignore it and count other blocks

//Mistake : lis must have consecutive elements
//when original unique array is sorted


void solve()
{
 int n;
 cin >> n;
    
 set<int> s;   
 map<int,int> mp;   
 map<int,int> first;   
 map<int,int> prev;
 
 int a[n];
    
 f(i,n) cin >> a[i];
    
 f(i,n) mp[a[i]] = i;   
 
 for(int i=n-1;i>=0;i--) first[a[i]] = i;
    
 f(i,n) s.insert(a[i]);
  
 int p = -1;
 
 for(auto x : s)
  {
  	prev[x] = p; p = x;
  }
  
 vector<int> d(n,0);
 
 f(i,n)
 {	
 	if(i!=first[a[i]]) continue;
 	
    if(mp[prev[a[i]]] < i && prev[a[i]] > 0) 
       d[i] = d[first[prev[a[i]]]];
       
       d[i]++;     	
 }
  
    int ans = 0;
    
    f(i,n)  ans = max(ans,d[i]);
    
    cout << ((int)s.size()-ans) << "\n";       
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}