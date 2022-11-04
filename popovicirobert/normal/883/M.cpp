#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int x1, y1, x2, y2;
    ios::sync_with_stdio(false);
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = 2 * ((abs(x1 - x2) + (x1 == x2) + 1) + (abs(y1 - y2) + (y1 == y2) + 1));
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}