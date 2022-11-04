#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const ll INF = 2e18;
const int MAXN = (int) 2e5 + 5;

ll a[MAXN + 1], b[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n / 2; i++) {
        cin >> b[i];
    }
    a[n + 1] = INF;
    for(i = 1; i <= n / 2; i++) {
        ll x = max(a[i - 1], b[i] - a[n - i + 2]);
        a[i] = x;
        a[n - i + 1] = b[i] - x;
    }
    for(i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}