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
 int m;
    
 cin >> n >> m;
    
 string s[n];
    
 f(i,n) cin >> s[i];
    
 int a[m];
    
 f(i,m) cin >> a[i];
    
 int cn[m][5];
    
 f(i,m) f(j,5) cn[i][j] = 0;
    
 int ans = 0;   
    
 f(i,m)
 {
    f(j,n) cn[i][s[j][i]-'A']++;
     
    int hh = 0;
     
    f(j,5) hh = max(hh,cn[i][j]);
     
    ans+=a[i]*hh;
     
     
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