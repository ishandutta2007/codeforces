#include <bits/stdc++.h>
using namespace std;

int n;
const int max_n = 1e6 + 1;
vector<int> gr[max_n];
bool used[max_n];
int good = -1;

void dfs(int v) {
    if (used[v]) return;
    used[v] = true;
    for(int i : gr[v]) dfs(i);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t-- > 0) {
        int m;
        cin >> n >> m;

        for(int i = 0;i < n;i++) {
            gr[i].clear();
            used[i] = false;
        }

        for(int i = 0;i < m;i++) {
            int v1, v2;
            cin >> v1 >> v2;
            gr[v2 - 1].emplace_back(v1 - 1);
        }
        for(int i = 0;i < n;i++) {
            if (!used[i]) {
                dfs(i);
                good = i;
            }
        }

        for(int i = 0;i < n;i++) used[i] = false;
        vector<int> q[n];
        for(int i = 0;i < n;i++) {
            for(int j : gr[i]) q[j].emplace_back(i);
        }
        for(int i = 0;i < n;i++) {
            gr[i] = q[i];
        }

        dfs(good);

        int cnt = 0;
        for(int i = 0;i < n;i++) if (used[i]) cnt++;
        if (cnt == n) cout << "No" << '\n';
        else{
            cout << "Yes" << '\n' << cnt << " " << n - cnt << '\n';

            for(int i = 0;i < n;i++) {
                if (used[i]) cout << i + 1 << " ";
            }
            cout << '\n';
            for(int i = 0;i < n;i++) {
                if (!used[i]) cout << i + 1 << " ";
            }
            cout << '\n';
        }
    }

}