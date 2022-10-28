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

ll W(int x1, int y1, int x2, int y2) {
    ll tot = (x2-x1+1)*1LL*(y2-y1+1);
    if (tot % 2 == 1 and (x1+y1) % 2 == 0) return tot / 2 + 1;
    return tot / 2;
}

ll B(int x1, int y1, int x2, int y2) {
    ll tot = (x2-x1+1)*1LL*(y2-y1+1);
    return tot - W(x1, y1, x2, y2);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4;
        ll w = W(1, 1, m, n) + B(x1, y1, x2, y2) - W(x3, y3, x4, y4);

        pair<ii, ii> ints(ii(max(x1, x3), max(y1, y3)), ii(min(x2, x4), min(y2, y4)));

        if (ints.S.F >= ints.F.F and ints.S.S >= ints.F.S) {
            w -= B(ints.F.F, ints.F.S, ints.S.F, ints.S.S);
        }

        cout << w << " " << n*1LL*m - w << "\n";
    }    
   
    return 0;
}