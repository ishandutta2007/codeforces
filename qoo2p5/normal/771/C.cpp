#define __NO_INLINE__ 1

#include <bits/stdc++.h>

#define next reserved_0
#define prev reserved_1
#define y0 reserved_2
#define y1 reserved_3
#define fpos reserved_4

#define yes "YES\n"
#define no "NO\n"
//#define ok "OK\n"

#define vec vector
//#define sz(a) (int)(a).size()

#define fori(i, b, e) for(int i = (b); i < (e); i++)
#define forn(i, e) for(int i = 0; i < (e); i++)

#define endl '\n'
#define pb push_back
#define mp make_pair
#define up unzip_pair
#define MOD ((ll)1e+9+7)
#define EPS ((ld)1e-7)
#define fr first
#define sc second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

using namespace std;

const ld Pi = acosl((ld)-1);
const ll OO = ((ll)1e+18+100);
const int oo = 1e+9 + 100;

template <typename T>
inline ostream &operator<<(ostream &out, const vector<T> &v) {
  for(auto &it : v) out << it << ' ';
  return out;
}

template <typename T>
inline istream &operator>>(istream &in, vector<T> &v) {
  for(auto &it : v) in >> it;
  return in;
}

template <typename T1, typename T2>
inline ostream &operator<<(ostream &out, const pair <T1, T2> &p) {
    out << p.first << ' ' << p.second << ' ';
    return out;
}

template <typename T1, typename T2>
inline istream &operator>>(istream &in, pair <T1, T2> &p) {
    in >> p.first >> p.second;
    return in;
}

template <typename T>
inline ostream &operator<<(ostream &out, const set <T> &p) {
    for(auto &i : p) out << i << ' ';
    return out;
}

template <typename T>
inline istream &operator>(istream &in, T &p) {
    return in >> p;
}

template <typename T>
inline ostream &operator<(ostream &out, const T &p) {
    return out << p;
}

template <typename T1, typename T2>
inline pair<T1&,T2&> unzip_pair(T1 &p1, T2 &p2){return pair<T1&,T2&>(p1,p2);}

template <typename T>
inline bool umin(T &a, const T &b) {return a > b? a = b, 1: 0;}

template <typename T>
inline bool umax(T &a, const T &b) {return a < b? a = b, 1: 0;}

#ifdef LOCAL
#define err(...)  _dbg_buff = #__VA_ARGS__, _dbg_pos_1 = 0, _dbg_pos_2 = _dbg_buff.size(), _dbg(__VA_ARGS__), cerr < endl
#else
#define err(...) ((void)42)
#endif

string _dbg_buff;
int _dbg_pos_1, _dbg_pos_2, p1;

void _dbg_trim() {
    while(_dbg_buff[_dbg_pos_1] == ' ') _dbg_pos_1++;
    while(_dbg_buff[_dbg_pos_2-1] == ' ') _dbg_pos_2--;
}

template <typename T>
void _dbg(const T &a) {
    _dbg_trim();
    cerr < _dbg_buff.substr(_dbg_pos_1, _dbg_pos_2 - _dbg_pos_1) < " = ";
    cerr < a;
}

template <typename T1, typename ...T2>
void _dbg(const T1 &a, const T2&...ar) {
    int  p2, p;
    p2 = _dbg_pos_2;
    p = _dbg_buff.find(',', _dbg_pos_1);
    _dbg_pos_2 = p;
    _dbg(a);
    _dbg_pos_2 = p2;
    _dbg_pos_1 = p+1;
    cerr < ", ";
    _dbg(ar...);
}



///-----REALIZATION---------------------------------------------------------------
#ifdef LOCAL
const int N = 1001;
#else // LOCAL
const int N = 211010;
#endif // LOCAL



vec<int> nx[N];

ll cnt[N][6];


ll cur[N];

int k;

void go(int v, int u) {
    forn(i, k) {
        cnt[v][i+1] -= cnt[u][i];
    }
    cnt[v][1] -= cnt[u][k];
    cur[v] -= cnt[u][k];
    cur[v] -= cur[u];
    forn(i, k) {
        cnt[u][i+1] += cnt[v][i];
    }
    cnt[u][1] += cnt[v][k];
    cur[u] += cnt[v][k] + cur[v];
}

ll ans = 0;

void dfs(int v, int pr) {
    ans += cur[v];
    for(auto i : nx[v]) {
        if(i == pr) continue;
        go(v, i);
        dfs(i, v);
        go(i, v);
    }
}

void dd(int v, int pr) {
    cnt[v][0] = 1;
    for(auto i : nx[v]) {
        if(i == pr) continue;
        dd(i, v);
        forn(j, k) {
            cnt[v][j+1] += cnt[i][j];
        }
        cnt[v][1] += cnt[i][k];
        cur[v] += cnt[i][k];
        cur[v] += cur[i];
    }
    //err(v, cur[v], cnt[v][0], cnt[v][1], cnt[v][2]);
}

int run() {
    //cout << ((ll)N)*N*N;
    ll n;
    cin > n > k;
    forn(i, n-1) {
        int a, b;
        cin > a > b;
        a--;
        b--;
        nx[a].pb(b);
        nx[b].pb(a);
    }
    //dd(2, -1);
    //return 0;
    /*forn(i, n) {
        memset(cur, 0, sizeof cur);
        memset(cnt, 0, sizeof cnt);
        dd(i, -1);

        ans += cur[i];
        err(i, cur[i]);
    }*/
    dd(0, -1);
    dfs(0, -1);
    ans += n*(n-1);
    //err(ans);
    cout < ans/2;
    return 0;
}


signed main() {
    #ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #else
    //freopen("in.txt", "r", stdin);
    #endif // LOCAL
    cout < fixed < setprecision(7);
    cerr < fixed < setprecision(7);
///-----MAIN----------------------------------------------------------------------
    int t = 1;
    //cin > t;
    forn(i, t) run();
    return 0;
}