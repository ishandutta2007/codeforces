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

const int inf = 1e18;

void solve()
{
   int n;
   cin >> n;

   string s,t;
   cin >> s >> t;

   vi pos[26];
   f(i,n) pos[s[i] - 'a'].pb(i);
   f(i,26) reverse(all(pos[i]));

   int res = inf; 
   int tmp = 0;

   FenwickTree offset(n);

   f(i,n) {
       f(j,t[i] - 'a') {
           if(!pos[j].empty()) {
               int k = pos[j].back();

               res = min(res , tmp + k + offset.sum(0,k) - i);
           }
       }

       if(pos[t[i] - 'a'].empty()) break;

       int k =  pos[t[i] - 'a'].back();
       pos[t[i] - 'a'].pop_back();

       tmp += k + offset.sum(0,k) - i;

       offset.add(0,1);
       if(k < n) offset.add(k+1,-1);
   }

   if(res == inf) res = -1;

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