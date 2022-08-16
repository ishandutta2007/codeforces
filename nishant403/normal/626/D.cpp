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

const int N = 5e3+10;
double sum[N+N];
double air[N];

void solve()
{
   int n;
   cin >> n;
     
   int a[n];
   f(i,n) cin >> a[i];
    
   sort(a,a+n); 
    
   f(i,n) f(j,i) air[a[i]-a[j]]++;
    
   f(i,N) f(j,N) sum[i+j]+=air[i]*air[j];
    
   f(i,N+N) sum[i]/=((double)n*(n-1)*0.50000000);
   f(i,N+N) sum[i]/=((double)n*(n-1)*0.50000000);
   
   double res = 0.0000000;
    
   for(int i=N-2;i>=0;i--)  air[i]+=air[i+1]; 
    
   f(i,N-1) res+=(sum[i]*air[i+1]);
   
    
   res/=n;
   res/=(n-1);
   res*=2.000000; 
    
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