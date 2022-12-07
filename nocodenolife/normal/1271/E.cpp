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

const int maxn = 107;

const ll inf = 1e9 + 7;

int n,dign,k;
int digitn[maxn];
int digity[maxn];

int numDigits(int x, int val)
{
    int dig = 0;
    while(x>0)
    {
        if(val==0)
        {
            digitn[dig] = x%2;
        }
        else
            digity[dig] = x%2;
        x/=2;
        dig++;
    }
    return dig;
}

/*int findNum(int y)
{
    dbg(cout<<"?"<<y<<endl;);
    //assert(x%2==0);
    if(y>n)
        return 0;
    int x = y;
    int ans = 0;
    if(y%2==0)
    {
        x/=2;
        ans--;
    }
    int digx = numDigits(x,-1); 
    //int ans = 0;
    int val = 1;
    int tem = digx;
    //dbg(cout<<digx<<" "<<dign<<endl;);
    while(tem<dign)
    {
        ans+=val;
        val*=2;
        tem++;
    }

    int idxx = digx-1;
    int idxn = dign-1;

    while(idxx>=0)
    {
        if(digitn[idxn]==digity[idxx])
        {
            idxx--;
            idxn--;
            continue;
        }
        dbg(cout<<"diff"<<endl;);
        if(digity[idxx]==1)
        {
            dbg(cout<<"Ans:"<<ans<<endl;);
            return ans;
        }
        else
        {
            ans+=val;
            dbg(cout<<"Ans:"<<ans<<endl;);
            return ans;
        }
    }
    
    val = 1;
    for(int i=0;i<idxn;i++)
        val*=2;

    while(idxn>=0)
    {
        if(digitn[idxn]==1)
            ans+=val;
        val/=2;
        idxn--;
    }
    ans+=val;
    dbg(cout<<"Ans:"<<ans<<endl;);
    return ans;
}*/

int findNum(int x)
{
    int ans = 0;
    if(x>n)
        return 0;
    int curl = x;
    int curr = x;
    ans++;

    if(x+1<=n && x%2==0)
    {
        curr++;
        ans++;
    }
    
    int val;
    while(true)
    {
        curl = curl*2;
        curr = curr*2+1;
        curr = min(curr,n);
        val=curr - curl +1;
        if(val<0)
            return ans;
        ans+=val;
    }
    return ans;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    PRELUDE;
    cin>>n>>k;
    dign = numDigits(n,0);

    int oddl,oddr,oddm;
    oddl = 1;
    oddr = n;
    if(n%2==0)
        oddr--;

    while(oddl<oddr)
    {
        oddm = oddl + oddr;
        oddm/=2;
        if(oddm%2==0)
            oddm++;
        dbg(cout<<oddm<<" "<<findNum(oddm)<<endl;);
        if(findNum(oddm)>=k)
        {
            oddl = oddm;
        }
        else
        {
            //dbg(cout<<"lef"<<endl;);
            oddr = oddm-2;
        }
    }

    int el,er,em;
    el = 2;
    er = n;
    if(n%2==1)
        er--;

    while(el<er)
    {
        em = el + er;
        em/=2;
        if(em%2==1)
            em++;
        if(findNum(em)>=k)
        {
            el = em;
        }
        else
        {
            er = em-2;
        }
    }
    
    if(findNum(el)<k)
    {
        cout<<oddl<<endl;
        return 0;
    }

    if(findNum(oddl)<k)
    {
        cout<<el<<endl;
        return 0;
    }
    
    el = max(el,oddl);
    cout<<el<<endl;
}