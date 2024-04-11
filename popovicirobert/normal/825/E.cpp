#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

vector <int> g[MAXN + 1];
int deg[MAXN + 1];

priority_queue <int> pq;
int sol[MAXN + 1];

int main() {
    //fstream cin("B.in");
    //ofstream cout("B.out");
    int i, n, m, x, y;
    cin >> n >> m;
    for(i = 1; i <= m; i++) {
        cin >> x >> y;
        g[y].push_back(x);
        deg[x]++;
    }
    for(i = 1; i <= n; i++)
        if(deg[i] == 0)
           pq.push(i);
    int cnt = n;
    while(!pq.empty()) {
        int nod = pq.top();
        pq.pop();
        sol[nod] = cnt;
        cnt--;
        for(auto it : g[nod]) {
            deg[it]--;
            if(deg[it] == 0)
                pq.push(it);
        }
    }
    for(i = 1; i <= n; i++)
        cout << sol[i] << " ";
    //cin.close();
    //cout.close();
    return 0;
}