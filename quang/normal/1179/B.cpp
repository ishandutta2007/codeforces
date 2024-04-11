#include <bits/stdc++.h>

using namespace std;

const int N = 100010;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int l = 1, r = n;
    while (l < r) {
        int curL = 1;
        int curR = m;
        for (int i = 1; i <= m * 2; i++) {
            if (i & 1) {
                cout << l << ' ' << curL << '\n';
                curL++;
            } else {
                cout << r << ' ' << curR << '\n';
                curR--;
            }
        }
        l++;
        r--;
    }    
    if (l == r) {
        int curL = 1, curR = m;
        for (int i = 1; i <= m; i++) {
            if (i & 1) {
                cout << l << ' ' << curL << '\n';
                curL++;
            } else {
                cout << l << ' ' << curR << '\n';
                curR--;
            }
        }
    }
    return 0;
}