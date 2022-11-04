#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;

void run() {
    int n;
    cin >> n;
    
    int left = -INF;
    int right = INF;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        int c, d;
        cin >> c >> d;
        if (d == 1) {
            left = max(left, 1900 - sum);
        } else if (d == 2) {
            right = min(right, 1899 - sum);
        }
        sum += c;
    }
    
    if (left > right) {
        cout << "Impossible\n";
    } else if (right == INF) {
        cout << "Infinity\n";
    } else {
        cout << sum + right << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}