#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pii pair<int,int>
#define F first
#define S second

const int N = 2e5 + 10;
const int inf = 1e9 + 10;

pair<int,int> seg[N+N];
int n;
int a[N];

pair<int,int> query(int l,int r)
{
    pair<int,int> res = {inf,-inf};
    
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1)
    {
        if(l&1) 
        {
            res.F = min(res.F,seg[l].F);
            res.S = max(res.S,seg[l].S);
            l++;
        }
        
        if(r&1)
        {
            --r;
            res.F = min(res.F,seg[r].F);
            res.S = max(res.S,seg[r].S);
        }
    }
    
    return res;
}

bool check(int x,int y)
{
    int xx = query(0,x-1).S;
    int yy = query(x+y,n-1).S;
    int zz = query(x,x+y-1).F;
    
    if(xx == yy && yy == zz)
    {
        cout <<"YES\n";
        cout << x << ' ' << y << ' ' << n - (x+y) << '\n';
        return 1;
    }
    
    return 0;
}

void solve()
{
    cin >> n;
    
    f(i,n) cin >> a[i];
    f(i,n) seg[i+n] = {a[i],a[i]};
    
    for(int i=n-1;i>=1;i--)
        seg[i].F = min(seg[i+i].F,seg[i+i+1].F),
        seg[i].S = max(seg[i+i].S,seg[i+i+1].S);
    
    int mx = 0;
    
    for(int i=0;i<n-2;i++)
    {
        mx = max(mx,a[i]);
        
        int l = 0;
        int r = n - i - 1;
        int res = -1;
        
        while(l <= r)
        {
            int mid = (l + r)/2;
            
            if(query(n-mid,n-1).S <= mx)
            {
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        
        if(res == -1) continue;
        
        if(check(i+1,n-(i+1)-res)) return;
        if(check(i+1,n-(i+1)-res+1)) return;
    }
    
    cout <<"NO\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}