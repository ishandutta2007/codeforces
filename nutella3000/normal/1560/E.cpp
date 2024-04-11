#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
#define ull unsigned long long
mt19937 rnd;
 
const int inf = 1e15 + 3;
const int max_n = 1e5 + 3;

bool check(string q, string alp, string s) {
    vector<bool> ban(26);
    int v = 0;
    for (int i = 0; i < size(alp); ++i) {
        int id = 0;
        while (true) {
            while (id < size(q) && ban[q[id] - 'a']) ++id;
            if (id == size(q)) break;
            if (v == size(s) || q[id] != s[v]) return false;
            ++id, ++v;
        }
        ban[alp[i] - 'a'] = true;
    }
    return v == size(s);
}

void run() {
    string s;
    cin >> s;
    int n = size(s);
    vector<int> cnt(26);
    string alp;
    for (int i = n - 1; i >= 0; --i) {
        if (!cnt[s[i] - 'a']) alp += s[i];
        ++cnt[s[i] - 'a'];
    }
    for (int i = 0; i < size(alp); ++i) {
        cnt[alp[i] - 'a'] /= (size(alp) - i);
    }
    string q;
    for (int i = 0; i < n; ++i) {
        if (!cnt[s[i] - 'a']) break;
        --cnt[s[i] - 'a'];
        q += s[i];
    }
    reverse(all(alp));
    //cout << q << " " << alp << endl;
    if (!check(q, alp, s)) cout << -1 << endl;
    else {
        cout << q << " " << alp << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);
 
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}