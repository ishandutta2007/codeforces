#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int a, b, n, m;

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> m >> a >> b;
    if(a * m < b) {
        cout << n * a;
        return 0;
    }
    else {
        cout << min(b * (n / m) + a * (n % m), b * (int)ceil(1.0 * n / m));
    }
    return 0;
}