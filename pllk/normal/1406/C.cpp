#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v[101010];
int c[101010];
bool ok;

void dfs(int s, int e) {
    c[s]++;
    for (auto x : v[s]) {
        if (x == e) continue;
        dfs(x,s);
        c[s] += c[x];
        if (c[x] == n/2) {
            ok = true;
            int ue = s;
            int us = x;
            while (true) {
                bool w = false;
                for (auto x : v[us]) {
                    if (x != ue) {
                        ue = us;
                        us = x;
                        w = true;
                        break;
                    }
                }
                if (!w) break;
            }
            cout << ue << " " << us << "\n";
            cout << s << " " << us << "\n";
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            c[i] = 0;
        }
        for (int i = 1; i <= n-1; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        ok = false;
        if (n%2 == 0) dfs(1,0);
        if (!ok) {
            cout << 1 << " " << v[1].back() << "\n";
            cout << 1 << " " << v[1].back() << "\n";
        }
    }
}