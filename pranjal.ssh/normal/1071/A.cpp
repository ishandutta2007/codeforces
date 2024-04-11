#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    ll a, b; cin >> a >> b;
    ll x = a + b;
    ll st = 0, en = 1e5;
    while (st < en) {
        ll mid = (st + en + 1) / 2;
        ll y = mid*(mid+1)/2;
        if (y <= x) st = mid;
        else en = mid - 1;
    }
    set<ll> d1, d2;
    NFOR (i, st, 1) {
        if (i > a) {
            d2.insert(i);
        } else {
            a -= i;
            d1.insert(i);
        }
    }
    for (auto d: {d1, d2}) {
        cout << sz(d) << "\n";
        for (auto i: d) cout << i << " ";
        if (sz(d)) cout << "\n";
    }

    
    return 0;
}