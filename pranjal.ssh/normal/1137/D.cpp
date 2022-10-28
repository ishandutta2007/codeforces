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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    
    while (1) {
        cout << "next 0 1" << endl; int k; cin >> k; vector<string> a(k); FOR (i, 0, k-1) cin >> a[i];
        cout << "next 1" << endl;

        cin >> k; a.resize(k); FOR (i, 0, k-1) cin >> a[i];
        bool done = 0;
        for (auto it: a) {
            if (count(all(it), '0') and count(all(it), '1')) {
                done = 1;
            }
        }
        if (done) break;
    }

    while (1) {
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        int k; cin >> k;
        vector<string> a(k); FOR (i, 0, k-1) cin >> a[i];
        if (k == 1) {
            cout << "done" << endl;
            return 0;
        }
    }

    
    return 0;
}