#include <iostream>

using namespace std;

int n;
int a[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int p = a[0], s = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < p) p = a[i];
        if (a[i] > s) s = a[i];
    }
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < s) t++;
        else break;
    }
    for (int i = t; i > 0; i--) a[i] = a[i-1];
    for (int i = n-1; i >= 0; i--) {
        if (a[i] > p) t++;
        else break;
    }
    cout << t << endl;
}