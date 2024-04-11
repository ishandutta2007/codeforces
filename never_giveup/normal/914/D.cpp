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

mt19937 rnd(1337);

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

const ll llinf = 2e18 + 100;

const int maxn = 5e5 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 300, mod = 1e9 + 7, LG = 17;

int n, zap;

int q[4 * maxn];

int a[maxn];

void build(int v, int l, int r){
    if (l == r){
        q[v] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m + 1, r);
    q[v] = __gcd(q[2 * v], q[2 * v + 1]);
}

void update(int v, int l, int r, int id, int val){
    if (l == r){
        q[v] = val;
        return;
    }
    int m = (l + r) / 2;
    if (id <= m)
        update(2 * v, l, m, id, val);
    else
        update(2 * v + 1, m + 1, r, id, val);
    q[v] = __gcd(q[2 * v], q[2 * v + 1]);
}

void get(int v, int tl, int tr, int l, int r, int &val){
    if (l > r)
        return;
    if (tl == l && tr == r){
        val = __gcd(val, q[v]);
        return;
    }
    int m = (tl + tr) / 2;
    get(2 * v, tl, m, l, min(r, m), val);
    get(2 * v + 1, m + 1, tr, max(l, m + 1), r, val);
}

int getid(int v, int tl, int tr, int l, int r, int val){
    if (l > r)
        return -1;
    int m = (tl + tr) / 2;
    if (tl == l && tr == r){
        if (q[v] % val == 0)
            return -1;
        if (l == r)
            return l;
        if (q[2 * v] % val != 0)
            return getid(2 * v, tl, m, l, m, val);
        return getid(2 * v + 1, m + 1, tr, m + 1, r, val);
    }
    int ret = getid(2 * v, tl, m, l, min(r, m), val);
    if (ret != -1)
        return ret;
    return getid(2 * v + 1, m + 1, tr, max(l, m + 1), r, val);
}

int main()
{
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //ifstream cin("sprinklers.in");
    //ofstream cout("sprinklers.out");
    //freopen("road.in", "r", stdin);
    //freopen("road.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);
    cin >> zap;
    while (zap--){
        int t;
        cin >> t;
        if (t == 1){
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            int id = getid(1, 0, n - 1, l, r, x);
            if (id == -1){
                cout << "YES\n";
                continue;
            }
            int y = x;
            get(1, 0, n - 1, l, id - 1, y);
            if (y != x){
                cout << "NO\n";
                continue;
            }
            get(1, 0, n - 1, id + 1, r, y);
            if (y != x)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
        else{
            int id, v;
            cin >> id >> v;
            update(1, 0, n - 1, id - 1, v);
            a[id - 1] = v;
        }
    }
}