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

    string s; cin >> s;
    vi f(26);
    for (char ch: s) {
        f[ch - 'a']++;
    }
    int m; cin >> m;
    
    vi ss(sz(s), (1 << 6) - 1);

    vi N(64);
    vi S(64);
    while (m--) {
        int idx; string t; cin >> idx >> t; --idx;
        int mask = 0; for (char ch: t) mask |= (1 << (ch - 'a'));
        ss[idx] = mask;
    }
    FOR (i, 0, sz(s) - 1) FOR (b, 1, 63) if (b & ss[i]) N[b]++;
        
    string t;
    
    FOR (i, 0, sz(s) - 1) {
        FOR (b, 1, 63) if ((b & ss[i])) N[b]--;

        FOR (j, 0, 5) if (f[j] and (ss[i] & (1 << j))) {
            char ch = 'a' + j;
            f[ch - 'a']--;
            bool bc = 0;
            FOR (mask, 1, 63) {
                S[mask] = S[mask & (mask - 1)] + f[__builtin_ctz(mask)];
                if (N[mask] < S[mask]) {
                    bc = 1;
                    break;
                }
            }
            if (!bc) {
                t += ch;
                break;
            }
            f[ch - 'a']++;
        }
        if (sz(t) != i + 1) {
            cout << "Impossible\n";
            return 0;
        }
    }
    cout << t;
    
    return 0;
}