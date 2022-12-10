#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define sz(x) ((int)(x).size())
#define smax(x, y) (x) = max((x), (y))
#define smin(x, y) (x) = min((x), (y))
#define L first
#define R second
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0)
            a[i] = -a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int le = 0, ri = 0;
        for (int j = 0; j < i; j++)
            le += a[j] < a[i];
        for (int j = i + 1; j < n; j++)
            ri += a[j] < a[i];
        ans += min(le, ri);
    }
    cout << ans << '\n';
    return 0;
}