#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 1000;

int a[MAXN + 1], x[MAXN + 1];
bool vis[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = n; i > 1; i--) {
        a[i] -= a[i - 1];
    }
    vector <int> sol;
    for(int k = 1; k <= n; k++) {
        memset(vis, 0, sizeof(vis));
        bool ok = 1;
        for(i = 1; i <= n; i++) {
            if(vis[(i - 1) % k] && x[(i - 1) % k] != a[i]) {
                ok = 0;
            }
            x[(i - 1) % k] = a[i];
            vis[(i - 1) % k] = 1;
        }
        if(ok == 1) {
            sol.push_back(k);
        }
    }
    cout << sol.size() << "\n";
    for(auto it : sol) {
        cout << it << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}