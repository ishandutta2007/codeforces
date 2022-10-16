#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

int n;

bool check(int mx, int cur, int now) {
    ll mn = mx - ll(n - 1) * now;
    if (mn < 0 || mn > cur) return false;
    cout << "! " << mn << ' ' << now << endl;
    return true;
}

int ask(int i) {
    int ret;
    cout << "? " << i << endl;
    cin >> ret;
    return ret;
}

pii query_max() {
    int l = 0, r = 1e9 - 1, cnt = 0;
    while (l < r) {
        int m = l + r + 1 >> 1;
        cout << "> " << m << endl;
        int ans;
        cin >> ans;
        if (!ans) r = m - 1;
        else l = m;
        cnt++;
    }
    return mp(l + 1, cnt);
}

int main() {
    cin >> n;
    mt19937 rand_generator;
    random_device rdev;
    rand_generator.seed(rdev());
//    REP(i, 100) {
//        uniform_int_distribution<int> rand_distribution(1, n);
//        cout << rand_distribution(rand_generator) << endl;
//    }
    pii tmp = query_max();
    int mx = tmp._1, used = tmp._2;
    vector<int> lis;
    FOR(i, 1, 60 - used) {
        uniform_int_distribution<int> rand_distribution(1, n);
        int now = rand_distribution(rand_generator);
        lis.eb(mx - ask(now));
    }
    sort(all(lis));
    int cur = mx - lis.back(), g = 0;
    set<int> s;
    REP(i, int(lis.size())) FOR(j, i, int(lis.size()) - 1) s.insert(lis[j] - lis[i]);
    for (auto it : s) g = __gcd(g, it);
    int upp = sqrt(g) + 0.5;
    FOR(i, 1, upp) if (g % i == 0) {
            bool flag = check(mx, cur, i);
            if (flag) return 0;
            if (i != g / i) flag = check(mx, cur, g / i);
            if (flag) return 0;
        }
    cout << "! " << cur << ' ' << mx - (mx - cur) / (n - 1) << endl;
}