#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, cnt[N];
set<int> s[N];

vector<int> ans;
bool visited[N];

bool solve() {
    while (ans.size() != n) {
        int u = ans[ans.size() - 1], v = ans[ans.size() - 2];

        for (int i : s[u]) {
            if (!visited[i] and s[i].find(v) != s[i].end()) {
                ans.push_back(i);
                visited[i] = true;
                break;
            }
        }

        if (ans.back() == u) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < 2*n; i++) {
        int a, b; cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
        s[a].insert(b);
        s[b].insert(a);
    }

    for (int i = 1; i <= n; i++) {
        if (cnt[i] != 4) {
            cout << "-1\n";
            return 0;
        }
    }


    for (int i : s[1]) {
        for (int j : s[1]) {
            if (i != j and s[i].find(j) != s[i].end()) {
                fill(visited, visited + n + 1, false);
                ans.clear();

                ans.push_back(1);
                ans.push_back(i);
                ans.push_back(j);

                visited[i] = visited[1] = visited[j] = true;
                if (solve()) {
                    for (int x : ans) cout << x << " ";
                    return 0;
                }
            }
        }
    }

    cout << "-1\n";
    return 0;
}