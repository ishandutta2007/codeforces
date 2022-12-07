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

//#define int ll
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

const int maxn = 3e5 + 7;

const ll inf = 1e9 + 7;
int n,q;
int arr[maxn];

class WaveletTree{
public:
    WaveletTree * lef, * rig;
    int lo, hi;
    vector<int> ci;

    WaveletTree(int * st, int * en, int l, int h)
    {
        lo = l;
        hi = h;
        lef = rig = NULL;
        if(st>=en || l==h)
            return;
        int num = en - st;
        int mid = (l+h)/2;
        auto f = [mid](int x){
            return x<=mid;
        };
        ci.pb(0);
        int prev = 0;
        for(auto i = st;i!=en;i++)
        {
            prev += f(*i);
            ci.pb(prev);
        }
        auto pivot = stable_partition(st, en, f);
        lef = new WaveletTree(st,pivot,l,mid);
        rig = new WaveletTree(pivot,en,mid+1,h);
    }

    int findKth(int l,int r, int k)
    {
        if(l>r)
            return -1;
        if(lo==hi)
            return lo;
        int lno = ci[r] - ci[l-1];
        if(k<=lno)
        {
            if(this->lef==NULL)
                return -1;
            return this->lef->findKth(ci[l-1]+1,ci[r],k);
        } else {
            if (this->rig == NULL)
                return -1;
            return this->rig->findKth(l - ci[l - 1], r - ci[r], k - lno);
        }
    }

    int count(int l, int r, int k)
    {
        if(l>r || k<lo || k>hi)
            return 0;
        if(lo==hi)
            return r - l+1;
        int mid = (lo+hi)/2;
        if(k<=mid)
        {
            return this->lef->count(ci[l-1]+1,ci[r],k);
        } else {
            return this->rig->count(l - ci[l - 1], r - ci[r], k);
        }
    }

    ~WaveletTree(){
        delete lef;
        delete rig;
    }
};

void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    WaveletTree wt(arr+1,arr+n+1,1,maxn);

    int k,l,d,r;
    int u,v,w,coun,req;
    for(int i=0;i<q;i++)
    {
        cin>>l>>r>>k;
        coun = r-l+1;
        req = coun/k;
        req++;
        u = req;
        w = 0;
        while(u<=coun)
        {
            v = wt.findKth(l,r,u);
            if(wt.count(l,r,v)>=req)
            {
                cout<<v<<endl;
                w = 1;
                break;
            }
            u+=req;
        }
        if(w==0)
            cout<<-1<<endl;
    }
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