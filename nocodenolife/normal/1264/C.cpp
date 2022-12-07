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

const ll mod = 998244353;

ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

ll inv(ll x)
{
    return modexp(x,mod-2);
}

const int maxn = 2e5 + 7;

const ll inf = 1e9 + 7;

int n,q;
ll prob[maxn];
ll premul[maxn];
ll invpre[maxn];
ll premulsum[maxn];

void takeInp()
{
    cin>>n>>q;
    prob[0]=1;
    premul[0] = 1;
    invpre[0] = 1;
    premulsum[0] = 0;
    
    int hundinv = inv(100);
    for(int i=1;i<=n;i++)
    {
        cin>>prob[i];
        prob[i] = (prob[i]*hundinv)%mod;
        premul[i] = (premul[i-1]*prob[i])%mod;
        invpre[i] = inv(premul[i]);
        premulsum[i] = (premulsum[i-1]+premul[i])%mod;

        //cout<<prob[i]<<" "<<premul[i]<<" "<<premulsum[i]<<endl;
    }
}

int findAns(int l, int r) {
    int num = (premulsum[r-1] - premulsum[l-1] + mod)%mod;
    num = (num*invpre[l-1])%mod;
    num++;
    //cout<<num<<endl;
    num = (num*invpre[r])%mod;
    //cout<<num<<endl;
    num = (num*premul[l-1])%mod;
    return num;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    takeInp();
    set<int> checkPoints;
    checkPoints.insert(1);
    checkPoints.insert(n+1);
    int ans = findAns(1,n);
    //cout<<ans<<endl;

    int x,l,r;
    auto ip = checkPoints.begin();
    for(int i=0;i<q;i++)
    {
        cin>>x;
        if(checkPoints.find(x)==checkPoints.end())
        {
            ip = checkPoints.upper_bound(x);
            r = *ip;
            ip--;
            l = *ip;
            ans+=findAns(l,x-1);
            ans+=findAns(x,r-1);
            ans-=findAns(l,r-1);
            //cout<<findAns(x,r-1)<<endl;
            checkPoints.insert(x);
            ans = (ans+mod)%mod;
        }
        else
        {
            checkPoints.erase(x);
            ip = checkPoints.upper_bound(x);
            r = *ip;
            ip--;
            l = *ip;
            ans-=findAns(l,x-1);
            ans-=findAns(x,r-1);
            ans+=findAns(l,r-1);

            ans = (ans+mod+mod)%mod;
        }
        //cout<<l<<" "<<r<<endl;
        cout<<ans<<endl;
    }
}