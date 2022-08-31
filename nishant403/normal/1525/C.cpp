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

const int N = 3e5 + 10;
int res[N];

int m;

void solve(vector<pair<pii,char> > go)
{
    vector<pair<pii,char > > st;
    
    int n = go.size();
    sort(all(go));
    
    f(i,n)
    {
         if(!st.empty() && st.back().S == 'R' && go[i].S == 'L')
         {
             int dis = (go[i].F.F - st.back().F.F)/2;
             res[go[i].F.S] = res[st.back().F.S] = dis;
             st.pop_back();
         }
        else st.pb(go[i]);
    }
    
    swap(go,st);
    st.clear();
    n = go.size();
    
    f(i,n)
    {
         if(!st.empty() && st.back().S == 'L' && go[i].S == 'L')
         {
             int dis = st.back().F.F + (go[i].F.F - st.back().F.F)/2;
             res[go[i].F.S] = res[st.back().F.S] = dis;
             st.pop_back();
         }
        else st.pb(go[i]);
    }
    
    swap(go,st);
    reverse(all(go));
    st.clear();
    n = go.size();
    
    f(i,n)
    {
         if(!st.empty() && st.back().S == 'R' && go[i].S == 'R')
         {
             int dis = (m - st.back().F.F) + (st.back().F.F - go[i].F.F)/2;
             res[go[i].F.S] = res[st.back().F.S] = dis;
             st.pop_back();
         }
        else st.pb(go[i]);
    }
    
    swap(go,st);
    reverse(all(go));
    st.clear();
    n = go.size();
    
    assert(go.size() <= 2);
    
    if(go.size() == 2)
    {
        int dis = (go[0].F.F + m - go[1].F.F + m)/2;
        res[go[0].F.S] = res[go[1].F.S] = dis;
    }
}

void solve()
{
     int n;
    cin >> n >> m;
    
    vector<pair<pii,char> > a(n),b,c;
    f(i,n) cin >> a[i].F.F;
    f(i,n) cin >> a[i].S;
    f(i,n) a[i].F.S = i;
    
    f(i,n) res[i] = -1;
    
    f(i,n) if(a[i].F.F & 1) b.pb(a[i]);
           else c.pb(a[i]);
    
    solve(b);
    solve(c);
    
    f(i,n) cout << res[i] << ' ';
    cout << '\n';
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}