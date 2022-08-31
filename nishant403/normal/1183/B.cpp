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

int check(int n)
{
    
    int d = (n%10);
    d+=(n/10)%10;
    d+=(n/100)%10;
    d+=(n/1000)%10;
    
    return d;
}

void solve()
{
int n,k;
    cin >> n >> k;
    
 int ans = -1;   
 int a[n];
 int ma= -1;   
 int mi=9999999999999;   
    
 f(i,n) { cin >> a[i]; ma= max(ma,a[i]); mi=min(mi,a[i]); }
 
    int l = ma-k;
    int r = mi+k;
    
    while(l<=r)
    {
        bool flag = 1;
        int mid =(l+r)/2;
        
        
        f(i,n) if(abs(a[i]-mid) > k) { flag = 0; break; }
        
        if(flag)
        {
         l = mid+1;   
         ans=max(ans,mid);   
        }
        else r = mid-1;
    }
    
    cout << ans << "\n";
    
}

signed main()
{
    fast;int t=1;
    cin >> t;
    while(t--)
    solve();
}