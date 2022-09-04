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

const int Mod = 998244353;

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

const ll llinf = 1e18 + 100;

const double eps = 1e-9;

const int maxn = 1e6 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, mod = 1e9 + 7;

int q[1000][1000];

vector<pair<int, int> > a1;

vector<int> a;

vector<int> pos[500];

pair<int, int> segs[500];

int calc(int l, int r) {
    if (l > r)
        return 1;
    if (l == r) {
        if (segs[a[l]].fr != segs[a[l]].sc)
            return 0;
        return 1;
    }
    if (q[l][r] == -1) {
        q[l][r] = 0;
        int id = inf;
        for (int i = l; i <= r; i++)
            setmin(id, a[i]);
        int L = segs[id].fr, R = segs[id].sc;
        auto inside = [&](int l1, int r1, int l2, int r2) {
            return l1 <= l2 && r1 >= r2;
        };
        if (!inside(l, r, L, R))
            return 0;
        for (int i = l; i < L; i++)
            if (!inside(l, L - 1, segs[a[i]].fr, segs[a[i]].sc))
                return 0;
        for (int i = L; i <= R; i++)
            if (!inside(L, R, segs[a[i]].fr, segs[a[i]].sc))
                return 0;
        for (int i = R + 1; i <= r; i++)
            if (!inside(R + 1, r, segs[a[i]].fr, segs[a[i]].sc))
                return 0;
        int lg = L, rg = R;
        int S = 0;
        for (int i = L; i >= l; i--) {
            setmin(lg, segs[a[i]].fr);
            if (lg == i)
                S = ad(S, mul(calc(l, i - 1), calc(i, L - 1)));
        }
        for (int i = R; i <= r; i++) {
            setmax(rg, segs[a[i]].sc);
            if (rg == i)
                q[l][r] = ad(q[l][r], mul(calc(R + 1, i), calc(i + 1, r)));
        }
        q[l][r] = mul(q[l][r], S);
        S = 1;
        int last = L + 1;
        int it = 0;
        for (int i = L + 1; i < R; i++) {
            while (it < pos[id].size() && pos[id][it] <= a1[i - 1].fr)
                it++;
            if (it < pos[id].size() && pos[id][it] < a1[i].fr) {
                S = mul(S, calc(last, i - 1));
                last = i;
            }
        }
        S = mul(S, calc(last, R - 1));
        q[l][r] = mul(q[l][r], S);
    }
    return q[l][r];
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
    int n, m;
    cin >> n >> m;
    a.reserve(1000);
    for (int i = 0; i < n; i++)
        segs[i].fr = inf;
    for (int i = 0; i < m; i++) {
        int w;
        cin >> w;
        w--;
        pos[w].push_back(i);
        if (segs[w].fr == inf)
            segs[w].fr = i;
        segs[w].sc = i;
    }
    for (int i = 0; i < n; i++) {
        a1.push_back({segs[i].fr, i});
        if (segs[i].fr != segs[i].sc)
            a1.push_back({segs[i].sc, i});
    }
    sort(a1.begin(), a1.end());
    a.resize(a1.size());
    for (int i = 0; i < a.size(); i++)
        a[i] = a1[i].sc;
    for (int i = 0; i < n; i++)
        segs[i].fr = inf, segs[i].sc = 0;
    for (int i = 0; i < a.size(); i++) {
        int w = a[i];
        if (segs[w].fr == inf)
            segs[w].fr = i;
        segs[w].sc = i;
    }
    for (int i = 0; i < n; i++) {
        vector<int> g;
        int it = 0;
        for (int j = 0; j < a.size(); j++) {
            if (it < pos[i].size() && pos[i][it] <= a1[j].fr)
                g.push_back(pos[i][it]);
            while (it < pos[i].size() && pos[i][it] <= a1[j].fr)
                it++;
        }
        swap(pos[i], g);
    }
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a.size(); j++)
            q[i][j] = -1;
    cout << calc(0, a.size() - 1) << '\n';
}