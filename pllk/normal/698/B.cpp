#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
int p[202020];
int z[202020];
int u;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    int w = 0;
    for (int i = 1; i <= n; i++) {
        if (i == p[i]) w = i;
    }
    for (int i = 1; i <= n; i++) {
        if (z[i]) continue;
        int x = i;
        while (true) {
            z[x] = i;
            x = p[x];
            if (z[x]) {
                if (z[x] != i) break;
                if (w == 0) w = x;
                if (p[x] != w) u++;
                p[x] = w;
                break;
            }
        }
    }
    cout << u << "\n";
    for (int i = 1; i <= n; i++) cout << p[i] << " ";
    cout << "\n";
}