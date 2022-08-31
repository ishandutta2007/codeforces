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
#define precise(x) fixed << setprecision(x) 
#define double long double

const int N = 2e5 + 10;
const double eps = 1e-12;

double a[N];
double b[N];
int n;

double fun(double x)
{
    f(i,n) b[i] = a[i] - x;
    
    double mx = 0;
    double mn = 0;
    double cur = 0;
    double res = 0;
    
    f(i,n)
    {
        cur+=b[i];
        
        res = max(res , abs(cur - mx));
        res = max(res , abs(cur - mn));
        mx = max(mx , cur);
        mn = min(mn , cur);
    }
    
    return res;
}

void solve()
{
   cin >> n;
   f(i,n) cin >> a[i];
    
   double l = -1e4;
   double r = 1e4;
    
   f(i,100)
   {
       double mid = (l + r)/2;
       
       if(fun(mid - eps) < fun(mid)) r = mid;
       else l = mid;
   }
    
   cout << precise(6) << fun((l+r)/2); 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}