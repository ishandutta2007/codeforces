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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int N = 46700;
int dp[N][3];
int first = 0;
int second = 0;

int mex(int a,int b = 1000,int c = 1500)
{
    f(i,4)
        if(i!=a && i!=b && i!=c) return i;
    
    assert(1==0);

    return 1; 
}

int get(int id)
{
    int res = 0;
    
    f(i,5)
        f(j,3)
    {
        res+=dp[i+id][j];
        res++; 
        res*=10;
    }
    
    return res;
}

void prep(int x,int y,int z)
{
   f(i,3) dp[0][i] = 0;
    
   map<int,int> mp; 
    
   for(int i=1;i<N;i++)
   {
       int a=0,b=0,c=0;
       
       if(i-x<= 0) a = 0;
       else a = dp[i-x][0];
       
       if(i-y<=0) b = 0;
       else b = dp[i-y][1];
       
       if(i-z<=0) c = 0;
       else c = dp[i-z][2];
       
       dp[i][0] = mex(a,b,c);
       dp[i][1] = mex(a,c);
       dp[i][2] = mex(a,b);
       
      if(i>=5)
      {
          
       int val = get(i-5);
       
       if(mp.find(val) != mp.end())
       {
           first = mp[val];
           second = i-5;
           return;
       }
       
       mp[val] = i-5;
          
      }
   }
}

int grundy(int val,int typ)
{
    if(val <= 0) return 0;
    if(val < first) return dp[val][typ];
    
    int id = val;
    id = ((id - first)%(second-first)) + first;
    
    return dp[id][typ];
}

void solve()
{
   int n,x,y,z;
   cin >> n >> x >> y >> z;
    
   int a[n];
   f(i,n) cin >> a[i];
    
   prep(x,y,z);
    
   int xr = 0;
    
   f(i,n) xr^=grundy(a[i],0);
   
   int res = 0;  
    
   f(i,n)
   {
       int old = grundy(a[i],0);
       int ne = grundy(a[i]-x,0);
       if((xr^old^ne) == 0) res++;
       ne = grundy(a[i]-y,1);
       if((xr^old^ne) == 0) res++;
       ne = grundy(a[i]-z,2);
       if((xr^old^ne) == 0) res++;
   }
    
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