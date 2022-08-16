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
    
 int a[n];
    f(i,n) cin >> a[i];
    
    int x = a[0];
    
    f(i,n) x=__gcd(x,a[i]);
    
    int cn = 0;
    
    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0){
            cn++;   
            if(i*i!=x) cn++;
        }
    }
    cout << cn;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}