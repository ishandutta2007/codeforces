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

const int N = 1000;
int mat[N][N];
int store[N][N];

void solve()
{
   int m,k;
    cin >> m >> k;
    
   pii a[k];
    f(i,k) cin >> a[i].F;
    f(i,k) a[i].S = i + 1;
   sort(a,a+k); 
    
   pii b[k];
   f(i,k) b[i] = a[i];
   
    
   int l = 1;
   int r = 2*sqrt(m);
   int res = r;
    
   while(l <= r)
   {
       int mid = (l + r)/2;
       
       f(i,k) a[i] = b[i];
   
       int tot_cells = (mid*mid);
       int empty_cells = (mid / 2)*(mid / 2);
       
       if(tot_cells - empty_cells < m)
       {
           l = mid + 1;
           continue;
       }
       
       //try to fill it and then we check
       int ptr = k-1;
       
       vector<pii> ord;

       f(i,mid) f(j,mid)
         if(i % 2 == 0 && j % 2 == 1) ord.pb({i,j});
       
       f(i,mid) f(j,mid)
         if(i % 2 == 0 && j % 2 == 0) ord.pb({i,j});
         
       f(i,mid) f(j,mid)
         if(i % 2 == 1 && j % 2 == 0) ord.pb({i,j});
       
       f(i,mid) f(j,mid) mat[i][j] = 0; 
       
       for(auto x : ord)
       {
           if(ptr >= 0 && a[ptr].F > 0)
           {
               mat[x.F][x.S] = a[ptr].S;
               a[ptr].F--;
               
               while(a[ptr].F == 0 && ptr >= 0) ptr--;
           }
       }
       
       int flag = 1; 
       
       f(i,mid) f(j,mid)
           if(i % 2 == 1)
       {
           if(j+1 < mid)
           {
               if(mat[i][j] != 0 && mat[i][j] == mat[i-1][j+1]) flag = 0;
           }
       }
       
       if(flag == 1)
       {
           res = mid;
           
           f(i,res) f(j,res) store[i][j] = mat[i][j];
           r = mid - 1;
       }
       else l = mid + 1;
   }
    
   cout << res << '\n';
    
   f(i,res)
   {
       f(j,res) cout << store[i][j] << ' ';
       cout << '\n';
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