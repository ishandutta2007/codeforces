#include <bits/stdc++.h>
#define MAXN 200000

using namespace std;

vector <int> g[MAXN + 1];

int lvl[MAXN + 1];

void dfs(int nod) {
    for(auto it : g[nod])
     if(lvl[it] == 0) {
         lvl[it] = lvl[nod] + 1;
         dfs(it);
     }
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i,n,k,x;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    i = k + 1;
    x = 1;
    while(i <= n - 1) {
        g[i - k].push_back(i);
        g[i].push_back(i - k);
        i++;
    }
    for(i = n - 1; i >= n - k; i--) {
        g[n].push_back(i);
        g[i].push_back(n);
    }
    lvl[n] = 1;
    dfs(n);
    sort(lvl + 1, lvl + n + 1, greater <int>());
    cout << lvl[1] + lvl[2] - 2 << endl;
    for(i = 1; i <= n; i++) {
        for(auto it : g[i])
            if(it > i)
               cout << i << " " << it << endl;
    }
    //cin.close();
    //cout.close();
    return 0;
}