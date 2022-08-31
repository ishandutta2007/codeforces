#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 2e5 + 10;
vi dv[N];

void pre()
{
    for(int i=1;i<N;i++)
        for(int j=i;j<N;j+=i) dv[j].pb(i);
}

void solve()
{
    int n;
    cin >> n;
    
    int a[n];
    f(i,n) cin >> a[i];
    
    vi go(N,0);
    f(i,n) go[a[i]]++;
    
    vi res(N,0);
    
    for(int i=1;i<N;i++)
    {
        for(auto v : dv[i]) 
            res[i] = max(res[i],res[v]);
        
        res[i]+=go[i];
    }
    
    int rr = 0;
    f(i,N) rr = max(rr,res[i]);
                           
    cout << n - rr << '\n';
}

signed main()
{
    fast;
    
    pre();
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}