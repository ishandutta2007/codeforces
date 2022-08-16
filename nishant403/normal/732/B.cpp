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
    int n,x,k;
    cin >> n >> k;
    
    vi data(n);
    
    f(i,n) cin >> data[i];
    
    int ans = 0;
    int temp =0;
    
    for(int i=1;i<n;i++)
    {
        temp=max(0LL,k-data[i]-data[i-1]);
        data[i]+=temp;
        ans+=temp;
    }
    
    cout << ans << "\n";
    
    f(i,n) cout << data[i] << " ";
    
}

signed main()
{
 Fast;
 solve();
}