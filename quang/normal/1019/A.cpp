#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
const long long INF = (1ll << 60);

int n, m;
vector<int> c[N];

long long get(int u) {
    int add = u - c[1].size();
    priority_queue<int> q;
    long long res = 0ll;
    for (int i = 2; i <= m; i++) {
        int now = c[i].size() - u + 1;
        now = max(now, 0);
        now = min(now, (int)c[i].size());
        for (int j = 0; j < now; j++) {
            res += c[i][j];
            // cout << i << "  " << j << endl;
            // if (u == 1) {
            //     // cout << "db " << j << " " << i << endl;
            // }
            add--;
        }
        for (int j = now; j < c[i].size(); j++) {
            q.push(-c[i][j]);
        }
    }
    if (add < 0) {
        return INF;
    }
    while (!q.empty() && add--) {
        int foo = q.top();
        res -= foo;
        q.pop();
    }
    if (add > 0) {
        return INF;
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int id, u;
        scanf("%d %d", &id, &u);
        c[id].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        sort(c[i].begin(), c[i].end());
    }
    long long res = INF;
    for (int i = max(1, (int)c[1].size()); i <= n; i++) {
        res = min(res, get(i));
        // cout << i << " " << res << endl;
    }
    cout << res << endl;
    return 0;
}