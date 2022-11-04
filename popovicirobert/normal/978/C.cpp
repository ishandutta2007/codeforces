#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

ll a[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ll b;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    while(m > 0) {
        m--;
        cin >> b;
        int res = 0;
        for(int step = 1 << 17; step; step >>= 1) {
            if(res + step <= n && a[res + step] < b) {
                res += step;
            }
        }
        cout << res + 1 << " " << b - a[res] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}