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

const int maxn = 1e6 + 7;

const ll inf = 1e9 + 7;
string s;

int findVal(string x)
{
    int val = 0;
    int num = 1;
    int m = x.length();
    m--;
    for(int i=m;i>=0;i--)
    {
        val+= num * (s[i]-'A'+1);
        num*=26;
    }

    return val;
}

string findEnc(string c)
{
    int val = 0;
    int num = 1;
    int m = c.length();
    m--;
    for(int i=m;i>=0;i--)
    {
        val += (c[i] - '0')*num;
        num = num*10;
    }

    string ans = "";
    char v;
    while(val>0)
    {
        m = val%26;
        if(m==0)
            m =26;
        m--;
        v = m + 'A';
        ans.pb(v);
        val -= m;
        val/=26;
    }
    reverse(all(ans));
    return ans;
}

void solve1()
{
    string x = "";
    string num = "";
    int i=0;
    while(i<s.length() && s[i]<='Z' && s[i]>='A')
        x.pb(s[i++]);
    while(i<s.length())
        num.pb(s[i++]);

    cout<<"R"<<num;
    cout<<"C";
    cout<<findVal(x)<<endl;
}

void solve2()
{
    string num="";
    string x = "";

    int i;
    for(i=1;i<s.length();i++)
    {
        if(s[i]=='C')
        {
            break;
        }
        num.pb(s[i]);
    }
    i++;

    for(;i<s.length();i++)
        x.pb(s[i]);

    cout<<findEnc(x)<<num<<endl;
}

void solve()
{
    cin>>s;
    int coun = 0;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]<='9' && s[i]>='0' && s[i-1]>='A' && s[i-1]<='Z')
        {
            coun++;
        }
    }

    if(coun==1)
        solve1();
    else
        solve2();
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    PRELUDE;
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}