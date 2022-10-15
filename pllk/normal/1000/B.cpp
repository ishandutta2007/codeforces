#include <iostream>

using namespace std;

int p[101010];
int a[101010];

int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        p[i] = x;
    }
    p[n+1] = m;
    for (int i = n; i >= 0; i--) {
        if (i%2 == 1) {
            a[i] = a[i+1];
        } else {
            a[i] = p[i+1]-p[i]+a[i+1];
        }
    }
    int b = 0, h = 0;
    for (int i = 0; i <= n; i++) {
        if (i%2 == 1) b += p[i]-p[i-1];
        int x, y;
        if (i%2 == 0) {
            x = 1+m-p[i+1]-a[i+1];
            y = 1+m-p[i]-a[i];
        } else {
            x = p[i+1]-p[i]-1+m-p[i+1]-a[i+1];
            y = -1+m-p[i]-a[i];
        }
        if (p[i+1]-p[i] > 1) {
            h = max(h,b+x);
        }
        if (i != 0 && p[i]-p[i-1] > 1) {
            h = max(h,b+y);
        }
    }
    if ((n+1)%2 == 1) b += m-p[n];
    h = max(h,b);
    cout << h << "\n";
}