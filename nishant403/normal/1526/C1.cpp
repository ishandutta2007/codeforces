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

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve()
{
   int n;
   cin >> n;
    
   int a[n];
   f(i,n) cin >> a[i];
    
   int sum = 0;
   int res = 0;
    
   f(i,n) if(a[i] >= 0) sum += a[i] , res++;
           
   //we must take all potions which increase health
   //from the remaining we take maximum potions that decrease health
    
   set<int> st;
   FenwickTree go(n+5);
   f(i,n) if(a[i] > 0) go.add(i,a[i]);
   f(i,n) if(a[i] > 0) st.insert(i);
    
   vector<pii> neg;
   f(i,n) if(a[i] < 0) neg.pb({a[i],i});
   sort(all(neg));    
   reverse(all(neg)); 
   
   for(auto x : neg)
   {
       int ss = go.sum(0,x.S);
       
       if(ss + x.F >= 0)
       {
           res++;
           int vv = -x.F;
           
           while(vv > 0)
           {
               auto zz = *(--st.upper_bound(x.S));
               
               int xx = go.sum(zz,zz);
               
               if(xx > vv)
               {
                   go.add(zz,-vv);
                   vv = 0;
               }
               else
               {
                   vv -= xx;
                   go.add(zz,-xx);
                   st.erase(zz);
               }
           }
       }
   }
    
   cout << res;     
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}