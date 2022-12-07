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

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    vector<int>c(1000+5);
    vector<string>a(1000+5),b(1000+5);
    map<string,int>q,q1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s,s1;
        cin>>s>>s1;
        a[i]=s.substr(0,3);
        b[i]=s.substr(0,2)+s1.substr(0,1);
        q[a[i]]++;
       // cout<<a[i]<<b[i];
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        if (c[j]==0)
        {
            if (q1[a[j]]==1)
            {
                c[j]=1;
                q[a[j]]--;
                q[b[j]]++;
            }
            else
            {
                if (q[a[j]]>1)
                {
                    c[j]=1;
                    q[a[j]]--;
                    q[b[j]]++;
                    q1[a[j]]=1;
                }
            }
        }
    }
   // for(int i=0;i<n;i++)
       // cout<<q[a[i]]<<' '<<q[b[i]];
    for(int i=0;i<n;i++)
        if ((q[a[i]]>=2)or(q[b[i]]>=2))
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
        if (c[i]==0)
        cout<<a[i]<<endl;
    else cout<<b[i]<<endl;
    
    
}