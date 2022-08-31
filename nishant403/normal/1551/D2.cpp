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

const int N = 105;
int res[N][N];
string ans[N];

int cnt = 0;

int solve(int row,int col,int hor,int ver)
{
    if((row*col) == 0) return 1;
    
    if(row % 2 == 1)
    {
        if(hor < (col/2)) return 0;
        
        for(int i=0;i<(col/2);i++)
        {
            res[row - 1][i+i] = res[row - 1][i+i+1] = cnt++;
        }
        
        return solve(row - 1,col,hor - (col/2),ver);
    }
    
    if(col % 2 == 1)
    {
        if(ver < (row/2)) return 0;
        
        for(int i=0;i<(row/2);i++)
        {
            res[i+i][col - 1] = res[i+i+1][col - 1] = cnt++;
        }
        
        return solve(row,col - 1,hor,ver - (row/2));
    }
    
    if(hor % 2 == 1) return 0;
     
    pii cur = {0,0};
    
    while(ver > 0)
    {
        res[cur.F][cur.S] = res[cur.F + 1][cur.S] = cnt++;
        cur.S++;
        ver--;
        if(cur.S == col) cur = {cur.F + 2,0};
    }
    
    f(i,row) f(j,col) if(res[i][j] == 0) res[i][j] = res[i][j+1] = cnt++;
    
    return 1;
}

int n,m,k;

bool valid(int i,int j,int v)
{
    if(i > 0 && ans[i-1][j] == ('a' + v)) return 0;
    if(j > 0 && ans[i][j-1] == ('a' + v)) return 0;
    if(i < n-1 && ans[i+1][j] == ('a' + v)) return 0;
    if(j < m-1 && ans[i][j+1] == ('a' + v)) return 0;
    return 1;
}

void solve()
{
   cin >> n >> m >> k;
    
   f(i,n) f(j,m) res[i][j] = 0;
   cnt = 1;
    
   if(solve(n,m,k,(n*m)/2 - k)) 
   {
       cout <<"YES\n";
       
       f(i,n)
       {
           ans[i].clear();
           f(j,m) ans[i] += 'z';
       }
       
       //hor
       f(i,n) f(j,m-1)
       {
           if(res[i][j] == res[i][j+1] && ans[i][j] == 'z')
           {
               f(v,10)
               {
                   if(valid(i,j,v) && valid(i,j+1,v))
                   {
                       ans[i][j] = ans[i][j+1] = v + 'a';
                       break;
                   }
               }
           }
       }
       
       //ver
       f(i,n-1) f(j,m)
       {
           if(res[i][j] == res[i+1][j] && ans[i][j] == 'z')
           {
               f(v,10)
               {
                   if(valid(i,j,v) && valid(i+1,j,v))
                   {
                       ans[i+1][j] = ans[i][j] = v + 'a';
                       break;
                   }
               }
           }
       }
       
       f(i,n) cout << ans[i] << '\n';
   }
   else cout <<"NO\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}