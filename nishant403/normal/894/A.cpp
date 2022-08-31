#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define F first
#define S second
#define Fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f(i,n) for(int i=0;i<n;i++)
#define vi vector<int> 
#define pii pair<int,int>

void solve()
{
    string s;
    cin >> s;
    
    int n = s.length();
    int ans = 0;
    
    vi pre(n+1,0);
    
    for(int i=1;i<=n;i++) pre[i] = pre[i-1]+(s[i-1]=='Q');
    
    for(int i=0;i<n;i++)
     if(s[i] == 'A') ans+=pre[i]*(pre[n] - pre[i]);   
       
    cout << ans;
}

signed main()
{
 Fast;
 solve();
}