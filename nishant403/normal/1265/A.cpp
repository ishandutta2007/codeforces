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
    
 int n = s.length();
     
    
 vector<char> cc = {'a','b','c'};   
    
 f(i,n)
 {
     if(s[i] != '?') continue;
     
     set<char> st(cc.begin(),cc.end());
     
     if(i!=0) st.erase(s[i-1]);
     if(i!=n-1) st.erase(s[i+1]);
     
     s[i] = (*st.begin());
 }
    
     
 f(i,n-1) if(s[i] == s[i+1])
 {
     cout<<"-1\n"; return;
 }
    
  cout << s << '\n';  
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}