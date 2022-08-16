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
    
    string s;
    cin >> s;
    
    int ones = 0,zero = 0;
    
    for(auto x  : s) if(x=='0') zero++;
                     else ones++;
        
     if(ones!=zero) 
    {
      cout  << 1 << endl;
        cout << s;
    }
    else
    {
     cout << 2 << "\n";
        
     cout << s[0] << "\n"; 
        
     for(int i=1;i<n;i++) cout << s[i];
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