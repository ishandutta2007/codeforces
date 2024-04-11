#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    string s;
    cin >> s;
    sort(all(s));
    vector<int> cnt(26);
    for (auto &c : s) {
        cnt[c - 'a']++;
    }
    {
        int ch = -1;
        range(i, 26) {
            if (cnt[i] == 1) {
                ch = i;
                break;
            }
        }
        if (ch != -1) {
            char x = 'a' + ch;
            range(i, (int) s.size()) {
                if (s[i] == x) {
                    swap(s[i], s[0]);
                    break;
                }
            }
            assert(s[0] == x);
            if (s.size() != 1) {
                sort(s.begin() + 1, s.end());
            }
            cout << s << '\n';
            return;
        }
    }
    int n = s.size();
    int cc = 0;
    range(i, 26) {
        if (cnt[i]) cc++;
    }
    if (cc == 1) {
        cout << s << '\n';
        return;
    }
    int a = 0;
    while (cnt[a] == 0) a++;
    int b = a + 1;
    while (cnt[b] == 0) b++;
    int to = (n - 1) / 2;
    if (cnt[a] + cnt[b] == n && to > cnt[b]) {
        string t;
        t += 'a' + a;
        cnt[a]--;
        while (cnt[b]) {
            t += 'a' + b;
            cnt[b]--;
        }
        while (cnt[a]) {
            t += 'a' + a;
            cnt[a]--;
        }
        cout << t << '\n';
        return;
    }
    if (to <= n - cnt[a]) {
        cnt[a] -= 2;
        string t;
        t += 'a' + a;
        t += 'a' + a;
        for (int i = 2; i < n; ++i) {
            if ((i & 1) && cnt[a]) {
                cnt[a]--;
                t += 'a' + a;
            } else {
                while (cnt[b] == 0) b++;
                cnt[b]--;
                t += 'a' + b;
            }
        }
        cout << t << '\n';
        return;
    } else {
        int c = b + 1;
        while (cnt[c] == 0) c++;
        string t;
        t += 'a' + a;
        t += 'a' + b;
        cnt[a]--;
        cnt[b]--;
        while (cnt[a]) {
            t += 'a' + a;
            cnt[a]--;
        }
        cnt[c]--;
        t += 'a' + c;
        range(i, 26) {
            while (cnt[i]) {
                t += 'a' + i;
                cnt[i]--;
            }
        }
        cout << t << '\n';
        return;
    }
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