#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int d[101010];
int h[101010];
int u;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> d[i] >> h[i];
    }
    u = h[0]+(d[0]-1);
    u = max(u, h[m-1]+(n-d[m-1]));
    for (int i = 0; i < m-1; i++) {
        int a = h[i];
        int b = h[i+1];
        if (abs(a-b) > abs(d[i]-d[i+1])) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if (a > b) swap(a, b);
        u = max(u, b);
        int x = d[i+1]-d[i];
        x -= b-a;
        if (x <= 0) continue;
        u = max(u, b+x/2);
    }
    cout << u << "\n";
}