#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n+1];
        for (int i = 1; i <= n; i++) cin >> a[i];
        int z[n+1];
        for (int i = 1; i <= n; i++) z[i] = 0;
        int e[n+1], f[n+1];
        for (int i = n; i >= 1; i--) {
            if (a[i] == 1) {
                e[i] = i-1;
                f[i] = 1;
                z[i] = 1;
                int g = 1;
                for (int j = i+1; j <= n; j++) {
                    if (z[j]) continue;
                    if (a[j] == g+1) {
                        g++;
                        z[j] = 1;
                        e[j] = i;
                        f[j] = 2;
                    } else break;
                }
            }
        }
        vector<int> v[n+1];
        v[1] = {1};
        for (int i = 2; i <= n; i++) {
            v[i] = v[e[i]];
            if (f[i] == 1) {
                v[i].push_back(1);
            } else {
                v[i][v[i].size()-1] = a[i];
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << v[i][0];
            for (int j = 1; j < v[i].size(); j++) {
                cout << "." << v[i][j];
            }
            cout << "\n";
        }
    }
}