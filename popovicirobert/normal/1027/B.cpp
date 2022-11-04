#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

int n;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int q;
    ios::sync_with_stdio(false);
    cin >> n >> q;
    while(q > 0) {
        q--;
        int x, y;
        cin >> x >> y;
        ll ans;
        if((x + y) % 2 == 0) {
            ans = (1LL * (x - 1) * n + y + 1) / 2;
        }
        else {
            ans = (1LL * n * n + 1) / 2 + (1LL * (x - 1) * n + y + 1) / 2;
        }
        cout << ans << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}