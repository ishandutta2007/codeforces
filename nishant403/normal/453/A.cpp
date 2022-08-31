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

const int N = 1e5+10;
double pw[N];

double power(double a,int b)
{
    double res = 1.0000000;
    
    while(b)
    {
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    
    return res;
}

void solve()
{
    int n,m;
    cin >> m >> n;
    
    f(i,m+1) pw[i] = power((double)i/m,n);
    
    double res = 0.000000000; 
    
    f(i,m) res+= (i+1)*(pw[i+1]-pw[i]);
    
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