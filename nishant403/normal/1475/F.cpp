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
   int n;
    cin >> n;
   
   string a[n],b[n];
    f(i,n) cin >> a[i];
    f(i,n) cin >> b[i];
    
   int cc[n][n];
    
    f(i,n) f(j,n)
    {
        int xx = a[i][j] - '0';
        int yy = b[i][j] - '0';
        cc[i][j] = (xx ^ yy);
    }
    
    //case 1 : do nothing for 1st row
    vi r(n,-1),c(n,-1);
    r[0] = 1;
    
    int flag = 1;
    
    f(i,n) f(j,n)
    {
        if(cc[i][j] == 1)
        {
            if(r[i] == 0) 
            {
                if(c[j] == 0) flag = 0;
                else c[j] = 1;
            }
            else if(r[i] == 1)
            {
                if(c[j] == 1) flag = 0;
                else c[j] = 0;
            }
            else if(r[i] == -1)
            {
                if(c[j] == 0) r[i] = 1;
                else if(c[j] == 1) r[i] = 0;
                else assert(1 == 0);
            }
        }
        else
        {
            if(r[i] == 0) 
            {
                if(c[j] == 1) flag = 0;
                else c[j] = 0;
            }
            else if(r[i] == 1)
            {
                if(c[j] == 0) flag = 0;
                else c[j] = 1;
            }
            else if(r[i] == -1)
            {
                if(c[j] == 0) r[i] = 0;
                else if(c[j] == 1) r[i] = 1;
                else assert(1 == 0);
            }
        }
    }
    
    if(flag)
    {
        cout <<"YES\n";
        return;
    }
    
    
    f(i,n) r[i] = c[i] = -1;
    r[0]= 0;
    
    flag = 1;
    
    
    f(i,n) f(j,n)
    {
        if(cc[i][j] == 1)
        {
            if(r[i] == 0) 
            {
                if(c[j] == 0) flag = 0;
                else c[j] = 1;
            }
            else if(r[i] == 1)
            {
                if(c[j] == 1) flag = 0;
                else c[j] = 0;
            }
            else if(r[i] == -1)
            {
                if(c[j] == 0) r[i] = 1;
                else if(c[j] == 1) r[i] = 0;
                else assert(1 == 0);
            }
        }
        else
        {
            if(r[i] == 0) 
            {
                if(c[j] == 1) flag = 0;
                else c[j] = 0;
            }
            else if(r[i] == 1)
            {
                if(c[j] == 0) flag = 0;
                else c[j] = 1;
            }
            else if(r[i] == -1)
            {
                if(c[j] == 0) r[i] = 0;
                else if(c[j] == 1) r[i] = 1;
                else assert(1 == 0);
            }
        }
    }
    
    if(flag)
    {
        cout <<"YES\n";
        return;
    }
    
    cout <<"NO\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}