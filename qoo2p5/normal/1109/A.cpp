#include <bits/stdc++.h>

#define rep(i, s, t) for (int i = s; i < t; i++)
#define per(i, s, t) for (int i = s; i >= t; i--)
#define sz(x) ((int)x.size())
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;

const int N = (int) (3e5 + 123);

int n;
int a[N];
int cnt[1 << 21][2];
int p[N];

int main() {
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    p[0] = a[0];
    rep(i, 1, n) p[i] = p[i - 1] ^ a[i];
    ll ans = 0;
    cnt[0][1] = 1;
    rep(i, 0, n) {
        ans += cnt[p[i]][i % 2];
        cnt[p[i]][i % 2]++;
    }
    cout << ans << "\n";

    return 0;
}