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

const int maxn = 1e6 + 7;

const ll inf = 1e9 + 7;
map<int, vector<int>> v;
map<vector<int>, int> w;
 
int solve(vector<int> v){
    sort(all(v));
    v.resize(distance(v.begin(),unique(all(v))));
    if(!v.empty() && v.front() == 0) v.erase(v.begin());

    if (w.count(v) || v.empty()){
        return w[v];
    }
    bool ok = 0;
    vector<int> q, f;
    for (int x = 1; x <= v[v.size()-1]; x++){
        q = v;
        for (int &y : q){
            if (y >= x){
                y -= x;
            }
        }
        f.pb(solve(q));
    }
    int mex = 0;
    sort(all(f));
    for (int x : f){
        if (x == mex) mex++;
    }
    return w[v] = mex; 
}

void addNum(int x)
{
    int p;
    for(int i=2;i*i<=x;i++)
    {
        p = 0;
        while(x%i==0)
        {
            p++;
            x/=i;
        }
        if(p==0)
            continue;
        v[i].pb(p);
    }

    if(x>1)
    {
        v[x].pb(1);
    }

}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    //memset(dp,-1,sizeof(dp));
    //dp[0][0] = 0;
    //precomp();
    int n;
    cin>>n;

    int x;
    for(int i=0;i<n;i++)
    {   
        cin>>x;
        addNum(x);
    }

    int ans = 0;
    vector<int> d;
    for(auto p:v)
    {
        //cout<<v<<" "<<mini[v]<<" "<<maxi[v]<<" "<<dp[mini[v]][maxi[v]]<<endl;
        //ans = ans ^ dp[mini[v]][maxi[v]];
        //d = p.S;
        //sort(all(d));
        //d.resize(distance(d.begin(),unique(all(d))));
 
        ans ^= solve(p.S);
        //cout<<p.F<<" "<<solve(p.S)<<endl;
    }

    if(ans==0)
    {
        cout<<"Arpa"<<endl;
    }
    else
    {
        cout<<"Mojtaba"<<endl;
    }
}