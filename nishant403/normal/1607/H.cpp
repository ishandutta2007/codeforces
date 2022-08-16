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

const int N = 2e5 + 10;
const int inf = 1e18;

int n;
int a[N],b[N],m[N];
pii way[N];

void solve()
{
   cin >> n;
   f(i,n) cin >> a[i] >> b[i] >> m[i];
   f(i,n) way[i] = {0,0};
   
   //store 3 things : sum of remaining , range of a in remaining, index 
   vector<pair<pii,pii> > go; 
    
   f(i,n)
   {
       way[i] = {min(a[i],m[i]),m[i] - min(a[i],m[i])};
       a[i] -= way[i].F;
       b[i] -= way[i].S;
       go.push_back({{a[i] + b[i],a[i]},{a[i] + min(b[i],way[i].F),i}});
   }
    
   sort(all(go));
    
   int res = 0;
   int last_sum = -1;
   int last_id = 0;
   pair<int,int> rng = {-inf,inf};
    
   f(i,(int)go.size())
   {
       auto x = go[i];
       
       if(last_sum == x.F.F && max(rng.F,x.F.S) <= min(rng.S,x.S.F))
       {
           rng.F = max(rng.F , x.F.S);
           rng.S = min(rng.S , x.S.F);
       }
       else
       {
           for(int j=last_id;j<i;j++)
           {
               way[go[j].S.S].F -= rng.F - a[go[j].S.S];
               way[go[j].S.S].S += rng.F - a[go[j].S.S]; 
           }
           
           res++;
           last_id = i;
           last_sum = x.F.F;
           rng = {x.F.S,x.S.F};
       }
   }
    
    for(int j=last_id;j<n;j++)
    {
       way[go[j].S.S].F -= rng.F - a[go[j].S.S];
       way[go[j].S.S].S += rng.F - a[go[j].S.S]; 
    }
    
   cout << res << '\n';
   f(i,n) cout << way[i].F << ' ' << way[i].S << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}