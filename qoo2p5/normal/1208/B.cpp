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

const int N = 2005;

int n;
int a[N];

void run() {
    map<int, int> q;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        q[a[i]]++;
    }
    if (sz(q) == n) {
        cout << "0\n";
        return;
    }
    int ans = n;
    rep(i, 0, n) {
        q.clear();
        rep(j, 0, n) {
            q[a[j]]++;
        }
        int cnt = 0;
        rep(j, i, n) {
            cnt++;
            q[a[j]]--;
            if (q[a[j]] == 0) {
                q.erase(a[j]);
            }
            if (sz(q) == n - cnt) {
                mini(ans, cnt);
            }
        }
    }
    cout << ans << "\n";
}