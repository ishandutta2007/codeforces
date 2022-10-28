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

#define d2(x,y) sqrt((x.F-y.F)*(x.F-y.F)+(x.S-y.S)*(x.S-y.S))
#define d1(x,y) (abs(x.F-y.F)+abs(x.S-y.S))
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    double a, b, c; cin >> a >> b >> c;
    pair<double, double> A, B;
    cin >> A.F >> A.S; cin >> B.F >> B.S;
    vector<pair<double, double>> X, Y;
    if (b != 0) X.emplace_back(A.F, (-c-A.F*a)/b);
    if (b != 0) Y.emplace_back(B.F, (-c-B.F*a)/b);

    if (a != 0) X.emplace_back((-c-A.S*b)/a, A.S);
    if (a != 0) Y.emplace_back((-c-B.S*b)/a, B.S);

    double ans = d1(A, B);

    for (auto it1: X) for (auto it2: Y) {
        ans = min(ans, d1(A, it1) + d2(it1, it2) + d1(it2, B));
    }
    cout << fixed << setprecision(10) << ans << "\n";
    
    return 0;
}