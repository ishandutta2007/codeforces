#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

set <int> g[MAXN + 1];
int lvl[MAXN + 1], deg[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k, x, y;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].insert(y);
        g[y].insert(x);
        deg[x]++;
        deg[y]++;
    }
    queue <int> Q;
    int cnt = 0;
    for(i = 1; i <= n; i++) {
        if(g[i].size() == 2) {
            cout << "No";
            return 0;
        }
        if(g[i].size() == 3) {
            cnt++;
        }
        if(g[i].size() == 1) {
            Q.push(i);
            lvl[i] = 1;
        }
    }
    if(cnt > 1) {
        cout << "No";
        return 0;
    }
    while(!Q.empty()) {
        int nod = Q.front();
        Q.pop();
        for(auto it : g[nod]) {
            g[it].erase(g[it].find(nod));
            if(lvl[it] == 0) {
                lvl[it] = lvl[nod] + 1;
            }
            else if(lvl[it] != lvl[nod] + 1) {
                cout << "No";
                return 0;
            }
            if(g[it].size() == 1) {
                Q.push(it);
            }
        }
    }
    /*for(i = 1; i <= n; i++) {
        cerr << i << " " << lvl[i] << "\n";
    }*/
    int nr = 0, id;
    for(i = 1; i <= n; i++) {
        nr += (lvl[i] == k + 1);
        if(lvl[i] == k + 1) {
            id = i;
        }
    }
    if(nr == 1) {
        if(cnt == 0 || (cnt == 1 && deg[id] == 3)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
    }
    else {
        cout << "No";
    }
    //cin.close();
    //cout.close();
    return 0;
}