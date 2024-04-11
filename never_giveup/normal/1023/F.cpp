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

#define fr first

#define sc second

#define m_p make_pair

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

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

mt19937 rnd(1227);

mt19937_64 rndll(12365);

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

const int Mod = 1e9 + 7;

int Bpow(int x, int y){
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

/*inline int ad(int x, int y){
    return x + y >= mod ? x + y - mod : x + y;
}

inline int dif(int x, int y){
    return x - y < 0 ? x - y + mod : x - y;
}

inline int mul(int x, int y){
    return (x * (ll)y) % mod;
}

int inv(int a){
    int b = mod, x = 0, y = 1;
    while (a){
        int t = b / a;
        b -= a * t;
        x -= t * y;
        swap(a, b);
        swap(x, y);
    }
    if (x < 0)
        x += mod;
    return x;
}*/

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

const ll llinf = 2e18 + 100;

const double eps = 1e-9;

const int maxn = 5e5 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 300, mod = 1e9 + 7, LG = 19;

int n, our, his;

int parent[maxn];

int rnk[maxn];

int hei[maxn];

int q[maxn];

int get(int x){
    return x == parent[x] ? x : parent[x] = get(parent[x]);
}

bool unite(int x, int y){
    x = get(x);
    y = get(y);
    if (x == y)
        return 0;
    if (rnk[x] < rnk[y])
        swap(x, y);
    parent[y] = x;
    if (rnk[x] == rnk[y])
        rnk[x]++;
    if (hei[q[x]] > hei[q[y]])
        q[x] = q[y];
    return 1;
}

int up[LG][maxn];

pair<int, int> seg[maxn];

bool anc(int v, int u){
    return seg[v].fr <= seg[u].fr && seg[v].sc >= seg[u].sc;
}

int getlca(int v, int u){
    if (hei[v] > hei[u])
        swap(v, u);
    if (anc(v, u))
        return v;
    for (int i = LG - 1; i >= 0; i--)
    if (!anc(up[i][v], u))
        v = up[i][v];
    return up[0][v];
}

int tnow;

vector<pair<int, int> > e[maxn];

int pars[maxn];

int ob[maxn];

void dfs(int v, int par){
    seg[v].fr = tnow++;
    parent[v] = v;
    rnk[v] = 0;
    q[v] = v;
    for (auto it : e[v]){
        int to = it.fr;
        if (to == par)
            continue;
        pars[to] = v;
        up[0][to] = v;
        hei[to] = hei[v] + 1;
        dfs(to, v);
        if (it.sc)
            unite(v, to);
        else
            ob[to] = -1;
    }
    seg[v].sc = tnow - 1;
}

vector<pair<int, pair<int, int> > > eh;

vector<pair<int, int> > eo;

bool good[maxn];

void add(pair<int, int> s, int w){
    e[s.fr].push_back(m_p(s.sc, w));
    e[s.sc].push_back(m_p(s.fr, w));
}

void upd(int v, int hbig, int w){
    while (hei[q[get(v)]] > hbig){
        int u = q[get(v)];
        ob[u] = w;
        unite(u, pars[u]);
    }
}

int main()
{
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //ifstream cin("gymnasts.in");
    //ofstream cout("gymnasts.out");
    //freopen("sort.in", "r", stdin);
    //freopen("sort.out", "w", stdout);
    #endif // ONPC
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    scanf("%d%d%d", &n, &our, &his);
    eo.resize(our);
    for (int i = 0; i < our; i++)
        scanf("%d%d", &eo[i].fr, &eo[i].sc),
        eo[i].fr--, eo[i].sc--;
    eh.resize(his);
    for (int i = 0; i < his; i++)
        scanf("%d%d%d", &eh[i].sc.fr, &eh[i].sc.sc, &eh[i].fr),
        eh[i].sc.fr--, eh[i].sc.sc--;
    for (int i = 0; i < n; i++)
        parent[i] = i;
    for (int i = 0; i < our; i++)
        unite(eo[i].fr, eo[i].sc),
        add(eo[i], 0);
    for (int i = 0; i < his; i++)
        if (unite(eh[i].sc.fr, eh[i].sc.sc))
            good[i] = 1, add(eh[i].sc, 1);
    dfs(0, -1);
    for (int j = 1; j < LG; j++)
        for (int i = 0; i < n; i++)
            up[j][i] = up[j - 1][up[j - 1][i]];
    for (int i = 0; i < his; i++)
    if (!good[i]){
        int v = eh[i].sc.fr, u = eh[i].sc.sc, w = eh[i].fr;
        int lca = getlca(v, u);
        upd(v, hei[lca], w);
        upd(u, hei[lca], w);
    }
    ll ans = 0;
    for (int i = 1; i < n; i++)
    if (ob[i] == -1){
        cout << -1;
        return 0;
    }
    else
        ans += ob[i];
    cout << ans;
}