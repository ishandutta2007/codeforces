#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, t) for (int i = s; i < t; i++)
#define per(i, s, t) for (int i = s; i >= t; i--)
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);

template<typename A, typename B> bool mini(A& x, const B& y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A& x, const B& y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

bool test(int mask, int bit) {
    return mask & (1 << bit);
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(12);
    run();
    return 0;
}

const int N = 1005;
int a[N];
string s[N];
map<char, int> cnt[N];

void run() {
    int n, m;
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> s[i];
        rep(j, 0, m) {
            cnt[j][s[i][j]]++;
        }
    }
    int ans = 0;
    rep(i, 0, m) {
        cin >> a[i];
        int c = 0;
        for (auto& it : cnt[i]) maxi(c, it.second);
        ans += c * a[i];
    }
    cout << ans << "\n";
}