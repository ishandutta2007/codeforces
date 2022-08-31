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
  int n,k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
  vi ava(26,0);  
    
    
    char ccc;
    
    f(i,k)
    {
    cin>>ccc;
    ava[ccc-'a'] = 1; 
    }
    
    int last = 0;
    
    while(last < n && ava[s[last]-'a'] == 0) last++;
 
   if(last == n)
   {
     cout << 0 ; return;   
   }
    
    int ans = 0;
    int cur = 1;
    
    for(int i=last;i<n;i++)
    {
        if(ava[s[i]-'a'] == 1)
        {
            ans+=cur;
            cur++;
        }
        else
        {
         cur = 1;   
        }
    }
    
    cout << ans;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}