#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n, k;
    cin >> n >> k;
    LL cnt = 0,
       sum = 0;
    for (int i = 0; i < k; i++) {
        LL x, y;
        cin >> x >> y;
        x--;
        cnt += y;
        sum = (sum + x * y) % n;
    }
    if (cnt > n or (cnt == n and sum != n * (n - 1) / 2 % n))
        cout << -1 << endl;
    else
        cout << 1 << endl;
    return 0;
}