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

const int N = 5010;
int a[N];
int n;

int go(int l,int r)
{
    if(l > r) return 0;
    
    if(l == r)
    {
        if(a[l] > 0) 
        {
            a[l] = 0;
            return 1;
        }
        
        return 0;
    }
    
    //find min element and reduce that much time
    
    int mn = a[l];
    for(int i=l;i<=r;i++) mn = min(mn,a[i]);
    
    int res = r - l + 1;
    int res2 = 0;
    
    if(mn <= n)
    {
        for(int i=l;i<=r;i++) a[i]-=mn;
        res2+=mn;

        int o = l;

        for(int i=l;i<=r;i++)
            if(a[i] == 0) res2+=go(o,i-1),o = i + 1;

        res2+=go(o,r);
        
        return min(res,res2);
    }
    
    return res;
    
}

void solve()
{
    cin >> n;
    
    f(i,n) cin >> a[i];
    
    cout << go(0,n-1);
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}