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

const int maxn = 1e5 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 300, mod = 1e9 + 7, LG = 17;

int o(int x){
    if (x >= mod)
        x -= mod;
    return x;
}

int f(ll x){
    return x % mod;
}

int H, W, N;

stack<pair<int, int> > a[maxn];

int q[4 * maxn];

void update(int v, int l, int r, int id, pair<int, int> val){
    if (l == r){
        a[l].push(val);
        q[v] = val.first;
        return;
    }
    int m = (l + r) / 2;
    if (id <= m)
        update(2 * v, l, m, id, val);
    else
        update(2 * v + 1, m + 1, r, id, val);
    q[v] = min(q[2 * v], q[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r, int val){
    if (l > r || q[v] > val)
        return 0;
    if (tl == tr){
        int ret = 0;
        while (!a[l].empty() && a[l].top().first <= val){
            ret = o(ret + a[l].top().second);
            a[l].pop();
        }
        q[v] = (a[l].empty() ? inf : a[l].top().first);
        return ret;
    }
    int m = (tl + tr) / 2;
    int ret = o(get(2 * v, tl, m, l, min(r, m), val) + get(2 * v + 1, m + 1, tr, max(l, m + 1), r, val));
    q[v] = min(q[2 * v], q[2 * v + 1]);
    return ret;
}

void build(int v, int l, int r, int val){
    q[v] = val;
    if (l == r){
        a[l].push(make_pair(val, 1));
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m, val);
    build(2 * v + 1, m + 1, r, val);
}

pair<pair<int, int>, pair<int, int> > arr[maxn];

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
    cin >> H >> W >> N;
    build(1, 1, W, H + 1);
    for (int i = 0; i < N; i++)
        cin >> arr[i].first.first >> arr[i].second.first >> arr[i].second.second >> arr[i].first.second;
    sort(arr, arr + N);
    reverse(arr, arr + N);
    for (int i = 0; i < N; i++){
        int hl = arr[i].first.first, hr = hl + arr[i].first.second, l = arr[i].second.first, r = arr[i].second.second;
        int val = get(1, 1, W, l, r, hr);
        if (val == 0)
            continue;
        if (l == 1)
            update(1, 1, W, r + 1, make_pair(hl, o(2 * val)));
        else
        if (r == W)
            update(1, 1, W, l - 1, make_pair(hl, o(2 * val)));
        else
            update(1, 1, W, l - 1, make_pair(hl, val)), update(1, 1, W, r + 1, make_pair(hl, val));
    }
    cout << get(1, 1, W, 1, W, inf);
}