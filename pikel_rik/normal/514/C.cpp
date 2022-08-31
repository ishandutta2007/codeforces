#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const ll mod = 1e18 + 7;
const int inf = 2e9 + 5;

const int N = 3e5 + 5;
const int p = 4;

ll h(const string &s) {
    ll val = 0, p_val = 1;

    for (char i : s) {
        val = (val + (i - 'a' + 1) * p_val) % mod;
        p_val = (p_val * p) % mod;
    }
    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<ll> set;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        set.insert(h(s));
    }

    while (m--) {
        string s;
        cin >> s;

        bool ans = false;
        ll val = h(s), p_val = 1;

        for (int i = 0; i < s.length(); i++) {
            for (char j = 'a'; j <= 'c'; j++) {
                if (j != s[i] and set.count((val + p_val * (j - s[i]) + mod + mod) % mod))
                    ans = true;
            }

            if (ans) break;
            p_val = (p_val * p) % mod;
        }

        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}