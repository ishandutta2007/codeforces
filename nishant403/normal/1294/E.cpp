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

int n,m;
vector<vi> a;

int go(vector<int> & arr)
{
    int n = arr.size();
    
    map<int,int> dis;
    
    f(i,n)
    {
        int val = arr[i];
        
        if(val%m != 0) continue;
        if(val < 0) continue;
        int original = val/m;
        if(original >= n) continue;
        if(original <= i) dis[i-original]++;
        else dis[n+i-original]++;
    }
    
    int ans = n;
    
    for(auto x : dis)
    {
        int cur = x.F + n - x.S;
        ans = min(ans,cur);
    }
    
    
    return ans;
}

void solve()
{
    cin >> n >> m;
    a.resize(m);
    
    f(i,m) a[i].resize(n);
    f(i,n) f(j,m) cin >> a[j][i];
    f(i,n) f(j,m) a[j][i]-=(j+1);
    
    int res = 0;
    
    f(j,m) res+=go(a[j]);
    
    cout << res; 
}

signed main()
{
    fast;
        
    solve();
}