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

typedef unsigned long long ull;

typedef long double ld;

ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MOD = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MOD;
    XR = YR;
    YR = ZR;
    return ZR;
}

ll sqr(ll x){
    return x * x;
}

int md(int x, int mymod){
    if (x >= mymod)
        x -= mymod;
    if (x < 0)
        x += mymod;
    return x;
}

vector<int> sufarray(string &s){
    s.push_back('$');
    int n = s.length(), sum;
    vector<int> mas(n), buck(max(n, 256)), col(n), buf(n);
    for (int i = 0; i < n; i++)
        col[i] = s[i];
    fill(buck.begin(), buck.end(), 0);
    sum = 0;
    for (int i = 0; i < n; i++)
        buck[col[i]]++;
    for (int i = 0; i < buck.size(); i++)
        sum += buck[i], buck[i] = sum - buck[i];
    for (int i = 0; i < n; i++)
        mas[buck[col[i]]++] = i;
    col[mas[0]] = 0;
    for (int i = 1; i < n; i++)
        if (s[mas[i]] == s[mas[i - 1]])
            col[mas[i]] = col[mas[i - 1]];
        else
            col[mas[i]] = col[mas[i - 1]] + 1;
    for (int len = 1; len < n; len <<= 1){
        fill(buck.begin(), buck.end(), 0);
        sum = 0;
        for (int i = 0; i < n; i++)
            buck[col[i]]++;
        for (int i = 0; i < n; i++)
            sum += buck[i], buck[i] = sum - buck[i];
        for (int i = 0; i < n; i++)
            buf[buck[col[md(mas[i] - len, n)]]++] = md(mas[i] - len, n);
        mas = buf;
        buf[mas[0]] = 0;
        for (int i = 1; i < n; i++)
            if (col[mas[i]] == col[mas[i - 1]] && col[md(mas[i] + len, n)] == col[md(mas[i - 1] + len, n)])
                buf[mas[i]] = buf[mas[i - 1]];
            else
                buf[mas[i]] = buf[mas[i - 1]] + 1;
        col = buf;
    }
    s.pop_back();
    for (int i = 0; i < n; i++)
        if (mas[i] == n - 1){
            mas.erase(mas.begin() + i);
            break;
        }
    return mas;
}

vector<int> lcpsufarray(vector<int> &sufmas, string &s){
    int n = s.length();
    vector<int> obr(n), mas(n);
    for (int i = 0; i < n; i++)
        obr[sufmas[i]] = i;
    int k = 0;
    for (int i = 0; i < n; i++)
        if (obr[i] == n - 1)
            mas[n - 1] = -1;
        else{
            while (max(i + k, sufmas[obr[i] + 1] + k) < n && s[i + k] == s[sufmas[obr[i] + 1] + k])
                k++;
            mas[obr[i]] = k;
            if (k > 0)
                k--;
        }
    return mas;
}

int gcd(int x, int y){
    if (x == 0 || y == 0)
        return max(1, max(x, y));
    return __gcd(x, y);
}

pair<int, int> compress(pair<int, int> x){
    if (x.second < 0)
        x.first *= -1, x.second *= -1;
    int g = gcd(abs(x.first), x.second);
    return make_pair(x.first / g, x.second / g);
}

pair<int, int> mkp(int x, int y){
    return make_pair(x, y);
}

int mystoi(string &s){
    int ret = 0;
    int vl = 1;
    if (s[0] == '-')
        vl = -1;
    for (int i = (vl == 1 ? 0 : 1); i < s.length(); i++)
        ret = ret * 10 + s[i] - 48;
    return ret * vl;
}

pair<int, int> operator +(pair<int, int> X, pair<int, int> Y){
    return compress(make_pair(X.first * Y.second + X.second * Y.first, X.second * Y.second));
}

pair<int, int> operator -(pair<int, int> X, pair<int, int> Y){
    return compress(make_pair(X.first * Y.second - X.second * Y.first, X.second * Y.second));
}

pair<int, int> operator *(pair<int, int> X, pair<int, int> Y){
    return compress(make_pair(X.first * Y.first, X.second * Y.second));
}

pair<int, int> operator /(pair<int, int> X, pair<int, int> Y){
    return compress(make_pair(X.first * Y.second, X.second * Y.first));
}

const ll llinf = 4e18 + 100;

const ld EPS = 1e-6;

const ld PI = atan2(0, -1);

const int maxn = 5e3 + 10, inf = 1e9 + 100, sq = 300, mod = 1e9 + 7;

int n, B;

vector<int> e[maxn];

int c[maxn], dc[maxn];

int q[maxn][2][maxn];

int sz[maxn];

int get(int x){
    if (x > B)
        return inf;
    return x;
}

void dfs(int v){
    vector<int> p[2];
    for (int i = 0; i < e[v].size(); i++){
        int to = e[v][i];
        dfs(to);
        p[0].resize(sz[v] + sz[to] + 1, inf);
        p[1].resize(sz[v] + sz[to] + 1, inf);
        for (int k1 = 0; k1 <= sz[v]; k1++)
        for (int k2 = 0; k2 <= sz[to]; k2++){
            p[0][k1 + k2] = min(p[0][k1 + k2], get(q[v][0][k1] + q[to][0][k2]));
            p[1][k1 + k2] = min(p[1][k1 + k2], min(p[0][k1 + k2], get(min(q[v][0][k1], q[v][1][k1]) + min(q[to][0][k2], q[to][1][k2]))));
        }
        sz[v] += sz[to];
        for (int j = 0; j <= sz[v]; j++)
            q[v][0][j] = p[0][j], q[v][1][j] = p[1][j];
    }
    sz[v]++;
    q[v][0][sz[v]] = inf;
    q[v][1][sz[v]] = inf;
    for (int i = sz[v]; i > 0; i--){
        q[v][0][i] = min(q[v][0][i], get(q[v][0][i - 1] + c[v]));
        q[v][1][i] = get(q[v][1][i - 1] + dc[v]);
    }
    q[v][1][0] = inf;
}

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #else
    //ifstream cin("common.in");
    //ofstream cout("common.out");
    //freopen("trap.in", "r", stdin);
    //freopen("trap.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> B;
    for (int i = 0; i < n; i++){
        int x, ce;
        cin >> c[i] >> x;
        dc[i] = c[i] - x;
        if (i > 0){
            cin >> ce;
            e[ce - 1].push_back(i);
        }
    }
    dfs(0);
    int answer = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 2; j++)
            if (q[0][j][i] <= B)
                answer = max(answer, i);
    cout << answer;
    /*cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k = 1;
    while (n > 2){
        for (int i = 0; i < n - 1; i++)
            b[i] = a[i] + k * a[i + 1], k *= -1;
        n--;
        for (int i = 0; i < n; i++)
            a[i] = b[i];
    }
    cout << a[0];
    */
}