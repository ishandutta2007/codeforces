#include <bits/stdc++.h>
using namespace std;
#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<vi> a(4);
    FOR (i, 0, n - 1) {
        string s; cin >> s; int x; cin >> x;
        int h = (s[0]-'0')*2+(s[1]-'0');
        a[h].push_back(x);
    }
    FOR (i, 0, 3) {
        sort(all(a[i]));
    }
    int ans = accumulate(all(a[3]), 0);
    int mn = min(sz(a[1]), sz(a[2]));
    while (mn--) {
        ans += a[1].back()+a[2].back();
        a[1].pop_back();
        a[2].pop_back();
    }
    // int num = sz(a[3]), cost = sz(a[3]);
    int k = 1;
    if (a[1].empty()) {
        k = 2;
    }
    int num = min(sz(a[3]), sz(a[0])+sz(a[k]));
    
    reverse(all(a[0])), reverse(all(a[k]));

    if (sz(a[k]) > num) a[k].resize(num);
    if (sz(a[0]) > num) a[0].resize(num);
    int nans = ans + accumulate(all(a[k]), 0);
    
    int x = 0, y = accumulate(all(a[k]), 0);

    FOR (i, 0, sz(a[0])-1) {
        x += a[0][i];
        if (num - (i + 1) < sz(a[k])) y -= a[k][num - (i + 1)];

        int h = (i + 1), t = min(sz(a[k]), num - h);
        if (sz(a[3]) - h + t >= 0)
            nans = max(nans, ans + x + y);
    }
    
    cout << nans;
    
    return 0;
}