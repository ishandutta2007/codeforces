#include <iostream>

using namespace std;

typedef long long ll;

int n, k;
int t[505][505];
int c;
ll u;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k-1; j++) {
            t[i][j] = ++c;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = k; j <= n; j++) {
            t[i][j] = ++c;
            if (j == k) u += c;
        }
    }
    cout << u << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << t[i][j] << " ";
        }
        cout << "\n";
    }
}