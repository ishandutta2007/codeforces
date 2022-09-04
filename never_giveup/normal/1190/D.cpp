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

#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())

#define low_bo(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()

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

const ll llinf = 4e18 + 100;

const double eps = 1e-9;

const int maxn = 2e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 7;

    int q[4 * maxn];
    vector<int> ids;
    void add(int w) {
        ids.push_back(w);
    }

    void pre() {
        sort(ids.begin(), ids.end());
        unique(ids);
    }

    void update(int v, int l, int r, int id) {
        if (l == r) {
            q[v] = 1;
            return;
        }
        int m = (l + r) / 2;
        if (id <= m)
            update(2 * v, l, m, id);
        else
            update(2 * v + 1, m + 1, r, id);
        q[v] = q[2 * v] + q[2 * v + 1];
    }

    int get(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (tl == l && tr == r)
            return q[v];
        int m = (tl + tr) / 2;
        return get(2 * v, tl, m, l, min(r, m)) + get(2 * v + 1, m + 1, tr, max(l, m + 1), r);
    }

    void update(int i) {
        update(1, 0, ids.size() - 1, lower_bound(ids.begin(), ids.end(), i) - ids.begin());
    }

    int get(int l, int r) {
        return get(1, 0, ids.size() - 1, upper_bound(ids.begin(), ids.end(), l) - ids.begin(), lower_bound(ids.begin(), ids.end(), r) - ids.begin() - 1);
    }


int main() {
    #ifdef ONPC
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //freopen("markchain.in", "r", stdin);
    //freopen("markchain.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int> > g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i].sc >> g[i].fr, add(g[i].sc);
    pre();
    sort(g.begin(), g.end());
    reverse(g.begin(), g.end());
    int L = 0, R = 0;
    ll ans = 0;
    auto fun = [&](int w) {
        return w * (ll)(w - 1) / 2;
    };
    while (L < n) {
        while (R < n && g[R].fr == g[L].fr)
            R++;
        vector<int> t(R - L);
        for (int i = L; i < R; i++)
            t[i - L] = g[i].sc;
        reverse(t.begin(), t.end());
        unique(t);
        for (int i = 1; i < t.size(); i++)
            ans -= fun(get(t[i - 1], t[i]));
        ans -= fun(get(0, t[0])) + fun(get(t.back(), int(1e9) + 1));
        for (int i = 0; i < t.size(); i++)
            update(t[i]);
        ans += fun(get(0, int(1e9) + 1));
        L = R;
    }
    cout << ans + n;
}