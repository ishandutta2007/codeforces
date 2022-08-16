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
    
    int a[n];
    f(i,n) cin >> a[i];
    
    sort(a,a+n);
    
    int l = a[n/2];  
    int r = 1e12;
    int ans = l;
    
    while(l<=r)
    {
        int mid =(l+r)/2;
        
        int step = 0;
        
        for(int i=n/2;i<n;i++) if(a[i] < mid ) step+= mid-a[i];
       
        if(step <= k) { ans = max(ans,mid); l = mid+1; }
        else r = mid -1;
        
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