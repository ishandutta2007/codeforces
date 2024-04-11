#include <iostream>

using namespace std;

int n;
int t[101010];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) {
        int u1 = 2020202020;
        int u2 = -2020202020;
        if (i > 1) u1 = min(u1,t[i]-t[i-1]);
        if (i < n) u1 = min(u1,t[i+1]-t[i]);
        if (i != 1) u2 = max(u2,t[i]-t[1]);
        if (i != n) u2 = max(u2,t[n]-t[i]);
        cout << u1 << " " << u2 << "\n";
    }
}