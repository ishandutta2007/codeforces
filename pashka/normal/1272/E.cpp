#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        if (i - a[i] >= 0) {
            g[i - a[i]].push_back(i);
        }
        if (i + a[i] < n) {
            g[i + a[i]].push_back(i);
        }
    }
    
    vector<int> res(n, -1);
    
    for (int bb = 0; bb < 2; bb++) {
        vector<int> q;
        vector<int> d(n, -1);
        for (int i = 0; i < n; i++) {
            if ((a[i] & 1) == bb) {
                d[i] = 0;
                q.push_back(i);
            }
        }
        for (int i = 0; i < q.size(); i++) {
            int x = q[i];
            for (int y : g[x]) {
                if (d[y] == -1) {
                    d[y] = d[x] + 1;
                    q.push_back(y);
                }    
            }
        }
        for (int i = 0; i < n; i++) {
            if ((a[i] & 1) != bb) {
                res[i] = d[i];
            }
        }
    }
    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << "\n";
    

    return 0;
}