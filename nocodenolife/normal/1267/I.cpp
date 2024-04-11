#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
 
#define F first
#define S second 
#define pb push_back
//#define endl "\n"

#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }

#ifdef DEBUG
    #define dbg(s) {s;}
#endif

#ifndef DEBUG
    #define dbg(s)
#endif

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int grand(int x) { // from [0, x-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

#define int ll
#define i32 int32_t

#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 

#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int getInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}


ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
} 

const ll mod = 1e9 + 7;

ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 1e6 + 7;

const ll inf = 1e9 + 7;

set<int> a;
set<int> b;
int minia;
int minib;

map<pii,int> ans;

int query(int i, int j)
{
    int u = min(i,j);
    int v = max(i,j);

    if(ans[{u,v}]!=0)
    {
        return ans[{u,v}];
    }
    cout<<"? "<<u<<" "<<v<<endl;
    
    char c;
    cin>>c;
    int x;
    if(c=='<')
        x=u;
    else
        x=v;
    ans[{u,v}] = x;
    return x;
}

void insert(int val,int i)
{
    if(i==1)
    {
        a.insert(val);
        if(a.size()==1)
            minia = val;
        else
        {
            minia = query(minia,val);
        }
    }
    else
    {
        b.insert(val);
        if(b.size()==1)
            minib = val;
        else
        {
            minib = query(minib,val);
        }

    }
}

void del(int val,int i)
{
    if(i==1)
    {
        a.erase(val);
        minia = -1;
        for(auto xc: a)
        {
            if(minia==-1)
                minia = xc;
            else
                minia = query(xc,minia);
        }
    }
    else
    {
        b.erase(val);
        minib = -1;
        for(auto xc: b)
        {
            if(minib==-1)
                minib = xc;
            else
                minib = query(xc,minib);
        }
    }

}

void solve()
{
    a.clear();
    b.clear();
    ans.clear();

    int n;
    cin>>n;

    int x = n+1;
    for(int i=1;i<=x/2;i++)
    {
        insert(i,1);
    }
    for(int i=x/2+1;i<=x;i++)
    {
        insert(i,2);
    }
    
    int glob;
    for(int i=n+2;i<=n+n;i++)
    {
        glob = query(minia,minib);
        if(glob==minia)
        {
            del(glob,1);
            insert(i,1);
        }
        else
        {  
            del(glob,2);
            insert(i,2);
        }
    }
    glob = query(minia,minib);
    cout<<"!"<<endl;
        
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    int t;
    cin>>t;

    while(t--)
        solve();
    
}