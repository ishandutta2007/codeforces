#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> vis(3 * N + 100), visE(M + 100);
        vector<int> U(M + 100), V(M + 100);
        int match = 0;
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            U[i] = u, V[i] = v;
            if (vis[u] == 0 && vis[v] == 0) {
                match++;
                vis[u] = 1;
                vis[v] = 1;
                visE[i] = 1;
            }
        }

        if (match >= N) {
            cout << "Matching\n";
            int cnt = 0;
            for (int i = 0; i < M; i++) if (visE[i] == 1) {
                cnt++;
                cout << i + 1 << " ";
                if (cnt == N) break;
            }
            cout << "\n";
            continue;
        } else {
            vector<int> ans;
            for (int i = 1; i <= 3 * N; i++) {
                if (vis[i] == 0) ans.emplace_back(i);
            }
            
            cout << "IndSet\n";
            for (int i = 0; i < N; i++) {
                cout << ans[i] << " ";
            }
            cout << "\n";
            continue;
        }


    }   
}