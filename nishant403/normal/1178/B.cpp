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
    
int ans = 0;    
int n = s.length();    
    
vi pref(n,0);
    
f(i,n)
{
 if(i) pref[i] +=pref[i-1];   
 
if(i!=n-1)
{
 if(s[i] == s[i+1] && s[i] == 'v') pref[i]++;      
}
    
}
    
f(i,n)
{
 if(i==0 || i==n-1) continue;   
    
 if(s[i] == 'o')
 {       
   ans+=(pref[i]*(pref[n-1]-pref[i]));  
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