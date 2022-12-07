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

const int maxn = 4e5 + 7;

const ll inf = 1e9 + 7;

int n;
vector<int> vals;
map<int,vector<int>> cou;//[maxn];

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    PRELUDE;

    cin>>n;
    
    int u,v,w,x,y;
    for(int i=0;i<n;i++)
    {
        cin>>u;
        vals.pb(u);
    }
    
    //memset(numCount,0,sizeof(numCounts));
    sort(all(vals));
    
    int coun = 1;
    for(int i=1;i<n;i++)
    {
        if(vals[i]==vals[i-1])
            coun++;
        else
        {
            dbg(cout<<vals[i-1]<<"->"<<coun<<endl;);
           cou[coun].pb(vals[i-1]); 
           coun=1;
        }   
    }   
    dbg(cout<<vals[n-1]<<"->"<<coun<<endl;);
    cou[coun].pb(vals[n-1]);

    int ans = 0;
    int rows=0,cols=0;
    
    int c,num;
    for(int r=1;r*r<=n;r++)
    {
        num = 0;
        for(auto val : cou)
        {
            u = val.fi;
            v = (val.sc).size();
            u = min(u,r);
            num+= u*v;
        }
        dbg(cout<<r<<" max: "<<num<<endl;);
        c = num/r;
        num = c*r;

        if(c<r)
            continue;
        
        if(ans<num)
        {
            ans = num;
            rows = r;
            cols = c;
        }
    }

    cout<<ans<<endl;
    cout<<rows<<" "<<cols<<endl;
    
    int mat[rows+1][cols+1];
    memset(mat,-1,sizeof(mat));

    set<pii> ms;
    coun = 1;
    for(int i=1;i<n;i++)
    {
        if(vals[i]==vals[i-1])
            coun++;
        else
        {
           coun = min(coun,rows);
           ms.insert({coun,vals[i-1]});
           coun=1;
        }   
    }   
    coun = min(coun,rows);
    ms.insert({coun,vals[n-1]});

    pii cv;
    num = ans;
    int xc = 0;
    int off = 0;
    int r;
    while(num>0 && ms.size()>0)
    {
        cv = *(ms.rbegin());
        ms.erase(cv);
        u = cv.fi;
        v = cv.sc;
        
        u = min(u,num);
        for(int i=0;i<u;i++)
        {
            r = xc;
            c = xc+off;
            c%=cols;
            mat[r][c] = v;

            xc++;
            if(xc==rows)
            {
                xc = 0;
                off++;
            }

            num--;
        }
    }
    //dbg(cout<<num<<endl); 
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}