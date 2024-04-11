#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int n, k;

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> k;
    cout << (6 * n - 1) * k << endl;
    for(int i = 0; i < n; i++) {
        cout << (i * 6 + 1) * k << " " << (i * 6 + 2) * k << " " << (i * 6 + 3) * k << " " << (i * 6 + 5) *k << endl;
    }
    return 0;
}