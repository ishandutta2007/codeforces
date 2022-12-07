#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
 
#define F first
#define S second 
#define pb push_back
#define endl "\n"

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

const int maxn = 2e5 + 7;

const ll inf = 1e9 + 7;

ll n;
ll x,a,b,y;
ll pri[maxn];
ll tem;
ll k;

bool isPoss(ll val)
{
    ll lc = (a*b)/(__gcd(a,b));
    ll qab = val/lc;
    ll qa = val/a;
    qa-=qab;
    ll qb = val/b;
    qb-=qab;
    
    ll idx = 0;
    ll ans = 0;
    while(qab>0)
    {
        ans+= (x+y)*(pri[idx])/100;
        idx++;
        qab--;
    } 
    while(qa>0)
    {
        ans+= (x)*(pri[idx])/100;
        idx++;
        qa--;
    } 
    while(qb>0)
    {
        ans+= (y)*(pri[idx])/100;
        idx++;
        qb--;
    } 
    //cout<<ans<<" "<<val<<endl;
    if(ans>=k)
        return true;
    return false;

}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>pri[i];
    sort(pri,pri+n);
    reverse(pri,pri+n);
    cin>>x>>a;
    cin>>y>>b>>k;
    if(y>x)
    {
        tem = x;
        x = y;
        y = tem;
        tem = a;
        a = b;
        b = tem;
    }

    ll l = 0,r=n,m;
    while(l<r)
    {
        m = (l+r);
        m/=2;
        if(isPoss(m))
        {
            r = m;
        }
        else
        {
            l = m+1;
        }
    }
    if(isPoss(l))
        cout<<l<<endl;
    else
        cout<<-1<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    int q;
    cin>>q;
    while(q>0)
    {
        solve();
        q--;
    }    
    
}