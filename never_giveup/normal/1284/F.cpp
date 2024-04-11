/*
                     .:*+=%@@@@@@=-.
                 .:=@#@@@#@@#######%==*.
              .-=####@######%*-.....:%##%.
            .*@###########%+:--........-%@-
          .*@##############@+--.........-:%-
        .+##################@==%%%%=+*:----+.
      .-@####################%++%@@@@@=+**%@@*
      .%###################@%%@@@###@%+:--%@@%.
     -@###################@%%%%*::*%++:-----=@+.
    -#####################@%=++++++*:-------.-=:
   .+####################@%++*::-:::--::*:::***=:
   .@#####################%=++*::::-:::++*=##@@#@-
  ..#####################@%%=++**:::::**+%@#@%%##-..
   .%####################@@%=+++*+****::*=@######@.
  .=######################@%%==+==++**+=@%@##@###+:...
  -#######################@@@%%%===++=@@@%=++===*::--...
  -########################@@@@@@@%==%%=++==@@:::::*:--.
..:#########################@@@@@@%%======++++::-..:-.--...
%#############################@###@%%@@%==%=%*----.--.::---.
#############################################*-:*:-:---*---- .
#############################################*--*--:---*---:-.
#############################################+--::--::-*::-::.
###########################################+:*-.---.---.:---*-..
###########################################**:-----------------.
##########################################@::**:--::::::--:::::-
###########################################:--:*:::::::::**::*+*
###########################################=:::***::::::**:::*+*
############################@@@@@@#########@+****::::********+++
############################@%%%%%@@@@@@@###%+***::::::::***+==+
############################@%%%%%%%%%%%@####=+:::-::::-::*+=%%+
#############################@%%%%%%%%%%@#####=::--------:*=%@%+
%###########################@%%%%==%%%%%%@##@#=:------..-:+%@@%=
----------------------------------------------
--------------------------------------------
----------------------------------------------
--------------------------------------------
----------------------------------------------

         o###########oo
      o##"          ""##o
    o#"                "##
  o#"                    "#o
 #"  ##              ##   "##
#"                          ##
#  ###################       #
#                            #
#                            #
#                            #
#                            #
#                            #
#                            #
#o                           #
"#o                         ##
 "#o                       ##
  "#o                    o#"
   "#o                  ##
     "#o              o#"
       "#ooo      ooo#######oo
        ###############   "######o
     o###""        "###o      # ###
   o###o     oooo    ###    oo####"
 o###**#     #**#   ############"
 ""##""""""""""###########    #
    # oooooooo#"#**     ##    #
    # #       # # **    ##    #
    #o#       #o#  *****###ooo#
                        ##
                        ##   o###o
                        ## o##***##
               o########## #***#**##o
             o##"   ""###  #***##***#
 o#######o  ###   oo####   ##**####*#
o##"  ""#############""     ##****###
##"         ##              ##*##*###
##          ###              ##### ##
##           ###              # ##  #
##            ##                 #
##             ##
##             ###
##              ###oo
###              ""###
 ###
  ###
*/

///YEAH IM THE BEST I'VE EVER WAS

///SO HAPPY

#include <bits/stdc++.h>

#define popcnt(x) __builtin_popcount(x)

#define fr first

#define sc second

#define m_p make_pair

#define low_bo(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()

#define up_bo(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()

#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())

#define popcnt(x) __builtin_popcount(x)

//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;

//gp_hash_table<int, int> table;

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
//float __attribute__((aligned(32)))

/*char memory[(int)1e8];

char memorypos;

inline void * operator new(size_t n){
    char * ret = memory + memorypos;
    memorypos += n;
    return (void *)ret;
}

inline void operator delete(void *){}
*/

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef unsigned int uint;

ll sqr(ll x){
    return x * x;
}

int mysqrt(ll x){
    int l = 0, r = 1e9 + 1;
    while (r - l > 1){
        int m = (l + r) / 2;
        if (m * (ll)m <= x)
            l = m;
        else
            r = m;
    }
    return l;
}

#ifdef ONPC
    mt19937 rnd(231);
    mt19937_64 rndll(231);
#else
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    mt19937_64 rndll(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MODR = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MODR;
    XR = YR;
    YR = ZR;
    return ZR;
}

int gcd(int a, int b){
    return a ? gcd(b % a, a) : b;
}

int gcdex(int a, int b, int &x, int &y){
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int ret = gcdex(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return ret;
}

int Mod = 1e9 + 993;

int Bpow(int x, ll y){
    int ret = 1;
    int w = x;
    while (y){
        if (y & 1)
            ret = (ret * (ll)w) % Mod;
        w = (w * (ll)w) % Mod;
        y >>= 1;
    }
    return ret;
}

int Bdiv(int x){
    int a, b;
    gcdex(x, Mod, a, b);
    if (a < 0)
        a += Mod;
    return a;
}

int Bdiv(int x, int y){
    return (x * (ll)Bpow(y, Mod - 2)) % Mod;
}

inline int ad(int x, int y){
    return x + y >= Mod ? x + y - Mod : x + y;
}

inline int dif(int x, int y){
    return x - y < 0 ? x - y + Mod : x - y;
}

inline int mul(int x, int y){
    return (x * (ll)y) % Mod;
}

int inv(int a){
    int b = Mod, x = 0, y = 1;
    while (a){
        int t = b / a;
        b -= a * t;
        x -= t * y;
        swap(a, b);
        swap(x, y);
    }
    if (x < 0)
        x += Mod;
    return x;
}

void setmin(int &x, int y){
    x = min(x, y);
}

void setmax(int &x, int y){
    x = max(x, y);
}

void setmin(ll &x, ll y){
    x = min(x, y);
}

void setmax(ll &x, ll y){
    x = max(x, y);
}

const ll llinf = 1e18 + 100;

const ld eps = 1e-9;

const int maxn = 5e5 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 100, X = 43, LG = 18, B = 3000;

vector<int> ed[maxn];

int n, hei[maxn], up[LG][maxn], par[maxn], rpos[maxn], spos[maxn];

int parent[maxn];

int dget(int w) {
    return w == parent[w] ? w : parent[w] = dget(parent[w]);
}

void duni(int x, int y) {
    x = dget(x);
    y = dget(y);
    if (x == y)
        return;
    if (hei[x] > hei[y])
        swap(x, y);
    parent[y] = x;
}

int fen[maxn], sz;

int fget(int i) {
    int w = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        w += fen[i];
    return w;
}

int get(int v) {
    return fget(rpos[v]);
}

int get(int v, int u) {
    return fget(rpos[u]) - fget(rpos[v]);
}

void inc(int i, int w) {
    for (; i < sz; i = (i | (i + 1)))
        fen[i] += w;
}

void upd(int i) {
    inc(rpos[i], -1);
    inc(spos[i], 1);
    duni(i, par[i]);
}

void dfs(int v, int ps) {
    par[v] = ps;
    for (int i : ed[v])
    if (i != ps) {
        hei[i] = hei[v] + 1;
        rpos[i] = sz++;
        dfs(i, v);
        spos[i] = sz++;
    }
}

void prec() {
    dfs(0, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    rpos[0] = -1;
    for (int i = 1; i < n; i++) {
        inc(rpos[i], 1);
        inc(spos[i], -1);
    }
    for (int i = 0; i < n; i++)
        up[0][i] = par[i];
    for (int j = 1; j < LG; j++)
        for (int i = 0; i < n; i++)
            up[j][i] = up[j - 1][up[j - 1][i]];
}

int getlca(int v, int u) {
    if (hei[v] < hei[u])
        swap(v, u);
    for (int i = LG - 1; i >= 0; i--)
        if (hei[v] - (1 << i) >= hei[u])
            v = up[i][v];
    if (v == u)
        return v;
    for (int i = LG - 1; i >= 0; i--)
        if (up[i][v] != up[i][u])
            v = up[i][v], u = up[i][u];
    return up[0][v];
}

pair<int, int> calc(int f1, int f2) {
    int f = getlca(f1, f2);
    {
        int o = dget(f1);
        if (hei[o] > hei[f]) {
            upd(o);
            return {o, par[o]};
        }
    }
    for (int i = LG - 1; i >= 0; i--)
        if (hei[f2] - (1 << i) > hei[f] && get(f, up[i][f2]))
            f2 = up[i][f2];
    if (f2 != f && dget(f2) == f2) {
        upd(f2);
        return {f2, par[f2]};
    }
    return {-1, -1};
}

set<int> nig[maxn];

int main() {
    #ifdef ONPC
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        ed[v].push_back(u);
        ed[u].push_back(v);
    }
    prec();
    set<pair<int, int> > degs;
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        nig[v].insert(u);
        nig[u].insert(v);
    }
    for (int i = 0; i < n; i++)
        degs.insert({nig[i].size(), i});
    vector<vector<int> > ans;
    for (int iter = 1; iter < n; iter++) {
        int f1 = degs.begin()->sc;
        degs.erase(degs.begin());
        int f2 = *nig[f1].begin();
        //cerr << f1 << ' ' << f2 << '\n';
        degs.erase({nig[f2].size(), f2});
        nig[f2].erase(f1);
        if (!nig[f2].empty())
            degs.insert({nig[f2].size(), f2});
        auto so = calc(f1, f2);
        if (so.fr != -1)
            ans.push_back({so.fr, so.sc, f1, f2});
    }
    //assert(ans.size() + 1 == n);
    cout << ans.size() << '\n';
    for (auto i : ans) {
        for (int j : i)
            cout << j + 1 << ' ';
        cout << '\n';
    }
    /// uberi assert
}