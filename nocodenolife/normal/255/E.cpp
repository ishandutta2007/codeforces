#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
 
#define F first
#define S second 
#define pb push_back
//#define endl "\n"

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

const int maxn = 777777777777;

const ll inf = 1e9 + 7;
int n;
vector<pii> sg;

int findSg(int val)
{
    for(int i=sg.size()-1;i>=0;i--)
    {
        if(val>=sg[i].F)
            return sg[i].S;
    }
    cout<<"Problem"<<endl;
    return -1;
}

bool solve(int val)
{
    vector<int> mex;
    int x = sqrt(val);
    int y = sqrt(x);
    if(y*y*y*y<val)
        y++;
    //cout<<val<<" 1/4-> "<<y<<" 1/2-> "<<x<<endl;
    for(int i=y;i<=x;i++)
    {
        mex.pb(findSg(i));
    }

    sort(all(mex));
    mex.resize(distance(mex.begin(),unique(all(mex))));
    int an = 0;

    while(an<mex.size() && mex[an]==an)
        an++;

    if(an!= findSg(val-1))
    {
        sg.pb({val,an});
        return true;
    }
    return false;
    //cout<<val<<" "<<an<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    //cin>>n;
    sg.pb({0,0});
    sg.pb({4,1});
    sg.pb({16,2});
    sg.pb({82,0});
    sg.pb({6724,3});
    sg.pb({50626,1});
    sg.pb({2562991876,2});
    //set<int> events;
    //events.insert(4);
   // 
    //int x,y,u,v,w;
//
    //u = sqrt(maxn)+10;
    //v = sqrt(u)+10;
//
    //while(events.size())
    //{
        //x = *(events.begin());
        //events.erase(x);
        //if(solve(x))
        //{
            ////cout<<x<<endl;
            //if(x<=u)
            //{
                //w = x*x;
                //if(w<=maxn)
                    //events.insert(w);
            //}
            //w = x-1;
            //if(w<=v)
            //{
                //w = w*w*w*w;
                //w++;
                //if(w<=maxn)
                    //events.insert(w);
            //}
        //}
    //}
   // 
    //for(int i=0;i<sg.size();i++)
    //{
        //cout<<sg[i].F<<" "<<sg[i].S<<endl;
    //}
    
    
    cin>>n;
    int ans = 0,x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        ans = ans^findSg(x);
    }

    if(ans==0)
    {
        cout<<"Rublo"<<endl;
    }
    else
    {
        cout<<"Furlo"<<endl;
    }
     
}