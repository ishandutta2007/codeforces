//#define DEBUG
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <tuple>
#include <climits>
#include <limits>
#include <deque>
#include <list>
#include <array>
#include <stack>
#include <queue>
#include <random>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
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
const int maxval = 1e9;
const ll inf = 1e9 + 7;


struct LiChao{
    int l,r;
    struct LiChao * lef;
    struct LiChao * rig;
    pii line;
};
typedef  struct LiChao lichao;

int evalLine(pii line, int x)
{
    int val = line.fi * x + line.sc;
    return val;
}

lichao * createNode(int lr, int rr, pii lin)
{
    lichao * newNode = (lichao *)malloc(sizeof(lichao));
    newNode->l = lr;
    newNode->r = rr;
    newNode->line  =lin;
    newNode->lef = nullptr;
    newNode->rig = nullptr;
    return newNode;
}

void createChildren(lichao * root)
{
    if(root->l==root->r)
        return;
    int m = root->l+root->r;
    m/=2;
    root->lef = createNode(root->l, m, root->line);
    root->rig = createNode(m+1,root->r, root->line);
}

void addLine(pii lin, lichao * root)
{
    if(root==NULL)
        return;
    if(root->lef==NULL)
        createChildren(root);
    int ll, lr, lm;
    ll = root->l;
    lr = root->r;
    lm = ll+lr;
    lm  /=2;

    if(evalLine(lin,lm) > evalLine(root->line,lm))
    {
        //cout<<ll<<" "<<lr<<" "<<lm<<endl;
        //cout<<lin.fi<<" "<<lin.sc<<" > "<<root->line.fi<<" "<<root->line.sc<<" for "<<lm<<endl;
        swap(lin,root->line);
        //cout<<lin.fi<<" "<<lin.sc<<" > "<<root->line.fi<<" "<<root->line.sc<<" after "<<lm<<endl;

    }
    if(evalLine(lin,ll) > evalLine(root->line,ll))
    {
        addLine(lin,root->lef);
    } else{
        addLine(lin,root->rig);
    }
}

void printTree(lichao * root)
{
    if(root==NULL)
        return;
    if(root->l==1 &&root->r==4 )
        cout<<root->l<<" "<<root->r<<"->"<<root->line.fi<<" "<<root->line.sc<<endl;
    printTree(root->lef);
    printTree(root->rig);
}

int getMaximum(int x, lichao * root)
{
    if(root==NULL)
        return 0;
    int ll, lr, lm,ans;
    ll = root->l;
    lr = root->r;
    lm = ll+lr;
    lm /=2;

    ans = evalLine(root->line,x);
    if(x<=lm)
    {
        ans = max(ans,getMaximum(x,root->lef));
    } else{
        ans = max(ans,getMaximum(x,root->rig));
    }
    return ans;
}

void solve()
{
    lichao * root = createNode(1,maxval,{0,0});

    int n;
    cin>>n;

    vector<pair<pii,int>> q;

    int x,y,a;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>a;
        q.pb({{x,y},a});
    }
    sort(all(q));
    reverse(all(q));

    int ans = 0;
    int dp;

    for(auto c: q)
    {
        //cout<<c.fi.fi<<" "<<c.fi.sc<<" "<<c.sc<<"->";
        dp  = (c.fi.fi * c.fi.sc)  - c.sc;
        dp = dp + getMaximum(c.fi.fi, root);
        //cout<<dp<<" "<<endl;
        ans = max(ans,dp);
        //printTree(root);
        addLine({-c.fi.sc, dp},root);
        //printTree(root);
    }

    cout<<ans<<endl;
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