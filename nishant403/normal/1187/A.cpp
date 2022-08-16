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
    int m,k,ans = 0;
    
    int n,s,t; 
    
    cin >> n >> s >> t;
    
    cout << max(n-s+1,n-t+1) << "\n";
}

signed main()
{
    fast;
    int t= 1;
    cin >> t;
    while(t--)
    solve();
}