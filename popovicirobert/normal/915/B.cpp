#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 22

using namespace std;

const int INF = (int) 1e9;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, pos, l, r;
    ios::sync_with_stdio(false);
    cin >> n >> pos >> l >> r;
    int ans = INF;
    if(n > r) {
        if(l > 1) {
            ans = min(ans, abs(pos - l) + 1 + abs(r - l) + 1);
            ans = min(ans, abs(pos - r) + 1 + abs(r - l) + 1);
        }
        else {
            ans = min(ans, abs(pos - r) + 1);
        }
    }
    else {
        if(l > 1) {
            ans = min(ans, abs(pos - l) + 1);
        }
        else {
            ans = 0;
        }
    }

    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}