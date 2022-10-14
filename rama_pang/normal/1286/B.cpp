#include <bits/stdc++.h>
using namespace std;

int N;
int P[2005];
int C[2005];
vector<int> G[2005];
int R;
int pos;
int depth = -1;
int ans[2005];

void dfs(int n, int d = 0) {
    if (C[n] == 0) {
        if (depth < d) {
            pos = n;
            depth = d;
        }
        return;
    }
    for (auto &i : G[n]) {
        dfs(i, d + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> C[i];
        P[i]--;
        if (P[i] == -1) {
            R = i;
        } else {
            G[P[i]].emplace_back(i);
        }
    }

    for (int i = 0; i < N; i++) {
        pos = -1;
        depth = -1;
        dfs(R);
        if (pos == -1) {
            cout << "NO\n";
            return 0;
        }
        ans[pos] = i + 1;
        int cur = pos;
        while (cur != -1) {
            C[cur]--;
            cur = P[cur];
        }
    }

    cout << "YES\n";
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}