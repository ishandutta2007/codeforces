#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 1e6;

vector <int> g[MAXN + 1];
int lvl[MAXN + 1];

map <int, int> fr[MAXN + 1];
pair <int, int> sol[MAXN + 1];

void dfs(int nod) {
    fr[nod][lvl[nod]]++;
    sol[nod] = {1, lvl[nod]};
    for(auto it : g[nod]) {
        if(lvl[it] == 0) {
            lvl[it] = lvl[nod] + 1;
            dfs(it);
            if(sol[nod].first < sol[it].first || (sol[nod].first == sol[it].first && sol[nod].second > sol[it].second)) {
                sol[nod] = sol[it];
            }
        }
    }
    for(auto it : g[nod]) {
        if(lvl[it] > lvl[nod]) {
            if(fr[it].size() > fr[nod].size()) {
                swap(fr[it], fr[nod]);
            }
            for(auto itr : fr[it]) {
                fr[nod][itr.first] += itr.second;
                int nr = fr[nod][itr.first];
                if(nr > sol[nod].first || (nr == sol[nod].first && sol[nod].second > itr.first)) {
                    sol[nod] = {nr, itr.first};
                }
            }
            fr[it].clear();
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    lvl[1] = 1;
    dfs(1);
    for(i = 1; i <= n; i++) {
        cout << sol[i].second - lvl[i] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}