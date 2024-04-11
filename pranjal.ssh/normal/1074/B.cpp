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

    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<vi> g(n + 1);
        vi p(n + 1);
        FOR (i, 1, n - 1) {
            int x, y; cin >> x >> y;
            g[x].push_back(y), g[y].push_back(x);
        }
        vi c1, c2, col1(n + 1), col2(n + 1);
        int k1; cin >> k1; while (k1--) {
            int x; cin >> x; c1.push_back(x);
            col1[x] = 1;
        }
        int k2; cin >> k2; while (k2--) {
            int x; cin >> x; c2.push_back(x);
            col2[x] = 1;
        }
        cout << "B " << c2[0] << endl;
        int r; cin >> r;
        stack<int> s;
        s.push(r);
        int r2 = 0;
        while (!s.empty()) {
            int x = s.top();
            s.pop();
            if (col1[x]) {
                r2 = x;
                break;
            }
            for (int y: g[x]) if (y != p[x]) {
                p[y] = x;
                s.push(y);
            }
        }
        assert(r2);
        cout << "A " << r2 << endl;
        cin >> r;
        if (col2[r]) {
            cout << "C " << r2 << endl;
        } else {
            cout << "C " << -1 << endl;
        }
    }   
    
    return 0;
}