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

const int N = 1010;
pair<int,pii> go[N];

void pre()
{
    f(i,N) go[i] = {-1,{-1,-1}}; 
    
    for(int i=0;3*i<N;i++)
      for(int j=0;5*j<(N-(i*3));j++)
        for(int k=0;7*k<N-(i*3)-(j*5);k++) 
        go[(i*3) + (5*j) + (7*k)] = {i,{j,k}};
}

void solve()
{
   int n;
   cin >> n;
 
   if(go[n].F == -1) cout << -1 << '\n';
   else cout << go[n].F << ' ' << go[n].S.F << ' ' << go[n].S.S << '\n';
}

signed main()
{
    pre();
    
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}