#include <iostream>
#include <vector>

using namespace std;

int a[101010];
int b[101010];
int c[101010];

vector<int> fa[101010];
vector<int> fb[101010];
int r[101010];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        for (int i = 1; i <= m; i++) cin >> c[i];
        for (int i = 1; i <= n; i++) {
            fa[i].clear();
            fb[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == b[i]) fa[a[i]].push_back(i);
            else fb[b[i]].push_back(i);
        }
        int k = 0;
        bool f = false;
        for (int i = m; i >= 1; i--) {
            if (fb[c[i]].size()) {
                r[i] = fb[c[i]].back();
                fb[c[i]].pop_back();
                k = r[i];
            } else if (fa[c[i]].size()) {
                r[i] = fa[c[i]].back();
                k = r[i];
            } else if (k != 0) {
                r[i] = k;
            } else {
                f = true;
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (fb[i].size()) f = true;
        }
        if (f) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 1; i <= m; i++) cout << r[i] << " ";
        cout << "\n";
        
    }
}