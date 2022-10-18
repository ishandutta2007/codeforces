//isaf27

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>
//#include <ext/rope>

using namespace std;
//using namespace __gnu_cxx;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define random srand(time(NULL))
#define rand_int abs((rand() << 15) | rand())
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-7;
const ld zero = 0;
const ll INF = 1e18;
const int COUT = 30;
const int prost = 239;
const ll prost64 = 239;
const int two = 2;
const int thr = 3;
const ll sr = 31;
const ll MOD = 1e9 + 7;
const int BIG = 1e9 + 1;
const int alf = 26;
const int MAX_N = 2 * 1e5 + 239;
const int MAX_M = 2 * 1e3 + 239;
const int MAX_T = (1 << 20);
const int B = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 19;
const int km = (1 << 18);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int bit_max = 32;
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

// Code starts here

struct Node
{
    map<char, Node*> go;
    bool term;
    int kol;

    Node()
    {
        go.clear();
        term = false;
        kol = 0;
    }
};

Node *root;

int add(string s)
{
    vector<Node*> way;
    Node *cur = root;
    way.push_back(root);
    bool nw = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (cur->go.find(s[i]) == cur->go.end())
        {
            Node *to = new Node();
            cur->go[s[i]] = to;
            cur = to;
            nw = true;
        }
        else
            cur = cur->go[s[i]];
        way.push_back(cur);
    }
    if (!nw)
    {
        if (cur->term)
        {
            if (cur->kol > 1) return -1;
            for (int i = (int)way.size() - 1; i >= 0; i--)
                if (way[i]->kol > 1)
                    return i + 1;
            if (root->kol == 1)
                return 1;
        }
        cur->term = 1;
        for (Node *d : way)
            d->kol++;
        return -1;
    }
    int id = -1;
    for (int i = (int)way.size() - 1; i >= 0; i--)
        if (way[i]->term)
        {
            id = i;
            break;
        }
    if (id == -1 || way[id]->kol > 1)
    {
        cur->term = 1;
        for (Node *d : way)
            d->kol++;
        return -1;
    }
    int tw = -1;
    for (int i = id - 1; i >= 0; i--)
        if (way[i]->kol > 1)
        {
            tw = i;
            break;
        }
    if (tw == -1)
    {
        cur->term = 1;
        for (Node *d : way)
            d->kol++;
        return ((int)s.size() - id + 1);
    }
    cur->term = 1;
    for (Node *d : way)
        d->kol++;
    return ((int)s.size() - id + 1 + tw);

}

int func(vector<string> v)
{
    int ans = 0;
    for (string s : v)
    {
        if (s.empty()) continue;
        int pref = add(s);
        if (pref == -1)
            ans += s.size();
        else if (pref == s.size())
            ans += s.size();
        else
            ans += pref + 1;
    }
    return ans;
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    vector<string> v;
    string s;
    while (getline(cin, s))
        v.push_back(s);
    s = "";
    for (int i = 0; i < (int)v.size(); i++)
        s += v[i] + '!';
    v.clear();
    string now = "";
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (is_down(s[i]))
        {
            now += s[i];
            continue;
        }
        v.push_back(now);
        ans++;
        now = "";
    }
    v.push_back(now);
    root = new Node();
    ans += func(v);
    cout << ans;
    return 0;
}