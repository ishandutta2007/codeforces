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
    int n;
    cin >> n;
    int res = n+10;
    pii save;
    
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int a = i;
            int b = n/i;
            
        	if(__gcd(a,b) > 1) continue;
        	
            int f = max(a,b);
            if(f < res)
            {
                res = f;
                save = {a,b};
            }
            
        }
    }
 
    cout << save.F <<" "<<save.S;
}

signed main()
{
    fast;
    
    int t = 1;
    
 //   cin >> t;
    
    while(t--)
        
    solve();
}