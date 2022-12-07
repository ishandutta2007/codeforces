//#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define BSET(a, p) ((a) | (1ll << (p)))
#define BCHK(a, p) ((a) & (1ll << (p)))
#define BXOR(a, p) ((a) ^ (1ll << (p)))
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
    x = x%mod;
    ex = ex % (mod-1);
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 1e5 + 7;

const ll inf = 1e9 + 7;

int arr[maxn];
int mp[maxn];
int n,m;
int a,b;
int ans;

void remove(int idx)
{
    idx= arr[idx];
    if(idx+2>maxn)
    {
        return;
    }
    if(mp[idx]==idx)
    {
        ans--;
    }
    mp[idx]--;
    if(mp[idx]==idx)
    {
        ans++;
    }
}// TODO: remove value at idx from data structure
void add(int idx)
{
    idx = arr[idx];
    if(idx+2>maxn)
    {
        return;
    }
    if(mp[idx]==idx)
    {
        ans--;
    }
    mp[idx]++;
    if(mp[idx]==idx)
    {
        ans++;
    }
}// TODO: add value at idx from data structure
int get_answer()
{
    return ans;
}// TODO: extract the current answer of the data structure

int block_size;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<Query> qu;

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 1;
    int cur_r = 0;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}



void solve()
{
    memset(mp,0,sizeof(mp));
    cin>>n>>m;
    ans = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    Query q{};
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        q.l = a;
        q.r = b;
        q.idx = i;
        qu.pb(q);
    }

    vector<int> x = mo_s_algorithm(qu);

    for(auto c:x)
    {
        cout<<c<<endl;
    }

}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    PRELUDE;
    block_size = 319;
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}