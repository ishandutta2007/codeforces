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

const int maxn = 4e5 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 300, mod = 1e9 + 7, LG = 17;

#ifdef ONPC
    int lg = 19;
#else
    int lg = 19;
#endif // ONPC

int n;

pair<ll, int> q[19][maxn];

pair<int, int> up[19][maxn];

int w[maxn];

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
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    ll answer = 0;
    q[0][0].second = -1;
    up[0][0].second = -1;
    for (int i = 1; i < lg; i++)
        q[i][0] = make_pair(-1, -1), up[i][0] = q[i][0];
    n = 1;
    int zaps;
    scanf("%d", &zaps);
    while (zaps--){
        int typ;
        scanf("%d", &typ);
        if (typ == 1){
            ll par, wei;
            scanf("%I64d%I64d", &par, &wei);
            par ^= answer;
            wei ^= answer;
            par--;
            w[n] = wei;
            up[0][n] = make_pair(wei, par);
            for (int i = 1; i < lg; i++)
            if (up[i - 1][n].second != -1 && up[i - 1][up[i - 1][n].second].first != -1)
                up[i][n] = make_pair(max(up[i - 1][n].first, up[i - 1][up[i - 1][n].second].first), up[i - 1][up[i - 1][n].second].second);
            else
                up[i][n] = make_pair(-1, -1);
            int id = par;
            for (int i = lg - 1; i >= 0 && id >= 0; i--)
            if (up[i][id].first != -1 && up[i][id].first < wei)
                id = up[i][id].second;
            q[0][n] = make_pair(wei, id);
            for (int i = 1; i < lg; i++)
            if (q[i - 1][n].second != -1 && q[i - 1][q[i - 1][n].second].first != -1)
                q[i][n] = make_pair(q[i - 1][n].first + q[i - 1][q[i - 1][n].second].first, q[i - 1][q[i - 1][n].second].second);
            else
                q[i][n] = make_pair(-1, -1);
            n++;
        }
        else{
            ll id, sum;
            scanf("%I64d%I64d", &id, &sum);
            id ^= answer;
            sum ^= answer;
            id--;
            answer = 0;
            for (int i = lg - 1; i >= 0 && id != -1; i--)
            if (q[i][id].first != -1 && q[i][id].first <= sum)
                answer += (1 << i), sum -= q[i][id].first, id = q[i][id].second;
            printf("%I64d\n", answer);
        }
    }
}