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
int n,k,a,b;
    
    cin >> k >> n >> a >> b;
    
    int ans = -1;
    int l = 0;
    int r = n;
    
    while(l<=r)
    {
     int flag = 1;
        
     int mid =(l+r)/2;
          
     if(k <=(mid*a)+(n-mid)*(b)) flag = 0;
        
        if(flag){
         ans=max(ans,mid);
         l = mid+1;
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