#include <bits/stdc++.h>
using namespace std;

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

const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

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

signed main()
{
    fast;
    
    int n;
    cin >> n;
    
    int a[n];
    f(i,n) cin >> a[i];
    
    set<int> st;
    
    while(st.size() < n) st.insert(getRand(1,5e8));
    
    //first hash each number to be very different to avoid hash hacks
    unordered_map<int,int> mp;
    
    f(i,n) 
    {
       mp[a[i]] = *st.begin();
       st.erase(st.begin());
    }
    
    f(i,n) a[i] = mp[a[i]];
    
    //now prepare value's table
    //first occurs -> a
    //second occurs -> a^2
    //third occurs -> 1/(a^3)
    
    //maintain a variable L denoting that starting point must be >= L
    vector<int> start(n,0);
    unordered_map<int,vector<int> > fre;
    
    pii b[n];
    
    for(int i=0;i<n;i++)
    {
        if(i > 0) start[i] = start[i-1];
        fre[a[i]].pb(i);
        
        int sz = fre[a[i]].size();
        
        if(sz > 3) start[i] = max(start[i],fre[a[i]][sz-4]+1);
        
        if(sz % 3 == 0) b[i].F = a[i] , b[i].S = a[i];
        else if(sz % 3 == 1)
        {
            b[i].F = (a[i]*a[i])%MOD;
            b[i].S = (a[i]*a[i])%MOD2;
        }
        else
        {
            int v = (a[i]*a[i])%MOD;
            v = (v*a[i])%MOD;
            v = mod_pow(v,MOD-2);
            b[i].F = v;
            
            int v2 = (a[i]*a[i])%MOD2;
            v2 = (v2*a[i])%MOD2;
            v2 = mod_pow(v2,MOD2-2,MOD2);
            b[i].S = v2;
        }
    }
    
    int res = 0;
    map<pii,vector<int> > hh;
    
    pii has = {1,1};
    hh[has].pb(0);
    
    for(int i=0;i<n;i++)
    {
        has.F = (has.F*b[i].F)%MOD;
        has.S = (has.S*b[i].S)%MOD2;
        
        //number of indices in has >= start[i]
        if(hh.find(has) != hh.end())
        {
            res+=hh[has].size();
            res-=lower_bound(hh[has].begin(),hh[has].end(),start[i]) - hh[has].begin();
        }
        
        hh[has].pb(i+1);
    }
        
    cout << res;
}