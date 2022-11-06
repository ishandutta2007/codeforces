#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e6;

vector <int> g[MAXN + 1];
int fr[MAXN + 1], ans, k;
int vals[MAXN + 1];

void dfs(int nod, int par, int lvl) {
    int nr_son = 0;
    vector <int> arr;
    vals[nod] = -1;
    for(auto it : g[nod]) {
        if(it != par) {
            dfs(it, nod, lvl + 1);
            nr_son++;
        }
    }
    if(nr_son == 0) {
        vals[nod] = lvl;
        return ;
    }
    int mx1 = -1, mx2 = -1;
    for(auto it : g[nod]) {
        if(it != par) {
            vals[it] -= lvl;
            fr[vals[it]]++;
            mx1 = max(mx1, vals[it]);
        }
    }
    for(auto it : g[nod]) {
        if(it != par) {
            if(vals[it] != mx1) {
                mx2 = max(mx2, vals[it]);
            }
        }
    }
    int i;
    for(i = 1; i <= mx2; i++) {
        while(fr[i] > 0) {
            arr.push_back(i);
            fr[i]--;
        }
    }
    while(mx1 > -1 && fr[mx1] > 0) {
        arr.push_back(mx1);
        fr[mx1]--;
    }
    for(i = 0; i + 1 < arr.size(); i++) {
        if(arr[i] + arr[i + 1] > k) {
            vals[nod] = arr[i] + lvl;
            ans += arr.size() - (i + 1);
            break;
        }
    }
    if(vals[nod] == -1 && arr.size()) {
        vals[nod] = arr.back() + lvl;
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(i = 1; i <= n; i++) {
        if(g[i].size() > 1) {
            dfs(i, 0, 1);
            break;
        }
    }
    cout << ans + 1;
    //cin.close();
    //cout.close();
    return 0;
}