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

int ask(int x,int y)
{
    cout <<"? " << x << ' ' << y << endl;
    string res;
    cin >> res;
    
    if(res == "Yes") return 1;
    return 0;
}
    

signed main()
{
    int n;
    cin >> n;
    
    int k[n];
    f(i,n) cin >> k[i];
    
    int nn = n;
    
    f(v,n + n)
    {
        f(i,n)
        {
            if(k[i] == 0)
            {
                f(j,n) k[j]--;
                nn--;
            }
            else if(k[i] == nn - 1)
            {
                k[i] = -1;
                nn--;
            }
        }
    }
    
    //now any two left are connected
    vector<int> go;
    f(i,n) if(k[i] > 0) go.pb(i);
        
   vector<pair<int,pii> > go2;
   
   for(int i=0;i<go.size();i++)
       for(int j=0;j<i;j++)
   {
      if(k[go[i]] > k[go[j]]) go2.pb({ abs(k[go[i]] - k[go[j]]) , {go[i],go[j]}});
      else go2.pb({ abs(k[go[i]] - k[go[j]]) , {go[j],go[i]}});
   }
    
   sort(all(go2));
   reverse(all(go2));
    
    for(auto x : go2)
    {
        if(ask(x.S.F + 1,x.S.S + 1))
        {
            cout <<"! " << x.S.F + 1 << ' ' << x.S.S + 1 << endl;
            return 0;
        }
    }
    
    cout <<"! " << 0 << ' ' << 0 << endl;
}