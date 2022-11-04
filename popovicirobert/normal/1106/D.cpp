#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

vector <int> g[MAXN + 1];
bool vis[MAXN + 1];
priority_queue <int> pq;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, x, y;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    pq.push(-1);
    while(!pq.empty()) {
        int nod = -pq.top();
        pq.pop();
        if(vis[nod] == 1) {
            continue;
        }
        cout << nod << " ";
        vis[nod] = 1;
        for(auto it : g[nod]) {
            if(vis[it] == 0) {
                pq.push(-it);
            }
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}