#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int inf = 1e18;
const int N = 1e5 + 10;
const int sqN = 450;

int cur[N];
int nex[N];
int a[N];
int n;

int sum(int l,int r)
{
    return a[r] - a[l - 1];
}

void solve()
{
   cin >> n;
   f(i,n) cin >> a[i];
    
   reverse(a+1,a+n+1); 
    
   f(i,n) a[i] += a[i-1];
  
   for(int i=0;i<=n;i++) cur[i] = inf;
    
   int ans = 0;
    
   for(int j=1;j<sqN;j++)
   {
       for(int i=0;i<=n;i++) nex[i] = -inf;
       
       for(int i=1;i<=n;i++)
       {
           if(i - j < 0) continue;
           
           nex[i] = nex[i-1];
           
           if(sum(i - j + 1,i) < cur[i-j])
           {
               nex[i] = max(nex[i],sum(i - j + 1,i));
           }
           
       }
       
       for(int i=0;i<=n;i++) cur[i] = nex[i];
       
       if(cur[n] > 0) ans = j;
   }
    
   cout << ans << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}