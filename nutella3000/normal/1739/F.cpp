#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const int N = 5000 + 3, L = 12;

int trie[N][L], link[N], sz = 1;
int sum[N];

void add(list<char>& s, int cost) {
    int v = 1;
    for (char c : s) {
        if (!trie[v][c - 'a']) {
            trie[v][c - 'a'] = ++sz;
        }
        v = trie[v][c - 'a'];
    }
    sum[v] += cost;
}

void run() {
    fill(trie[0], trie[0] + L, 1);

    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        int c; string s; cin >> c >> s;

        bool good = true;
        list<char> norm = {s[0]};
        auto it = norm.begin();

        for (int j = 1; j < s.size(); ++j) {
            if ((it != norm.begin() && *((--it)++) == s[j]) || ((++it)-- != norm.end() && *((++it)--) != s[j])) {
                if (it == norm.begin()) {
                    norm.push_front(s[j]);
                }
                --it;
            } else {
                if ((++it)-- == norm.end()) {
                    norm.push_back(s[j]);
                }
                ++it;
            }
            if (*it != s[j]) good = false;
        }
        /*for (auto i : norm)
            cout << i;
        cout << '\n';*/
        if (good) {
            add(norm, c);
            norm.reverse();
            add(norm, c);
        }
    }
    queue<int> q({1});
    while (q.size()) {
        int u = q.front();
        q.pop();
        sum[u] += sum[link[u]];

        for (int c = 0; c < L; ++c) {
            if (trie[u][c]) {
                link[trie[u][c]] = trie[link[u]][c];
                q.push(trie[u][c]);
            } else {
                trie[u][c] = trie[link[u]][c];
            }
        }
    }

    vector dp(1 << L, vector(sz+1, -inf));
    dp[0][1] = 0;

    for (int mask = 0; mask < (1 << L); ++mask) {
        for (int pl = 1; pl <= sz; ++pl) {
            if (dp[mask][pl] < 0) {
                continue;
            }
            for (int to = 0; to < L; ++to) {
                if (mask >> to & 1) {
                    continue;
                }
                int nm = mask | 1 << to;
                chmax(dp[nm][trie[pl][to]], dp[mask][pl] + sum[trie[pl][to]]);
            }
        }
    }
    int m = (1 << L) - 1;
    int pl = max_element(all(dp[m])) - dp[m].begin();

    string res = "";
    while (m) {
        for (int i = 0; i < L; ++i) {
            if (~m >> i & 1) {
                continue;
            }
            int pm = m ^ 1 << i;
            for (int j = 1; j <= sz; ++j) {
                if (trie[j][i] == pl && dp[m][pl] == dp[pm][j] + sum[pl]) {
                    res += 'a' + i;
                    m = pm;
                    pl = j;
                    break;
                }
            }
        }
    }
    cout << res << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}