#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a(51);
vector<int> v(51);
int sz = 0;

void dfs(int now) {
      v[now] = 1;
      for (int i = 0; i < a[now].size(); i++) {
            if (v[a[now][i]]) continue;
            else {
                  dfs(a[now][i]);
            }
      }
}

int main() {
      int n, m;
      cin >> n >> m;
      while (m--) {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
      }
      for (int i = 1; i<=n; i++) {
            if (v[i]) continue;
            sz++;
            dfs(i);
      }
      cout << (1LL<<(n - sz));
}