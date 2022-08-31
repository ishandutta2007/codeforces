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

const int N = 1e5 + 10;
int nex[N],pre[N];
queue<int> go;
vector<int> res;
int a[N];
int n;

void rem(int x)
{
    int pp = pre[x];
    int nn = nex[x];
    
    pre[nn] = pp;
    nex[pp] = nn;
    
    res.pb(x);
    
    if(go.size() > 0 && go.front() == nn) go.pop();
        
    if(__gcd(a[pp],a[nn]) == 1 && nn != x && pp != x) go.push(nn);
}

void solve()
{
    cin >> n;
    f(i,n) cin >> a[i];
    
    if(n == 1)
    {
        if(a[0] > 1) cout << 0 << '\n';
        else cout << 1 << ' ' << 1 << '\n';
        return;
    }
    
    f(i,n) pre[i] = (i + n - 1)%n;
    f(i,n) nex[i] = (i + 1)%n;
    
    res.clear();
    
    f(i,n) if(__gcd(a[i],a[(i+1)%n]) == 1) go.push((i+1)%n);
        
    while(!go.empty())
    {
        auto z = go.front(); go.pop();
        rem(z);
    }
    
    cout << res.size() << ' ';
    for(auto x : res) cout << x + 1 << ' ';
    cout << "\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}