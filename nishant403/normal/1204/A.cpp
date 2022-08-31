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
    
    if(s=="0" || s=="1") {cout << 0; return; }
    
    int ans = 1;
    
    int zeros = (n-1)/2;
    
    if(n%2==1)
    {
     int flag = 1;
       
     for(int i=1;i<n;i++) if(s[i]=='1') flag = 0;
         
     ans-=flag;   
    }
    
    cout << ans+zeros;
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}