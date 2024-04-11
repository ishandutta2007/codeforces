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

const int maxn = 3e5 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 300, mod = 1e9 + 993, LG = 17;

int n, m;

vector<int> e[maxn];

unordered_set<ll> mp;

bool ex(int x, int y){
    if (x > y)
        swap(x, y);
    return mp.find(x * (ll)1000000000 + y) != mp.end();
}

bool vis[maxn];

queue<int> que;

int dst[maxn];

int par[maxn];

vector<int> ans;

void upd(vector<int> ups){
    if (ans.empty() || ups.size() < ans.size())
        swap(ans, ups);
}

int p[maxn];

int get(int x){
    return x == p[x] ? x : p[x] = get(p[x]);
}

void uni(int x, int y){
    x = get(x);
    y = get(y);
    p[x] = y;
}

vector<int> g[maxn];

vector<int> we;

bool dfs(int v, int fin){
    vis[v] = 1;
    if (v == fin){
        we.push_back(v);
        return 1;
    }
    for (int i : e[v])
    if (!vis[i] && dfs(i, fin)){
        we.push_back(v);
        return 1;
    }
    return 0;
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
    cin >> n >> m;
    mp.reserve(8000000);
    for (int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        if (v > u)
            swap(v, u);
        mp.insert(v * (ll)1000000000 + u);
        e[v].push_back(u);
        e[u].push_back(v);
    }
    for (int i = 1; i < n; i++)
        dst[i] = -1;
    que.push(0);
    while (!que.empty()){
        int v = que.front();
        que.pop();
        for (int i : e[v])
        if (dst[i] == -1)
            dst[i] = dst[v] + 1,
            par[i] = v,
            que.push(i);
    }
    if (dst[n - 1] != -1){
        vector<int> pth;
        int v = n - 1;
        pth.push_back(v);
        while (v > 0){
            v = par[v];
            pth.push_back(v);
        }
        reverse(pth.begin(), pth.end());
        upd(pth);
    }
    if (!ans.empty() && ans.size() < 5){
        cout << ans.size() - 1 << '\n';
        for (int i : ans)
            cout << i + 1 << ' ';
        return 0;
    }
    for (int i : e[0])
        vis[i] = 1;
    for (int i : e[0])
        for (int j : e[i])
        if (j != 0 && !vis[j]){
            cout << 4 << '\n' << 1 << ' ' << i + 1 << ' ' << j + 1 << ' ' << 1 << ' ' << n << '\n';
            return 0;
        }
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i : e[0])
        for (int j : e[i])
        if (j != 0)
            uni(i, j);
    for (int i : e[0])
        g[get(i)].push_back(i);
    for (int i = 0; i < n; i++)
        vis[i] = 0;
    vis[0] = 1;
    for (int i : e[0]){
        for (int x : g[i])
            for (int y : g[i])
            if (x != y && !ex(x, y)){
                dfs(x, y);
                for (int len = 2; ; len++)
                    for (int j = 0; j + len < we.size(); j++)
                    if (!ex(we[j], we[j + len])){
                        cout << 5 << '\n' << 1 << ' ' << we[j] + 1 << ' ' << we[j + len - 1] + 1 << ' ' << we[j + len] + 1 << ' ' << we[j] + 1 << ' ' << n;
                        return 0;
                    }
            }
    }
    if (ans.empty())
        cout << -1 << '\n';
    else{
        cout << ans.size() - 1 << '\n';
        for (int i : ans)
            cout << i + 1 << ' ';
    }
}