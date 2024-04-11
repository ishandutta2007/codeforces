#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int n, k;

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> k;
    if(n == 1) {
        cout << (k? -1: 1);
        return 0;
    }
    if(k < n / 2) {
        cout << -1;
        return 0;
    }
    int sl = k - (n / 2 - 1);
    cout << sl << " " << sl * 2 << " ";
    for(int i = 3; i <= n; i++) cout << 900000000 + i << " ";
    return 0;
}