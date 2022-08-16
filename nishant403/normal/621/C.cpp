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
    int n,p;
    cin >> n >> p;
    
    pii data[n+1];
    pii calc[n+1];
    
    f(i,n) cin >> data[i].F >> data[i].S;
    
    f(i,n) calc[i].F = data[i].S/p - (data[i].F-1)/p;
    f(i,n) calc[i].S = data[i].S - data[i].F + 1;
    
    calc[n] = calc[0];
    
    double res = 0.000000;
    
    f(i,n) res+=(double)calc[i].F/calc[i].S;
   
    res*=2.0000000;
   
    f(i,n) res-=((double)calc[i].F/calc[i].S)*((double)calc[i+1].F/calc[i+1].S);
    
    res*=2000.00000000;
    
    cout << fixed << setprecision(6) << res;     
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}