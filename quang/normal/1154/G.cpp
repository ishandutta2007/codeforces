#include <bits/stdc++.h>

using namespace std;

const int N = 10000010;

int n;
int id[N];
vector<int> cnt[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        id[i] = u;
        if (cnt[u].size() < 2) cnt[u].push_back(i);
    }
    long long res = (1ll << 60);
    pair<int, int> ans;
    for (int i = 1; i < N; i++) {
        // if (i >= res) break;
        vector<int> a;
        for (int j = i; j < N; j += i) {
            for (int u : cnt[j]) {
                a.push_back(u);
                if (a.size() == 2) break;
            }
            if (a.size() == 2) break;
        }
        if (a.size() != 2) continue;
        long long foo = 1ll * id[a[0]] * id[a[1]] / i;
        if (foo < res) {
            res = foo;
            ans = {a[0], a[1]};
        }
    }
    if (ans.first > ans.second) swap(ans.first, ans.second);
    cout << ans.first << ' ' << ans.second << endl;
    return 0;
}