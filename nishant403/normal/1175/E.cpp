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
#define all(x) x.begin(),x.end()

const int N = 5e5 + 10;
const int LN = 19;

vector<int> g[N];
int mx[N];

int sp[N][LN];

void solve()
{
   int n,m;
    cin >> n >> m;
    
   pii a[n];
    f(i,n) cin >> a[i].F >> a[i].S;
    f(i,n) g[a[i].F].pb(a[i].S);
    
   for(int i=0;i<N;i++)
   {
       if(i > 0 && mx[i-1] >= i) mx[i] = mx[i-1];
       
       for(auto x : g[i])
       {
           mx[i] = max(mx[i] , x);
       }
       
       sp[i][0] = mx[i];
   }
    
   for(int i=1;i<LN;i++)
       for(int j=0;j<N;j++)
         sp[j][i] = sp[sp[j][i-1]][i-1];
      
   int l,r;
    
   while(m--)
   {
       int l,r;
       cin >> l >> r;
       
       int res = 0;
       
       for(int i=LN-1;i>=0;i--)
       {
           if(sp[l][i] < r && sp[l][i] > l)
           {
               res += (1LL<<i);
               l = sp[l][i];
           }
       }
       
       l = sp[l][0];
       
       res++;
       
       if(l >= r) cout << res << '\n';
       else cout << -1 << '\n';
   }
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}