#include <bits/stdc++.h>

using namespace std;

const int N = 2010;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 2000;
    int k;
    cin >> k;
    cout << n << endl;
    cout << -1 << ' ';
    k += n;
    int INF = 1000000;
    for (int i = 2; i <= n; i++) {
        if (k > INF) {
            cout << INF << ' ';
            k -= INF;
        } else {
            cout << k << ' ';
            k = 0;
        }
    }
    cout << endl;
    return 0;
}