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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}


void solve()
{
    int n;
    cin >> n;
   
    double a[n];
    f(i,n) cin >> a[i];

    if(n == 2) {
        cout << 0 << '\n';
        return;
    }

   int res = max((int)0,n-2);

   f(i,n) 
    for(int j=i+1;j<n;j++) {
        int tmp = 0;

        //we can represent each value in terms of a[0] and a[n-1]
        //formula will be distance from a[n-1]*a[0] + distance from a[0]*a[n-1] / (n-1)
       
        //first calculate a[0] and a[n-1] from fixed values
        pair<pair<double,double>,double> e1 = {{n-1-i,i},(n-1)*a[i]};
        pair<pair<double,double>,double> e2 = {{n-1-j,j},(n-1)*a[j]};
       
        double a_l = ((e1.S*j) - (e2.S*i))/(e1.F.F*j - e2.F.F*i);
        double a_r = ((e1.S) - (a_l*e1.F.F)) / e1.F.S;  

        f(k,n) {
            double vv = (a_l*(n - k - 1)) + (a_r*k);
            if(abs(vv - a[k]*(n-1)) <= 1e-6) ;
            else tmp++;
        }

        res = min(res,tmp);
    }

    cout << res << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}