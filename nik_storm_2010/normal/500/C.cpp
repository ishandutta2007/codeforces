#include <iostream>

using namespace std;
const int N = 1e5;

int w[N], b[N], pos[N];
bool used[N];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        b[m + i] = i;
    int cnt{0};
    for (int i = 1; i <= n + m; i++) {
        if (used[b[i]])
            continue;
        used[b[i]] = true;
        pos[++cnt] = b[i];
    }
    int ans{0};
    for (int t = 1; t <= m; t++) {
        int nom;
        for (int i = 1; i <= n; i++)
            if (pos[i] == b[t])
                nom = i;
        for (int i = nom; i > 1; i--) {
            ans += w[pos[i - 1]];
            pos[i] = pos[i - 1];
        }
        pos[1] = b[t];
    }
    cout << ans << "\n";
    return 0;
}