#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n, m;
int a[5050];
unordered_set<int> b;

int aa[35000];
int xx[35000];
int xk;

int gcd(int x, int y) {
    if (x%y == 0) return y;
    return gcd(y, x%y);
}

int main() {
    for (int i = 2; i < 35000; i++) {
        if (aa[i]) continue;
        for (int j = 2*i; j < 35000; j += i) aa[j] = 1;
    }
    for (int i = 2; i < 35000; i++) {
        if (!aa[i]) xx[xk++] = i;
    }
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }
    for (int i = n; i >= 1; i--) {
        int g = a[0];
        for (int j = 0; j < i; j++) g = gcd(g, a[j]);
        int h = g;
        int c1 = 0, c2 = 0;
        for (int j = 0; j < xk && xx[j]*xx[j] <= h; j++) {
            while (h%xx[j] == 0) {
                if (b.count(xx[j])) c1++;
                else c2++;
                h /= xx[j];
            }
        }
        if (h > 1) {
            if (b.count(h)) c1++;
            else c2++;
        }
        if (c1 < c2) continue;
        for (int j = 0; j < i; j++) a[j] /= g;
    }
    int q = 0;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        int h = a[i];
        for (int j = 0; j < xk && xx[j]*xx[j] <= h; j++) {
            while (h%xx[j] == 0) {
                if (b.count(xx[j])) c1++;
                else c2++;
                h /= xx[j];
            }
        }
        if (h > 1) {
            if (b.count(h)) c1++;
            else c2++;
        }
    }
    cout << c2-c1 << endl;
}