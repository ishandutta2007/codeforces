#include <iostream>

using namespace std;

int n, m;
int a[1000], b[1000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x-1] = 1;
        b[y-1] = 1;
    }
    int t = 0;
    for (int i = 1; i < n-1; i++) {
        if (!a[i]) t++;
        if (!b[i]) t++;
    }
    if (n%2 == 1 && !a[n/2] && !b[n/2]) t--;
    cout << t << endl;
}