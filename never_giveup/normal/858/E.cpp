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
    ll ZR = (XR * AR + YR * BR + CR);
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

ll lcm(ll x, ll y){
    return x * y / gcd(x, y);
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

const ld EPS = 1e-9;

const ld PI = atan2(0, -1);

const int maxn = 2e5 + 100, inf = 1e9 + 100, sq = 300, mod = 1e9 + 7;

set<string> usedd;

bool used(string s){
    return usedd.find(s) != usedd.end();
}

string getrand(){
    string ret;
    for (int i = 0; i < 6; i++)
        ret.push_back('a' + rand() % 26);
    if (used(ret))
        return getrand();
    usedd.insert(ret);
    return ret;
}

int n;

int ex;

vector<string> a, b;

vector<int> bada, badb;

int q[maxn];

int vals[maxn], typ[maxn];

vector<int> ea, eb;

string itos(int x){
    string ret;
    while (x)
        ret.push_back(x % 10 + 48), x /= 10;
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<pair<string, string> > answer;

int main() {
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //ifstream cin("aplusb.in");
    //ofstream cout("aplusb.out");
    //freopen("trap.in", "r", stdin);
    //freopen("trap.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        int t;
        cin >> s >> t;
        typ[i] = t;
        if (t)
            ex++;
        bool ez = 1;
        for (int j = 0; j < s.size(); j++)
        if (!(s[j] >= '0' && s[j] <= '9')){
            ez = 0;
            break;
        }
        if (s[0] == '0')
            ez = 0;
        if (!ez){
            if (t)
                a.push_back(s);
            else
                b.push_back(s);
            continue;
        }
        int val = 0;
        for (int j = 0; j < s.size(); j++)
            val = val * 10 + s[j] - 48;
        if (val < 1 || val > n){
            if (t)
                a.push_back(s);
            else
                b.push_back(s);
            continue;
        }
        vals[i] = val;
        q[val] = 1;
    }
    for (int i = 0; i < n; i++)
    if (vals[i]){
        int val = vals[i];
        if (typ[i]){
            if (val > ex)
                bada.push_back(val);
        }
        else
            if (val <= ex)
                badb.push_back(val);
    }
    for (int i = 1; i <= ex; i++)
        if (q[i] == 0)
            ea.push_back(i);
    for (int i = ex + 1; i <= n; i++)
        if (q[i] == 0)
            eb.push_back(i);
    if (ea.empty() && eb.empty() && (!bada.empty() || !badb.empty())){
        string w = getrand();
        int val = bada[0];
        string p = itos(bada[0]);
        bada.erase(bada.begin());
        answer.push_back(make_pair(p, w));
        eb.push_back(val);
        q[val] = 0;
        a.push_back(w);
    }
    while (!bada.empty() && !badb.empty()){
        string x = itos(bada.back()), y = itos(badb.back());
        if (!ea.empty()){
            int id = ea.back();
            ea.pop_back();
            answer.push_back(make_pair(x, itos(id)));
            q[id] = 1;
            answer.push_back(make_pair(y, x));
            q[badb.back()] = 0;
            ea.push_back(badb.back());
        }
        else{
            int id = eb.back();
            eb.pop_back();
            answer.push_back(make_pair(y, itos(id)));
            q[id] = 1;
            answer.push_back(make_pair(x, y));
            q[bada.back()] = 0;
            eb.push_back(bada.back());
        }
        bada.pop_back();
        badb.pop_back();
    }
    for (auto i : bada)
        answer.push_back(make_pair(itos(i), itos(ea.back()))), ea.pop_back(), eb.push_back(i);
    for (auto i : badb)
        answer.push_back(make_pair(itos(i), itos(eb.back()))), eb.pop_back(), ea.push_back(i);
    for (auto i : a)
        answer.push_back(make_pair(i, itos(ea.back()))), ea.pop_back();
    for (auto i : b)
        answer.push_back(make_pair(i, itos(eb.back()))), eb.pop_back();
    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++)
        cout << "move " << answer[i].first << ' ' << answer[i].second << '\n';
}