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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    priority_queue<int, vector<int>, greater<>> q;

    int n;
    cin >> n;

    vector<pair<string, int>> op(n);
    for (int i = 0; i < n; i++) {
        cin >> op[i].first;
        if (op[i].first != "removeMin")
            cin >> op[i].second;
    }

    string s;
    int num;

    vector<pair<string, int>> ans;

    for (int i = 0; i < n; i++) {
        s = op[i].first;
        num = op[i].second;

        if (s == "insert") {
            ans.emplace_back(s, num);
            q.push(num);
        }
        else if (s == "getMin") {
            while (!q.empty() and q.top() < num) {
                q.pop();
                ans.emplace_back("removeMin", 0);
            }
            if (q.empty() or q.top() != num) {
                ans.emplace_back("insert", num);
                q.push(num);
            }
            ans.emplace_back(s, num);
        }
        else {
            if (q.empty()) {
                ans.emplace_back("insert", 0);
                q.push(0);
            }
            ans.emplace_back(s, 0);
            q.pop();
        }
    }

    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p.first << " ";
        if (p.first != "removeMin") cout << p.second;
        cout << "\n";
    }
    return 0;
}