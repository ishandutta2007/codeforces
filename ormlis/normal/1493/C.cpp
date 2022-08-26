#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 2e5 + 1;
const int md = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26);
    int need = 0;
    if (n % k) {
        cout << "-1\n";
        return;
    }
    set<int> t;
    for (auto &c : s) {
        cnt[c - 'a']++;
    }
    range(i, 26) {
        if (cnt[i] % k) {
            int w = k - (cnt[i] % k);
            need += w;
            t.insert(i);
        }
    }
    if (need == 0) {
        cout << s << '\n';
        return;
    }
    for (int i = n - 1; i >= 0; --i) {
        int x = s[i] - 'a';
        if (cnt[x] % k) {
            int w = k - (cnt[x] % k);
            need -= w;
            t.erase(x);
        }
        cnt[x]--;
        if (cnt[x] % k) {
            int w = k - (cnt[x] % k);
            need += w;
            t.insert(x);
        }
        if (x == 25) continue;
        if (need + i == n && t.upper_bound(x) != t.end()) {
            int w = *t.upper_bound(x);
            s[i] = w + 'a';
            cnt[w]++;
            w = 0;
            for(int j = i + 1; j < n; ++j) {
                while(cnt[w] % k == 0) w++;
                cnt[w]++;
                s[j] = w + 'a';
            }
            cout << s << '\n';
            return;
        }
        if (need + i < n) {
            s[i] = x + 1 + 'a';
            cnt[x + 1]++;
            int w = 25;
            for(int j = n - 1; j > i; --j) {
                while(w > 0 && cnt[w] % k == 0) w--;
                cnt[w]++;
                s[j] = w + 'a';
            }
            cout << s << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}