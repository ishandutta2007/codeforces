#include <bits/stdc++.h>

using namespace std;

inline bool ok(int x, int p) {
    int d = 2;
    int mn = x;
    while(d * d <= x) {
        if(x % d == 0) {
            mn = min(mn, d);
        }
        while(x % d == 0) {
            x /= d;
        }
        d++;
    }
    if(x > 1) {
        mn = min(mn, x);
    }
    return mn <= p;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int p, y;
    ios::sync_with_stdio(true);
    cin >> p >> y;
    int cnt = 0;
    while(y > 0 && ok(y, p)) {
        y--;
        cnt++;
        if(cnt > 300)
            break;
    }
    if(ok(y, p))
        y = 0;
    if(y == 0)
        y--;
    cout << y;
    //cin.close();
    //cout.close();
    return 0;
}