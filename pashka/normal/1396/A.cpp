#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << "1 1\n0\n1 1\n0\n1 1\n"<<-a[0] << "\n";
        return 0;
    }
    long aa = n;
    long bb = n - 1;
    long xa = 1;
    long ya = 0;
    long xb = 0;
    long yb = 1;
    while (bb) {
        long k = aa / bb;
        long aa1 = bb;
        long xa1 = xb;
        long ya1 = yb;
        long bb1 = aa - k * bb;
        long xb1 = xa - k * xb;
        long yb1 = ya - k * yb;
        aa = aa1;
        bb = bb1;
        xa = xa1;
        xb = xb1;
        ya = ya1;
        yb = yb1;
    }
    cout << "1 " << n << "\n";
    for (int i = 0; i < n - 1; i++) cout << -a[i] * xa * n << " ";
    cout << "0\n";
    cout << "1 " << n - 1 << "\n";
    for (int i = 0; i < n - 1; i++) cout << -a[i] * ya * (n - 1) << " ";
    cout << "\n";
    cout << n << " " << n << "\n";
    cout << -a[n - 1] << "\n";

    return 0;
}