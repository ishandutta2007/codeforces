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

const int N = 2e5 + 10;
map<int,char> ed[N];
int od = 0,ev = 0;

void change(int x,int y,char c)
{
    if(ed[x].find(y) != ed[x].end()) //remove
    {
        if(ed[y].find(x) != ed[y].end())
        {
            char cc = ed[y][x];
            if(cc == c) od--;
            else ev--;
        }
        
        ed[x].erase(y);
    }
    else //add
    {   
        if(ed[y].find(x) != ed[y].end())
        {
            char cc = ed[y][x];
            
            if(cc == c) od++;
            else ev++;
        }
        
        ed[x][y] = c;
    }
}

void solve()
{
   int n,m;
    cin >> n >> m;
    
   char c;
   int x,y,z;
   
   while(m--)
   {
       cin >> c;
       
       if(c == '+')
       {
           cin >> x >> y >> c;
           change(x,y,c);
       }
       else if(c == '-')
       {
           cin >> x >> y;
           change(x,y,ed[x][y]);
       }
       else
       {
           cin >> x;
           
           if(od > 0) cout <<"YES\n";
           else if(x % 2 == 1 && ev > 0) cout << "YES\n";
           else cout <<"NO\n";
       }
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