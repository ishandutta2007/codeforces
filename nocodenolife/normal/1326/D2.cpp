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

const ll inf = 1e9 + 7;

int findMaxPrePal(string s)
{
    string rev="",str=s;
    int m=s.size(),longestPalindromicPrefix=1;
    if(m==0 || m==1)    longestPalindromicPrefix=m;
    for(int i=m-1;i>=0;i--)
        rev+=s[i];
    s+='#';
    s+=rev;
    int n=s.size(),z[n+4],l=0,r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n && s[r-l]==s[r])
                r++;
            z[i]=r-l,r--;
        }
        else{
            int k=i-l;
            if(z[k]<r-i+1)
                z[i]=z[k];
            else{
                l=i;
                while(r<n && s[r-l]==s[r])
                    r++;
                z[i]=r-l,r--;
            }
        }
    }

    for(int i=m+1;i<n;i++){
        if(2*z[i]>=2*m-i && z[i]>longestPalindromicPrefix)
            longestPalindromicPrefix=z[i];
    }
    return longestPalindromicPrefix;
}

void solve()
{
    string s;
    cin>>s;
    int n = s.length();

    int i = 0;
    int j = n-1;
    while(i<j)
    {
        if(s[i]!=s[j])
            break;
        i++;
        j--;
    }
    if(i>=j)
    {
        cout<<s<<endl;
        return;
    }
    string x = "";
    for(int k=i;k<=j;k++)
    {
        x.pb(s[k]);
    }
    int c1 = findMaxPrePal(x);
    reverse(all(x));
    int c2 = findMaxPrePal(x);
   // cout<<c1<<" "<<c2<<" ";
    if(c1>c2)
    {
        for(int k=0;k<i;k++)
            cout<<s[k];
        for(int k=0;k<c1;k++)
            cout<<s[i+k];
        for(int k=j+1;k<n;k++)
            cout<<s[k];
    } else{
        for(int k=0;k<i;k++)
            cout<<s[k];
        for(int k=c2-1;k>=0;k--)
            cout<<s[j-k];
        for(int k=j+1;k<n;k++)
            cout<<s[k];
    }
    cout<<endl;


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