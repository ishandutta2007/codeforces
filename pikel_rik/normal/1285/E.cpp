#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, ans[N];
pair<int, int> a[N];
vector<int> mark[2*N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> temp;

        for (int i = 1; i <= n; i++) {
            cin >> a[i].first >> a[i].second;
            ans[i] = 0;
            temp.push_back(a[i].first);
            temp.push_back(a[i].second);
        }

        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        for (int i = 0; i < temp.size(); i++) {
            mark[i].clear();
        }

        for (int i = 1; i <= n; i++) {
            a[i].first = lower_bound(temp.begin(), temp.end(), a[i].first) - temp.begin();
            a[i].second = lower_bound(temp.begin(), temp.end(), a[i].second) - temp.begin();
            mark[a[i].first].push_back(i);
            mark[a[i].second].push_back(-i);
        }

        int cur = 0, open = 0;
        set<int> ids;

        for (int i = 0; i < temp.size(); i++) {
            sort(mark[i].begin(), mark[i].end(), greater<>());
            if (ids.size() == 1 and open) {
                if (!(mark[i].size() == 1 and mark[i][0] == -*ids.begin())) {
                    ans[*ids.begin()]++;
                }
                open = 0;
            }
            for (int x : mark[i]) {
                if (x < 0) {
                    ids.erase(-x);
                } else {
                    ids.insert(x);
                }
            }
            if (ids.size() == 1 and !(mark[i].size() == 1 and mark[i][0] == *ids.begin())) {
                open = 1;
            }
            cur += ids.empty();
        }
        cout << min(n - 1, cur + *max_element(ans + 1, ans + n + 1)) << '\n';
    }
    return 0;
}