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
  int ans = 0;
  int zero = 0;
    
   f(i,n)
   {
    if(s[i]=='0') zero++;   
    else
    {
      int num = 0;   
      int len = 0; 
        
        for(int j=i;j<n;j++)
        {
            len++;
            num=(num*2);
            if(s[j]=='1') num++;
            if(num <= len+zero) ans++;
            else break;   
        }
        zero = 0;
    }
   }
    
    cout<< ans << "\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}