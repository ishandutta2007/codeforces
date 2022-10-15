#include <iostream>

using namespace std;

int p1[202020];
int p2[202020];

int main() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[j]) {
            p1[j] = i;
            j++;
        }
        if (j == m) break;
    }
    j = m-1;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == b[j]) {
            p2[j] = i;
            j--;
        }
        if (j == -1) break;
    }
    int r = 0;
    for (int i = 0; i < m-1; i++) {
        r = max(r, p2[i+1]-p1[i]);
    }
    cout << r << "\n";
}