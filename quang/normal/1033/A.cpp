#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int a[2], b[2], c[2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];
    cin >> c[0] >> c[1];
    if (((b[0] > a[0] && c[0] > a[0]) || (b[0] < a[0] && c[0] < a[0])) &&
        ((b[1] > a[1] && c[1] > a[1]) || (b[1] < a[1] && c[1] < a[1]))) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}