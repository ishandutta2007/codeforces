#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

vector <int> g[MAXN + 1];
int cnt[MAXN + 1];

void dfs(int nod) {
    int son = 0;
    for(auto it : g[nod]) {
        dfs(it);
        cnt[nod] += cnt[it];
        son++;
    }
    cnt[nod] += (son == 0);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 2; i <= n; i++) {
        int par;
        cin >> par;
        g[par].push_back(i);
    }
    dfs(1);
    sort(cnt + 1, cnt + n + 1);
    for(i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}