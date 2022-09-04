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

using namespace std;

typedef long long ll;

typedef long double ld;

mt19937 rnd(1337);

ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MODR = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MODR;
    XR = YR;
    YR = ZR;
    return ZR;
}

const int mod = 1e9 + 7;

int bpow(int x, int y){
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    int ret = bpow(x, y >> 1);
    ret = (ret * (ll)ret) % mod;
    if (y & 1)
        ret = (ret * (ll)x) % mod;
    return ret;
}

int bdiv(int x, int y){
    return (x * (ll)bpow(y, mod - 2)) % mod;
}

const ll llinf = 1e18 + 100;

const int maxn = 1e5 + 100, inf = 1e9 + 100, sq = 300;

typedef vector<pair<ll, int> > vt;

vt merge(vt &a, vt &b){
    int it = 0;
    vt c;
    c.reserve(a.size() + b.size());
    for (int i = 0; i < a.size(); i++){
        while (it < b.size() && b[it].first < a[i].first)
            c.push_back(b[it]), it++;
        if (it < b.size() && a[i].first == b[it].first)
            c.push_back(make_pair(a[i].first, a[i].second + b[it].second)), it++;
        else
            c.push_back(a[i]);
    }
    while (it < b.size())
        c.push_back(b[it]), it++;
    return c;
}

ll u[4 * maxn];

int u1[4 * maxn];

vt q[4 * maxn];

int a[maxn];

int n, zap;

void build(int v, int l, int r){
    if (l == r){
        q[v].push_back(make_pair(a[l], 1));
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m + 1, r);
    q[v] = merge(q[2 * v], q[2 * v + 1]);
}

void make(int v, int tp, ll val){
    if (tp == 0)
        u[v] += val;
    else
        u[v] = 0, u1[v] = val;
}

void push(int v, int l, int r){
    if (u1[v] > 0){
        q[v].clear();
        q[v].push_back(make_pair(u1[v], r - l + 1));
        if (l != r)
            make(2 * v, 1, u1[v]), make(2 * v + 1, 1, u1[v]);
        u1[v] = 0;
    }
    if (u[v] > 0){
        for (int i = 0; i < q[v].size(); i++)
            q[v][i].first += u[v];
        if (l != r)
            make(2 * v, 0, u[v]), make(2 * v + 1, 0, u[v]);
        u[v] = 0;
    }
}

void update1(int v, int tl, int tr, int l, int r, int val){
    push(v, tl, tr);
    if (l > r)
        return;
    if (tl == l && tr == r){
        make(v, 0, val);
        push(v, tl, tr);
        return;
    }
    int m = (tl + tr) / 2;
    update1(2 * v, tl, m, l, min(r, m), val);
    update1(2 * v + 1, m + 1, tr, max(l, m + 1), r, val);
    q[v] = merge(q[2 * v], q[2 * v + 1]);
}

void update2(int v, int tl, int tr, int l, int r, int val){
    push(v, tl, tr);
    if (l > r)
        return;
    if (tl == l && tr == r){
        make(v, 1, val);
        push(v, tl, tr);
        return;
    }
    int m = (tl + tr) / 2;
    update2(2 * v, tl, m, l, min(r, m), val);
    update2(2 * v + 1, m + 1, tr, max(l, m + 1), r, val);
    q[v] = merge(q[2 * v], q[2 * v + 1]);
}

vt get(int v, int tl, int tr, int l, int r){
    push(v, tl, tr);
    if (l > r)
        return {};
    if (tl == l && tr == r)
        return q[v];
    int m = (tl + tr) / 2;
    vt x = get(2 * v, tl, m, l, min(r, m)),
    y = get(2 * v + 1, m + 1, tr, max(l, m + 1), r);
    return merge(x, y);
}

int bpw(int x, int y, int md){
    if (y == 1)
        return x;
    int ret = bpw(x, y >> 1, md);
    ret = (ret * (ll)ret) % md;
    if (y & 1)
        ret = (ret * (ll)x) % md;
    return ret;
}

int seed, vmax;

int grand(){
    int ret = seed;
    seed = (seed * (ll)7 + 13) % mod;
    return ret;
}

int main()
{
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    //freopen("trap.in", "r", stdin);
    //freopen("trap.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> zap >> seed >> vmax;
    for (int i = 0; i < n; i++)
        a[i] = grand() % vmax + 1;
    build(1, 0, n - 1);
    while (zap--){
        int op = grand() % 4 + 1;
        int l = grand() % n + 1;
        int r = grand() % n + 1;
        if (l > r)
            swap(l, r);
        int x, y;
        if (op == 3)
            x = grand() % (r - l + 1) + 1;
        else
            x = grand() % vmax + 1;
        if (op == 4)
            y = grand() % vmax + 1;
        l--;
        r--;
        if (op == 4 && y == 1){
            cout << 0 << '\n';
            continue;
        }
        if (op == 1){
            update1(1, 0, n - 1, l, r, x);
        }
        else
        if (op == 2){
            update2(1, 0, n - 1, l, r, x);
        }
        else{
            vt g = get(1, 0, n - 1, l, r);
            if (op == 3){
                for (auto i : g){
                    if (x > i.second)
                        x -= i.second;
                    else{
                        cout << i.first << '\n';
                        break;
                    }
                }
            }
            else{
                int ans = 0;
                for (auto i : g)
                    ans = (ans + bpw(i.first % y, x, y) * (ll)i.second) % y;
                cout << ans << '\n';
            }
        }
    }
}