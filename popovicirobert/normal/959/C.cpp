#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

inline void out(int x, int y) {
    cout << x << " " << y << "\n";
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    if(n < 6) {
        cout << -1 << "\n";
    }
    else {
        out(1, 2);
        out(1, 3);
        out(1, 4);
        for(i = n; i > 4; i--) {
            out(i, 3);
        }
    }
    for(i = 2; i <= n; i++) {
        out(i - 1, i);
    }
    //cin.close();
    //cout.close();
    return 0;
}