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
 int n;
 cin >> n;
    
    int a[] = {100,20,10,5,1};
    
    int ans = 0;
    
    for(auto x : a)
    {
     ans+=(n/x);   
     n%=x;   
    }
    
    cout << ans;
    
}

signed main()
{
 Fast;
 solve();
}