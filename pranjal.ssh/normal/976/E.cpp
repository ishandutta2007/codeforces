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

    int n, a, b; cin >> n >> a >> b;
    b = min(b, n);
    vector<ii> A(n); FOR (i, 0, n - 1) cin >> A[i].F >> A[i].S;

    sort(all(A), [](ii x, ii y) {
        return x.F - x.S > y.F - y.S;
    });

    ll sum = 0;
    FOR (i, 0, n - 1) {
        if (i < b) {
            sum += max(A[i].F, A[i].S);
        }
        else sum += A[i].S;
    }
    ll ans = sum;
    FOR (i, 0, n - 1) {
        if (i < b) {
            ll cur = sum - max(A[i].S, A[i].F) + (A[i].F * (1LL << a));
            ans = max(ans, cur);
        } else if (b) {
            ll cur = sum - A[i].S + (A[i].F * (1LL << a));
            cur += A[b-1].S - max(A[b-1].S, A[b-1].F);
            ans = max(ans, cur);
        }
    }
    cout << ans;
    
    return 0;
}