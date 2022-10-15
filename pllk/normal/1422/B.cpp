#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, m;
int t[111][111];

int main() {
    int z;
    cin >> z;
    while (z--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> t[i][j];
            }
        }
        ll r = 0;
        for (int i = 1; i <= (n+1)/2; i++) {
            for (int j = 1; j <= (m+1)/2; j++) {
                int y1 = i;
                int y2 = n-i+1;
                int x1 = j;
                int x2 = m-j+1;
                vector<int> v;
                v.push_back(t[y1][x1]);
                if (y1 != y2) {
                    v.push_back(t[y2][x1]);
                }
                if (x1 != x2) {
                    v.push_back(t[y1][x2]);
                }
                if (y1 != y2 && x1 != x2) {
                    v.push_back(t[y2][x2]);
                }
                ll p = 1e18;
                for (auto x : v) {
                    ll e = 0;
                    for (auto y : v) {
                        e += abs(x-y);
                    }
                    p = min(p,e);
                }
                r += p;
            }
        }
        cout << r << "\n";
    }
}