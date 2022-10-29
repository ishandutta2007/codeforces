#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

ll dp[11][60][1024];

ll f(int b, ll x) {
    if (x == 0) return 0;
    string s;
    while (x) s += '0' + (x % b), x /= b;
    reverse(all(s));
    int mask = 0;
    ll ans = 0;
    FOR (pos, 0, sz(s) - 1) {
        int len = sz(s) - pos - 1;
        FOR (mkc, pos ? 0 : 1, s[pos] - '0' - 1) {
            ans += dp[b][len][mask ^ (1 << mkc)];
        }
        if (pos > 0) {
            FOR (mkc, 1, b - 1) {
                ans += dp[b][len][1 << mkc];
            }
        }
        mask ^= (1 << (s[pos] - '0'));
    }
    return ans + dp[b][0][mask];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    FOR (b, 2, 10) {
        dp[b][0][0] = 1;
        FOR (len, 1, 59) {
            FOR (mask, 0, 1023) {
                FOR (d, 0, b - 1) {
                    dp[b][len][mask] += dp[b][len - 1][mask ^ (1 << d)];
                }
            }
        }
    }

    int q; cin >> q; while (q--) {
        int b; cin >> b;
        ll l, r; cin >> l >> r;
        cout << f(b, r) - f(b, l - 1) << "\n";
    }

    return 0;
}