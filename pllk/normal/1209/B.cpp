#include <iostream>

using namespace std;

int n;
int x[111];
int a[111], b[111];

int main() {
    cin >> n;
    string s;
    cin >> s;
    int r = 0;
    for (int i = 0; i < n; i++) {
        x[i+1] = s[i] == '1';
        r += x[i+1];
    }
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    int u = 0;
    for (int h = 0; h < 10000; h++) {
        u = max(u,r);
        for (int i = 1; i <= n; i++) {
            b[i]--;
            if (b[i] == 0) {
                if (x[i] == 0) r++;
                else r--;
                x[i] = 1-x[i];
                b[i] = a[i];
            }
        }
    }
    cout << u << "\n";
}