#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

int v[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, u;
    ios::sync_with_stdio(false);
    cin >> n >> u;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int pos = 1;
    double ans = -1;
    for(i = 1; i <= n; i++) {
        while(pos <= n && v[pos] - v[i] <= u) {
            pos++;
        }
        pos--;
        if(pos > i + 1) {
            ans = max(ans, 1.0 * (v[pos] - v[i + 1]) / (v[pos] - v[i]));
        }
    }
    cout << fixed << setprecision(20) << ans;
    //cin.close();
    //cout.close();
    return 0;
}