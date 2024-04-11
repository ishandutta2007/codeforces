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
#include <bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
//float __attribute__((aligned(32)))

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

const int Mod = 1e9 + 7;

int bpow(int x, int y){
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    int ret = bpow(x, y >> 1);
    ret = (ret * (ll)ret) % Mod;
    if (y & 1)
        ret = (ret * (ll)x) % Mod;
    return ret;
}

int bdiv(int x, int y){
    return (x * (ll)bpow(y, Mod - 2)) % Mod;
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

int gcd(int a, int b){
    return a ? gcd(b % a, a) : b;
}

const ll llinf = 2e18 + 100;

const double eps = 1e-9;

const int maxn = 1e5 + 100, maxw = 1e7 + 100, inf = 2e9 + 100, sq = 300, mod = 1e9 + 7, LG = 17;

int n;

vector<int> e[maxn];

pair<int, int> q[4 * maxn];

int upd[4 * maxn];

void push(int v, int l, int r){
    if (upd[v] == 0)
        return;
    q[v].first += upd[v];
    if (l != r)
        upd[2 * v] += upd[v],
        upd[2 * v + 1] += upd[v];
    upd[v] = 0;
}

int arr[maxn];

int mas[maxn];

void build(int v, int l, int r){
    if (l == r){
        q[v] = make_pair(arr[l], mas[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m + 1, r);
    q[v] = max(q[2 * v], q[2 * v + 1]);
}

void update(int v, int tl, int tr, int l, int r, int val){
    push(v, tl, tr);
    if (l > r)
        return;
    if (tl == l && tr == r){
        upd[v] += val;
        push(v, tl, tr);
        return;
    }
    int m = (tl + tr) / 2;
    update(2 * v, tl, m, l, min(r, m), val);
    update(2 * v + 1, m + 1, tr, max(l, m + 1), r, val);
    q[v] = max(q[2 * v], q[2 * v + 1]);
}

int dst[maxn];

void getfar(int v, int par){
    for (auto i : e[v])
    if (i != par)
        dst[i] = dst[v] + 1, getfar(i, v);
}

bool vis[maxn];

bool mark(int v, int par, int fin){
    if (v == fin){
        vis[v] = 1;
        return 1;
    }
    for (auto i : e[v])
    if (i != par && mark(i, v, fin)){
        vis[v] = 1;
        return 1;
    }
    return 0;
}

pair<int, int> g[maxn];

int p[maxn];

int cnt;

void dfs(int v, int par, int h){
    p[v] = par;
    g[v].first = cnt;
    if (e[v].size() == 1)
        arr[cnt] = h, mas[cnt++] = v;
    for (auto i : e[v])
    if (i != par)
        dfs(i, v, h + 1);
    g[v].second = cnt - 1;
}

void go(int v){
    while (!vis[v]){
        vis[v] = 1;
        update(1, 0, cnt - 1, g[v].first, g[v].second, -1);
        v = p[v];
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << 1;
    cin >> n;
    if (n == 1)
        return 0;
    for (int i = 1; i < n; i++){
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    getfar(0, -1);
    pair<int, int> wes;
    wes.first = -1;
    for (int i = 0; i < n; i++)
        wes = max(wes, make_pair(dst[i], i));
    int A = wes.second;
    dst[A] = 0;
    getfar(A, -1);
    wes.first = -1;
    for (int i = 0; i < n; i++)
        wes = max(wes, make_pair(dst[i], i));
    int B = wes.second;
    mark(A, -1, B);
    for (int i = 0; i < n; i++)
    if (vis[i])
        for (auto j : e[i])
        if (!vis[j])
            dfs(j, i, 1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    if (vis[i])
        ans++;
    cout << ' ' << ans;
    if (cnt == 0){
        for (int i = 2; i < n; i++)
            cout << ' ' << ans;
        return 0;
    }
    build(1, 0, cnt - 1);
    for (int i = 2; i < n; i++){
        pair<int, int> w = q[1];
        ans += w.first;
        go(w.second);
        cout << ' ' << ans;
    }
}