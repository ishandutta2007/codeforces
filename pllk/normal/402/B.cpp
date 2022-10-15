#include <iostream>

using namespace std;

int n, k;
int a[1010];
int p = 999999999;
int v;

int laske(int x) {
    int c;
    for (int i = 0; i < n; i++) {
        if (a[i] != x) c++;
        x += k;
    }
    return c;
}

void nayta(int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] < x) cout << "+ " << i+1 << " " << x-a[i] << endl;
        if (a[i] > x) cout << "- " << i+1 << " " << a[i]-x << endl;
        x += k;
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= 1000; i++) {
        if (laske(i) < p) {
            p = laske(i);
            v = i;
        }
    }
    cout << p << endl;
    nayta(v);
}