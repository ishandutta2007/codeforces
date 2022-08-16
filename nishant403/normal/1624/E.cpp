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
   int n,m;
   cin >> n >> m;

   string s[n];
   f(i,n) cin >> s[i];

   map<string,pair<int,pii> > mp;

   f(i,n) {
       f(j,m) {
           for(int k=2;k<=3;k++) {
               if(j + k - 1 >= m) continue;
               string tmp = s[i].substr(j,k);
               mp[tmp] = {i,{j,j+k-1}};
           }
       }
   }

   string t;
   cin >> t;
    
   vector<pair<int,pii> > possible(m);

   f(i,m) {
       possible[i] = {-1,{-1,-1}};

       for(int k=2;k<=3;k++) {
           if(i + 1 < k) continue;
           string tmp = t.substr(i - k + 1,k);

            if(mp.find(tmp) == mp.end()) continue;

           if(i - k + 1 == 0 || possible[i - k].F != -1) {
               possible[i] = mp[tmp];
           }
       }
   }

   if(possible[m-1].F == -1) {
       cout << -1 << '\n';
   } else {
       vector<pair<int,pii> > go;

       int pos = m-1;

       while(pos >= 0) {
           go.pb(possible[pos]);
           int len = go.back().S.S - go.back().S.F + 1;
           pos -= len;
       }

       reverse(all(go));

       cout << go.size() << '\n';

       for(auto x : go) {
            cout << x.S.F + 1 << ' ' << x.S.S + 1 << ' ' << x.F + 1 << '\n';
       }
   }
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}