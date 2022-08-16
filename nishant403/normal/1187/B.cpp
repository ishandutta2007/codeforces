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
    int n,m,k;
    string s,t;
    
    cin >> n >> s;
    
    int q;
    cin >> q;
    
    vector<int> c[26];
    
    for(int i=0;i<n;i++) c[s[i]-'a'].pb(i+1);
    
    while(q--)
    {
     cin >> t;   
        
     int d[26]={0}; 
     for(auto x : t) d[x-'a']++; 
          
     int ans = 0;     
       
    f(i,26) if(d[i] > 0 ) ans = max(ans,c[i][d[i]-1]);   
        
     cout << ans << "\n";
    }
    
}

signed main()
{
    fast;
    int t= 1;
   // cin >> t;
    while(t--)
    solve();
}