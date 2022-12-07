/* aman36 - Aman Raj */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define AfterDecimal(n) cout << fixed << setprecision(n);
#define pb push_back
#define pp(a, b) pair <a, b>
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define pi pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define itr iterator
#define bits(x) __builtin_popcount(x)
#define fori(n)  for (ll i = 0; i < n; i++)
#define forj(n)  for (ll j = 0; j < n; j++)
#define fork(n)  for (ll k = 0; k < n; k++)
#define forlp(k,x,n)  for (ll k = x; k <= n; k++)
#define vll vector <ll>
#define mll map <ll, ll>
#define vpll vector <pll>
#define mem(x) memset(x, 0, sizeof(x));
// #define int ll
//#define endl "\n"
 
using namespace __gnu_pbds;
using namespace std;
 
template <class T> T printr(T p) { cout << p << '\n'; return 0; }
template <class T> T printe(T p) { cout << p << '\n'; exit(0); }
template <class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template <class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
 
template <typename T> using ordered_set =
 tree<T, null_type, less<T>, rb_tree_tag, 
 tree_order_statistics_node_update>;
 
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << "# "<< name << " = " << arg1 << '\n';
}
template<typename Arg1, typename... Args>
void __f(const char* names, Arg1 && arg1, Args &&... args){
        const char* comma = strchr(names + 1 ,',');
        cout << "# ";
        cout.write(names, comma - names)<< " = " << arg1 << " | ";
        __f(comma + 1, args...);
}
#else
#define debug(...) 36
#endif

ll mxm() {return LLONG_MIN;}
template<typename... Args>
ll mxm(ll a, Args... args) { return max(a,mxm(args...)); }
 
ll mnm() {return LLONG_MAX;}
template<typename... Args>
ll mnm(ll a, Args... args) { return min(a,mnm(args...)); }

template<class T> ostream& operator<<(ostream& os,vector<T> V){
    os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";
}
template<class L,class R> ostream& operator<<(ostream& os,pair<L,R> P){
    return os<<"("<<P.first<<","<<P.second<<")";
}

int power(int lx, int ly, int p) { 
    ll res = 1;
    ll x = lx;
    ll y = ly;
    x = x % p;  
    while (y > 0) {
        if (y & 1) 
            res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p; 
    }
    return (int)res;
}

bool isPrime(int n) 
{ 
    if (n <= 1) return false; 
    if (n <= 3) return true; 
    if (n % 2 == 0 || n % 3 == 0) return false;  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true; 
}


const ll INF = (ll)(8e18);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int maxn = 1e6+5;
// check the limits

pll next(pll cur, char c) {
    if(c == 'L') return {cur.F, cur.S-1};
    if(c == 'R') return {cur.F, cur.S+1};
    if(c == 'U') return {cur.F-1, cur.S};
    if(c == 'D') return {cur.F+1, cur.S};
}

int n, m;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0}; 
int total = 0, black = 0;

vector<bool> c[maxn];
vector<int> vis[maxn];
string s[maxn];
bool color[maxn];

void chain(pll q, int d, int index, int cycSize) {
    //cout<<q.F<<"->"<<q.S<<endl;
    
    //int m = (index-d+cycSize*maxn) % cycSize;
    int z = (index + cycSize - (d%cycSize)) %cycSize;
    
    vis[q.F][q.S] = 1;
    if(c[q.F][q.S] == 0 && color[z] == 1) {
        color[z] = 0;
    }

    fori(4) {
        pll r = {q.F + dx[i], q.S + dy[i]};
        if(r.F>=0 && r.S>=0 && r.F<n && r.S<m && next(r, s[r.F][r.S]) == q && vis[r.F][r.S]!=1) {
            chain(r, d+1, index, cycSize);
        }
    }
}

void start(int i, int j) {
    vpll v;
    while (vis[i][j] != 2)
    {
        vis[i][j] = 2;
        pll nx = next({i, j}, s[i][j]);
        i = nx.F, j = nx.S;
    }
    while (vis[i][j] != 1)
    {
        vis[i][j] = 1;
        pll nx = next({i, j}, s[i][j]);
        i = nx.F, j = nx.S;
    }
    v.pb({i,j});
    //cout<<i<<" "<<j<<endl;
    pll p = next({i, j}, s[i][j]);
    i = p.F, j = p.S;
    while (p != v[0])
    {
        v.pb(p);
        p = next(p, s[i][j]);
        i = p.F, j = p.S;
    }

    int cycSize = v.size();

    int y=0;
    for(auto x : v) {
        color[y] = (c[x.F][x.S]);
        y++;
    }

    int index = 0;
    for(auto x : v) {
        fork(4) {
            pll q = {x.F + dx[k], x.S + dy[k]};
            if(q.F>=0 && q.S>=0 && q.F<n && q.S<m && next(q, s[q.F][q.S]) == x && vis[q.F][q.S]!=1) {
                //cout<<q.F<<"->"<<q.S<<endl;
                chain(q, 1, index, cycSize);
            }
        }
        index++;
    }

    total += cycSize;
    for(int k=0; k<cycSize; k++) {
        if(color[k] == 0) black++;
    }
    debug(total, black);
}
 
int32_t main() {
    IOS;
    #ifndef ONLINe5E_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        total = 0, black = 0;
        fori(n) {
            c[i].resize(m);
            vis[i].resize(m);
            string r;
            cin >> r;
            forj(m) {
                c[i][j] = (r[j]-'0');
                vis[i][j] = 0;
            }
        }

        fori(n) cin >> s[i];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j]) {
                    //cout<<i<<","<<j<<endl;
                    start(i, j);
                }
            }
        }

        cout << total << " " << black << endl;
    }
    
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}

/* g++ -DLOCAL -DDEBUG -std=c++17 -Wshadow -Wall -o "c" "icpc.cpp" 
-fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g */

// read the question correctly
// read code carefully
// corner cases // int vs ll // cin vs scanf // clear structures // maths
// check max, min set to INT_MAX instead INF
// check constraints