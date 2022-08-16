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
    int n,x,prev = -1,temp=0,ans = 0;
    
    cin >> n;
 
    f(i,n)
    {
        cin >> x;
        if(x <= prev) temp=0;
        
        ans = max(ans,++temp);
        prev = x;
    }
    
    cout << ans;
}

signed main()
{
 Fast;
 solve();
}