//#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define BSET(a, p) ((a) | (1ll << (p)))
#define BCHK(a, p) ((a) & (1ll << (p)))
#define BXOR(a, p) ((a) ^ (1ll << (p)));
#define BREM(a, p) (BCHK(a, p)?(BXOR(a, p)):(a))
#define BSHO(a, N) (bitset<N>(a))

#define fi first
#define sc second 
#define pb push_back


#ifdef DEBUG
    #define dbg(s) {s;}
    #define PRELUDE
#endif

#ifndef DEBUG 
    #define PRELUDE { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
    #define dbg(s)
    #define endl "\n"
#endif

#define int ll
#define i32 int32_t

#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 
// Ordered set docs:
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

// To remove randomization use 0 below:
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int ri(int x) { // from [0, n-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

inline ld rf() { // from [0, 1]
    return uniform_real_distribution<ld>(0, 1)(rng);
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
const int N = 5001;
const ll inf = 1e9 + 7;
int n,m;
int sweet[N];
vector<int> grass[N];

pii cows[N];
vector<int> cowsSweet[N];
int maxi, ans;
int totcols;

void updateAns(int idx)
{
    int col = cows[idx].first;
    int swe = cows[idx].second;

    if(grass[col].size()<swe)
        return;

    int part = grass[col][swe-1];
    int lef,rig;
    int lefcoun, rigcoun, bothcoun, totcoun;
    int val = 1;
    int coun = 1,u,v;
    for(int i=1;i<=totcols;i++)
    {
        lef = 0;
        for(int j=0;j<grass[i].size();j++)
        {
            if(grass[i][j]<=part)
                lef++;
        }
        rig = grass[i].size() - lef;
        lefcoun = 0;
        rigcoun = 0;
        bothcoun = 0;
        totcoun = 0;
        if(i==col)
        {
            for(auto x : cowsSweet[i])
            {
                if(x==swe)
                    continue;
                if(x<=rig)
                    rigcoun++;
            }
            if(rigcoun==0)
                continue;
            val++;
            coun*=rigcoun;
            coun%=mod;
        } else{
            for(auto x : cowsSweet[i])
            {
                totcoun++;
                if(x<=lef && x<=rig)
                    bothcoun++;
                else if(x<=lef)
                    lefcoun++;
                else if(x<=rig)
                    rigcoun++;
                else
                    totcoun--;
            }
            if(totcoun==0)
                continue;
            else if(rigcoun==0 && bothcoun==0)
            {
                val++;
                coun*= lefcoun;
                coun%=mod;
            }
            else if(lefcoun==0 && bothcoun==0)
            {
                val++;
                coun*= rigcoun;
                coun%=mod;
            }
            else if(rigcoun==0 && lefcoun==0 && bothcoun==1)
            {
                val++;
                coun*=2;
                coun%=mod;
            }
            else
            {
                val+=2;
                u = lefcoun * rigcoun;
                u+= lefcoun * bothcoun;
                u+= rigcoun * bothcoun;
                u+= bothcoun * (bothcoun-1);
                u%=mod;
                coun*=u;
                coun%=mod;
            }
        }
    }
    //cout<<val<<" - "<<coun<<endl;
    if(val>maxi)
    {
        maxi = val;
        ans = coun;
    }
    else if(val==maxi)
    {
        ans+=coun;
    }
    ans%=mod;
}

void allRight(int idx)
{
    int col = cows[idx].first;
    int swe = cows[idx].second;

    if(grass[col].size()<swe)
        return;

    int part = grass[col][grass[col].size() - swe];
    int lef,rig;
    int rigcoun;
    int val = 1;
    int coun = 1,u,v;
    for(int i=1;i<=totcols;i++)
    {
        lef = 0;
        for(int j=0;j<grass[i].size();j++)
        {
            if(grass[i][j]<part)
                lef++;
        }
        rig = grass[i].size() - lef;
        rigcoun = 0;
        if(i==col)
        {
            continue;
        } else{
            for(auto x : cowsSweet[i])
            {
                if(x<=rig)
                    rigcoun++;
            }
            if(rigcoun==0)
                continue;
            else
            {
                val++;
                coun*=rigcoun;
                coun%=mod;
            }
        }
    }

    if(val>maxi)
    {
        maxi = val;
        ans = coun;
    }
    else if(val==maxi)
    {
        ans+=coun;
    }
    ans%=mod;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>sweet[i];
        grass[sweet[i]].pb(i);
    }
    for(int i=1;i<=n;i++)
    {
        sort(all(grass[i]));
    }
    totcols = 0;
    for(int i=1;i<=m;i++)
    {
        cin>>cows[i].fi>>cows[i].sc;
        totcols = max(totcols,cows[i].fi);
        cowsSweet[cows[i].fi].pb(cows[i].sc);
    }
    sort(cows+1,cows+m+1);
    maxi = 0;
    ans = 1;

    for(int i=1;i<=m;i++)
    {
        updateAns(i);
        allRight(i);
    }

    ans%=mod;
    cout<<maxi<<" "<<ans<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    PRELUDE;
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}