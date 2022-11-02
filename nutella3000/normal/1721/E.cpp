#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const ll infL = 1e18 + 7;
const int N = 1e6 + 15;

int z[N];
int nxt[N][26];

void run() {
    string s; int n, q; cin >> s >> q;
    n = size(s);

    for (int i = 1; i < n; ++i) {
        z[i] = nxt[i-1][s[i] - 'a']+1;
        if (s[i] != s[z[i]-1]) --z[i];

        for (int j = 0; j < 26; ++j)
            nxt[i][j] = nxt[max(0, z[i]-1)][j];
        nxt[i][s[z[i]] - 'a'] = z[i];
    }

    for (int it = 0; it < q; ++it) {
        string t; cin >> t; s += t;

        for (int i = n; i < size(s); ++i) {
            z[i] = nxt[i-1][s[i] - 'a']+1;
            if (s[i] != s[z[i]-1]) --z[i];

            for (int j = 0; j < 26; ++j)
                nxt[i][j] = nxt[max(0, z[i]-1)][j];
            nxt[i][s[z[i]] - 'a'] = z[i];

            cout << z[i] << " ";
        }
        cout << '\n';
        while (size(s) != n)
            s.pop_back();
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}