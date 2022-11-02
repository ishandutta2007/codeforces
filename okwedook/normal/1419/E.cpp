#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <complex>
#include <random>
#include <cassert>
#include <chrono>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

#ifdef DEBUG
    template<class T> T to_dbg(T x) { return x; }
    template<class T, class U> string to_dbg(pair<T, U> p) {
        stringstream ss;
        ss << '{' << p.f << ',' << p.s << '}';
        return ss.str();
    }
    string to_dbg(string s) { return "\"" + s + "\""; }
    template<class It> string to_dbg(It begin, It end, string d = "") {
        stringstream ss;
        ss << '{';
        if (begin != end) ss << to_dbg(*begin++);
        while (begin != end)
            ss << "," << d << to_dbg(*begin++);
        ss << '}';
        return ss.str();
    }
    template<class T> string to_dbg(vector<T> a) { return to_dbg(all(a)); }
    template<class T> string to_dbg(set<T> a) { return to_dbg(all(a)); }
    template<class T> string to_dbg(hashset<T> a) { return to_dbg(all(a)); }
    template<class T, class U> string to_dbg(map<T, U> a) { return to_dbg(all(a), "\n"); }
    template<class T, class U> string to_dbg(hashmap<T, U> a) { return to_dbg(all(a), "\n"); }
    template<class T> void dbgout(T x) { cout << to_dbg(x) << endl; }
    template<class T, class... U>
    void dbgout(T t, U... u) {
        cout << to_dbg(t) << ", ";
        dbgout(u...);
    }
    #define dbg(...) cout << "[" << #__VA_ARGS__ << "] = ", dbgout(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif

template<class T, class U> inline bool chmax(T &x, U y) { return x < y ? x = y, 1 : 0; }
template<class T, class U> inline bool chmin(T &x, U y) { return x > y ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }
void read() {} void print() {} void println() { cout << '\n'; }
template<class T, class ...U> void read(T &x, U& ... u) { cin >> x; read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { cout << x; print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { cout << x; println(u...); }

int mark(const vector<int> &v) {
    int ans = 0;
    for (int i = 0; i < sz(v); ++i)
        ans += (v[i] & v[(i + 1) % sz(v)]) == 0;
    return ans;
}

int getmask(const vector<int> &pr, int x) {
    int mask = 0;
    for (int bit = 0; bit < sz(pr); ++bit)
        if (x % pr[bit] == 0)
            mask |= 1 << bit;
    return mask;
}

vector<vector<int>> order = {
    {},
    {1},
    {1, 2, 3},
    {7,1,3,2,6,5,4},
    {15,1,3,2,6,5,9,7,4,13,10,11,8,12,14},
    {31,1,3,2,6,5,17,9,7,25,18,10,19,21,13,11,14,4,12,20,29,27,26,23,22,15,8,24,16,28,30},
    {63,1,3,2,34,33,5,17,9,10,41,35,37,19,6,21,49,25,7,18,11,13,4,36,38,51,50,45,43,42,53,14,39,57,12,29,8,27,26,15,20,23,22,30,16,58,59,31,55,24,61,54,52,47,46,44,40,28,48,32,62,56,60},
    {127,1,3,2,66,65,5,33,17,9,10,73,25,97,49,13,7,6,69,67,81,35,41,37,11,34,19,18,21,4,85,99,70,101,57,15,53,12,68,71,74,82,98,83,75,77,113,51,14,50,89,105,29,22,20,45,23,26,8,43,27,38,39,36,42,114,109,115,86,24,84,87,117,102,52,90,107,103,76,121,91,100,72,93,30,28,106,44,46,47,55,16,31,54,79,61,40,58,59,78,118,119,48,80,116,122,32,125,123,111,110,56,63,88,108,92,60,104,62,94,95,126,64,124,96,120,112},
    {255,1,3,2,130,129,65,33,17,9,5,35,10,137,81,13,6,133,161,41,34,131,69,37,11,49,145,193,66,97,67,73,7,4,21,19,18,25,99,15,209,177,146,135,89,101,134,85,132,141,77,82,105,71,98,83,149,194,201,195,138,162,14,8,45,74,70,75,169,23,197,139,147,153,163,113,225,165,36,57,50,26,12,68,39,20,29,27,38,43,22,51,53,42,136,150,148,155,28,24,233,211,30,181,140,151,166,185,87,227,47,164,173,199,154,226,143,72,196,52,217,205,157,61,142,229,40,114,241,84,31,86,178,179,44,213,46,198,202,203,210,171,170,167,76,59,16,121,54,100,117,109,106,103,102,55,90,79,115,107,93,58,91,78,62,200,245,180,189,60,63,249,237,32,235,214,95,242,88,182,80,243,212,230,228,231,187,218,204,56,186,207,206,215,48,219,234,92,221,111,94,108,104,110,118,159,123,116,168,144,125,122,158,152,156,119,175,183,174,172,251,246,253,250,232,247,124,64,238,127,236,239,126,244,222,223,112,188,216,120,160,96,176,191,190,184,208,220,254,252,240,192,128,248,224},
    {511,1,3,2,258,257,129,65,33,17,9,5,193,259,66,321,385,145,137,73,69,261,37,41,49,7,289,67,6,133,11,10,265,131,81,161,273,97,13,4,21,35,130,34,19,18,25,163,147,134,14,293,417,389,153,141,297,135,194,139,169,162,138,146,99,27,291,266,22,12,132,165,177,325,195,329,281,337,105,323,197,113,290,305,386,269,201,149,449,39,260,267,15,209,322,101,393,263,274,277,275,353,387,262,98,89,401,225,82,50,83,42,8,74,29,20,85,77,23,57,51,26,71,68,70,38,36,45,75,53,43,271,433,421,213,361,268,171,453,205,44,276,345,425,279,278,292,285,264,313,270,210,226,419,217,229,357,282,227,409,211,59,369,481,203,79,47,46,457,233,294,354,324,451,450,199,28,185,58,202,283,465,241,198,402,394,339,331,333,388,55,40,181,295,309,390,61,54,395,330,30,338,52,84,31,76,326,391,397,403,405,306,155,418,355,307,327,341,298,299,301,154,173,90,196,100,109,167,143,78,170,150,16,179,91,72,136,166,157,93,103,142,87,24,178,114,106,107,86,102,148,121,151,115,164,117,140,459,398,489,334,485,370,441,454,347,467,328,411,473,104,32,356,317,455,466,349,332,340,272,437,88,371,452,335,461,458,359,410,362,95,399,407,396,422,346,365,358,363,469,343,406,111,48,303,308,497,92,420,423,482,435,483,373,80,310,108,314,200,118,212,404,426,94,429,144,315,413,377,427,392,180,311,434,110,56,62,342,204,123,152,302,60,122,63,214,172,249,187,219,168,116,215,218,221,156,207,237,158,206,159,182,280,242,183,119,125,228,174,284,234,189,235,186,286,175,230,287,231,296,243,245,300,490,239,424,498,445,474,312,505,316,190,493,438,336,491,160,470,443,460,208,428,462,439,436,112,127,232,468,442,222,463,414,246,176,318,236,430,456,431,499,244,487,501,477,250,223,471,124,475,120,484,184,486,238,126,188,304,288,251,96,319,247,344,64,372,220,381,366,216,415,379,350,191,378,375,408,374,351,367,364,360,348,253,400,412,495,380,494,320,488,509,252,255,503,432,416,192,506,254,248,507,500,376,240,502,492,368,224,128,440,382,352,479,447,464,383,444,446,472,476,478,510,508,480,448,384,504,256,496}
};

void solve() {
    int n;
    read(n);
    vector<int> pr;
    int x = n;
    for (int d = 2; d * d <= n; ++d)
        if (x % d == 0) {
            pr.pb(d);
            while (x % d == 0) x /= d;
        }
    if (x > 1) pr.pb(x);
    set<int> del;
    for (int i = 1; i * i <= n; ++i)
        if (n % i == 0) {
            del.insert(i);
            del.insert(n / i);
        }
    del.erase(1);
    vector<vector<int>> bymask(1 << sz(pr));
    for (auto i : del)
        bymask[getmask(pr, i)].pb(i);
    if (sz(pr) == 2) {
        vector<int> ans;
        if (sz(bymask[3]) > 1) {
            for (auto i : bymask[1]) ans.pb(i);
            ans.pb(bymask[3][0]);
            for (auto i : bymask[2]) ans.pb(i);
            for (int i = 1; i < sz(bymask[3]); ++i)
                ans.pb(bymask[3][i]);
            for (auto i : ans) print(i, ' ');
            println();
            println(0);
            return;
        } else {
            for (int i = 1; i <= 3; ++i)
                for (auto j : bymask[i]) print(j, ' ');
            println();
            println(1);
            return;
        }
    }
    for (auto i : order[sz(pr)])
        for (auto j : bymask[i]) print(j, ' ');
    println();
    println(0);
}

signed main() {
    FAST; FIXED;
    int t;
    read(t);
    while (t--) solve();
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}