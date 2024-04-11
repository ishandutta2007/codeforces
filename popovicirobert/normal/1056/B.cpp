#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

inline ll get(int n, int m, int r) {
    if(r == 0) {
        return n / m;
    }
    else {
        return (n - r) / m + 1;
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>> n >> m;
    ll ans = 0;
    for(i = 0; i < min(n + 1, m); i++) {
        for(j = 0; j < min(n + 1, m); j++) {
            if((i * i + j * j) % m == 0) {
                ans += 1LL * get(n, m, i) * get(n, m, j);
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}