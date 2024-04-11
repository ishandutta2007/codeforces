#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); --(i))
#define REP(i, n) FOR(i, 0, (n) - 1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
using LL = long long;
using ll = long long;
using pii = pair<int, int>;

string s;
vector<pii> vec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    vec.pb({ s[0], 1 });
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) ++vec.back()._2;
        else {
            vec.pb({ s[i], 1 });
        }
    }

    int l = 0, r = vec.size() - 1;
    while (l < r) {
        if (vec[l]._1 != vec[r]._1) break;
        if (vec[l]._2 + vec[r]._2 < 3) break;
        ++l, --r;
    }
    if (l != r) cout << 0 << '\n';
    else if (vec[l]._2 < 2) cout << 0 << '\n';
    else cout << vec[l]._2 + 1 << '\n';
    return 0;
}