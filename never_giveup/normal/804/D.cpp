/*

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

using namespace std;

typedef long long ll;

typedef long double ld;

void setmax(int &x, int y){
    x = max(x, y);
}

void setmin(int &x, int y){
    x = max(x, y);
}

void setmax(ll &x, ll y){
    x = max(x, y);
}

void setmin(ll &x, ll y){
    x = max(x, y);
}

ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MOD = 1e9 + 993;

const int mod = 1e9 + 7;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MOD;
    XR = YR;
    YR = ZR;
    return ZR;
}

string prm(string s){
    string t;
    for (int i = 1; i < s.length(); i++)
        t.push_back(s[i]);
    t.push_back(s[0]);
    return t;
}

ll bpow(ll x, ll y){
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    ll ret = bpow(x, y >> 1);
    ret = (ret * ret) % mod;
    if (y & 1)
        ret = (ret * x) % mod;
    return ret;
}

ll bdiv(ll x, ll y){
    return (x * bpow(y, mod - 2)) % mod;
}

int md(int x){
    if (x >= mod)
        x -= mod;
    if (x < 0)
        x += mod;
    return x;
}

ll MD(ll x){
    x %= MOD;
    if (x < 0)
        x += MOD;
    return x;
}

ll sqr(ll x){
    return x * x;
}

const ll llinf = 2e18;

const ld EPS = 1e-9;

const int maxn = 1e5 + 100, inf = 1e9 + 100, sq = 1000;

int n, m, zap;

vector<vector<int> > comp;

vector<int> diam;

bool vis[maxn];

ll q[maxn];

ll d[maxn];

vector<int> e[maxn];

int id[maxn];

void prec(int v){
    comp.back().push_back(v);
    id[v] = comp.size() - 1;
    vis[v] = 1;
    for (int i = 0; i < e[v].size(); i++)
        if (!vis[e[v][i]])
            prec(e[v][i]);
}

void getdist(int v, int par){
    for (int i = 0; i < e[v].size(); i++)
        if (e[v][i] != par)
            d[e[v][i]] = d[v] + 1, getdist(e[v][i], v);
}

int siz;

pair<ll, int> mas[maxn];

int big[maxn];

int bsz;

ll pt[maxn / sq][maxn];

ll cnt[maxn];

int p[maxn];

ll sum[maxn];

bool cmp(int x, int y){
    return q[x] < q[y];
}

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #else
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    //freopen("trap.in", "r", stdin);
    //freopen("trap.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> m >> zap;
    for (int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
    if (!vis[i]){
        comp.push_back({});
        prec(i);
        int x, y;
        int mx, ix;
        d[i] = 0;
        getdist(i, -1);
        mx = 0, ix = i;
        for (int i = 0; i < comp.back().size(); i++)
            if (d[comp.back()[i]] > mx)
                mx = d[comp.back()[i]], ix = comp.back()[i];
        x = ix;
        d[x] = 0;
        getdist(x, -1);
        mx = 0, ix = x;
        for (int i = 0; i < comp.back().size(); i++){
            if (d[comp.back()[i]] > mx)
                mx = d[comp.back()[i]], ix = comp.back()[i];
            q[comp.back()[i]] = d[comp.back()[i]];
        }
        y = ix;
        diam.push_back(mx);
        d[y] = 0;
        getdist(y, -1);
        for (int i = 0; i < comp.back().size(); i++)
            q[comp.back()[i]] = max(q[comp.back()[i]], d[comp.back()[i]]);
        sort(comp.back().begin(), comp.back().end(), cmp);
    }
    for (int i = 0; i < n; i++)
        mas[i] = make_pair(q[i], i);
    sort(mas, mas + n);
    siz = comp.size();
    for (int i = 0; i < siz; i++)
    if (comp[i].size() > sq){
        big[i] = bsz;
        bsz++;
        for (int j = 0; j < siz; j++)
            p[j] = comp[i].size(), sum[j] = 0, cnt[j] = 0;
        for (int j = 0; j < n; j++){
            int it = id[mas[j].second];
            if (it == i)
                continue;
            while (p[it] > 0 && q[comp[i][p[it] - 1]] + mas[j].first + 1 >= max(diam[it], diam[i]))
                p[it]--, sum[it] += q[comp[i][p[it]]];
            pt[bsz - 1][it] += sum[it] + (mas[j].first + 1) * (comp[i].size() - p[it]), cnt[it] += (ll)p[it];
        }
        for (int j = 0; j < siz; j++)
            pt[bsz - 1][j] += cnt[j] * max(diam[i], diam[j]);
    }
    else
        big[i] = -1;
    cout << fixed << setprecision(20);
    for (int iter = 0; iter < zap; iter++){
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        v = id[v], u = id[u];
        if (v == u){
            cout << -1 << '\n';
            continue;
        }
        if (comp[v].size() < comp[u].size())
            swap(v, u);
        ll answer = 0;
        if (big[v] != -1)
            answer = pt[big[v]][u];
        else{
            int it = comp[u].size();
            ll now = 0, cnow = 0;
            for (int i = 0; i < comp[v].size(); i++){
                while (it > 0 && q[comp[u][it - 1]] + q[comp[v][i]] + 1 >= max(diam[v], diam[u]))
                    it--, now += q[comp[u][it]];
                answer += now + (q[comp[v][i]] + 1) * (comp[u].size() - it), cnow += it;
            }
            answer += cnow * max(diam[v], diam[u]);
        }
        cout << answer / (ld)(comp[v].size() * comp[u].size()) << '\n';
    }
}