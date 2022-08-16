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
  string s;
  cin >> s;
    
  int n =s.length();
    
  map<char,int> mp;
    
  char c = s[0];  
    
   cout <<"Mike\n";
    
   f(i,n)
   {
       if(i==0) continue;
       
       if(c < s[i])  cout <<"Ann\n";   
       else cout <<"Mike\n";
       
       c = min(c,s[i]);
   }
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}