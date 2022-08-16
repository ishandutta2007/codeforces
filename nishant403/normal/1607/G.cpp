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
#define all(x) x.begin(),x.end()

const int N = 2e5 + 10;
const int inf = 1e18;

int val;
vector<pii> way;

void finder(int n,int m,vector<int> a,vector<int> b,bool sw)
{
    //take from a's first and then if not satisfied take from b
    //works on the assumption that in the final result, sum of a <= sum of b
    //so after taking most part from a , now we release some part of a and take some from b
    //we now try to increase sum of A and reduce sum of B at the same time.
    //do it as long as it improves the answer
    vector<pii> temp_way(n);
    f(i,n) temp_way[i] = {0,0};
    
    vector<pii> improve;
    
    f(i,n)
    {
        temp_way[i] = {min(m,a[i]),m - min(m,a[i])};
        a[i] -= temp_way[i].F;
        b[i] -= temp_way[i].S;
        improve.pb({i,min(temp_way[i].F,b[i])});
    }
    
    int sa = 0;
    int sb = 0;
    f(i,n) sa += a[i],sb += b[i];
  
    for(auto x : improve)
    {
        if(sb > sa)
        {
            int take = min((sb - sa)/2 ,x.S);
            sa += take;
            sb -= take;
            
            temp_way[x.F].F -= take;
            temp_way[x.F].S += take;
        }
    }
    
    int temp_val = abs(sa - sb);
    
    if(temp_val < val)
    {
        val = temp_val;
        
        if(sw) 
        {
            f(i,n) swap(temp_way[i].F,temp_way[i].S);
        }
        
        way = temp_way;
    }
}

void solve()
{
   int n,m;
   cin >> n >> m;
   
   vi a(n),b(n);
   f(i,n) cin >> a[i] >> b[i];
    
   val = inf;
   way.clear();
       
   finder(n,m,a,b,0);
   finder(n,m,b,a,1);
    
   cout << val << '\n';
   for(auto x : way) cout << x.F << ' ' << x.S << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}