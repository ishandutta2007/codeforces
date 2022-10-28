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
inline int add(int x, int y, int mod = inf) {
    x += y;
    if (x >= mod) x -= mod;
    return x;
}
inline int mul(int x, int y, int mod = inf) {
    return (x * 1LL * y) % mod;
}
struct Hash // S[2...4] => 2*b^2 + 3*b + 4
{
    int base, mod;
    string s; int l;
    vi pp, hf;

    Hash(const string &s, int base = 101, int mod = 1000000009): base(base), mod(mod), s(s), l(s.length()), pp(l), hf(l)
    {
        pp[0] = 1;
        FOR(i, 1, l - 1)pp[i] = mul(pp[i - 1], base, mod);
        // rr = {19, 15, 12, 23, 4, 21, 3, 5, 2, 20, 6, 7, 16, 8, 25, 26, 11, 14, 1, 13, 18, 22, 24, 10, 17, 9};

        hf[0] = s[0] - 'a';
        FOR(i, 1, l - 1)hf[i] = add(mul(hf[i - 1], base, mod), s[i] - 'a', mod);

        // hr[l - 1] = rr[s[l - 1] - 'a'];
        // NFOR(i, l - 2, 0)hr[i] = add(mul(hr[i + 1], base, mod), rr[s[i] - 'a'], mod);
    }

    inline int get(int i, int j)
    {
        if (i == 0)return hf[j];
        return add(hf[j], mod - mul(hf[i - 1], pp[j - i + 1], mod), mod);
        // else if (i == l - 1) return hr[j];
        // else     return add(hr[j], mod - mul(hr[i + 1], pp[i - j + 1], mod), mod);

    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    string s, t; cin >> s >> t;
    Hash H(t);
    int z = count(all(s), '0'), o = sz(s) - z;
    int ans = 0;
    FOR (i, 1, sz(t) / z) if (sz(t) > i*z) {
        if ((sz(t) - i*z) % o == 0) {
            int j = (sz(t) - i*z) / o;
            int h[2] = {-1, -1};
            bool can = true;
            int pos = 0;
            FOR (k, 0, sz(s) - 1) {
                int c = s[k] - '0';
                if (h[c] == -1) {
                    h[c] = H.get(pos, pos + (c ? j : i) - 1);
                } else if (h[c] != H.get(pos, pos + (c ? j : i) - 1)) {
                    can = false;
                    break;
                }
                pos += c ? j : i;
            }
            if (i == j and h[0] == h[1]) can = false;
            ans += can;
        }
    }
    cout << ans << "\n";


    
    return 0;
}