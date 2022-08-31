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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = (1LL<<21) + 1000;
int heap[N];
int sz[N];
int fsz[N];
vi res;

bool check(int node)
{
    if(sz[node] == fsz[node]) return false;
   
    int left = (node*2+1);
    int right = (node*2+2);
   
    if(heap[left] == 0 && heap[right] == 0) return 1;
    else if(heap[left] > heap[right]) return check(left);
    else return check(right);
    
    return 1;
}

void push(int node)
{
    sz[node]--;
    
    int left = (node*2+1);
    int right = (node*2+2);
               
    if(heap[left] == 0 && heap[right] == 0) heap[node] = 0;
    else if(heap[left] > heap[right])
    {
        heap[node] = heap[left];
        push(left);
    }
    else
    {
        heap[node] = heap[right];
        push(right);
    }
}

void go(int node)
{
    if(sz[node] == fsz[node]) return;
    
    while(sz[node] > fsz[node])
    {
       if(check(node))
       {
           res.pb(node);
           push(node);
       }
       else break;
    }
    
    go(node*2+1);
    go(node*2+2);
}

void solve()
{
   int h,g;
    cin >> h >> g;
    
   int n = mod_pow(2,h)-1;
    
   f(i,n) cin >> heap[i];
    
   int lastl = mod_pow(2,h-1)-1; 
    
   for(int i=lastl;i<n;i++) sz[i] = 1;
    
   for(int i=lastl-1;i>=0;i--) sz[i] = 1 + sz[(i<<1)+1] + sz[(i<<1)+2];   
  
   int lastg = mod_pow(2,g-1)-1; 
    
   for(int i=lastg;i<mod_pow(2,g)-1;i++) fsz[i] = 1;
   for(int i=lastg-1;i>=0;i--) fsz[i] = 1 + fsz[(i<<1)+1] + fsz[(i<<1)+2];   
    
   go(0);   
    
   int sum = 0;
    
   for(int i=0;i<mod_pow(2,g)-1;i++) sum+=heap[i];
   
   cout << sum << '\n';
   for(auto x : res) cout << x+1 <<" ";
   cout << '\n';
   
   for(int i=0;i<mod_pow(2,h);i++) heap[i] = sz[i] = fsz[i] = 0; // don't forget to f*** reset
    
   res.clear(); 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}