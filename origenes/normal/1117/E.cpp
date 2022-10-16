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

string s[3], t, o[3];

int main() {
    cin >> t;
    int n = t.size();
    REP(i, n) {
        char now[3] = {'a' + i % 26, 'a' + i / 26 % 26, 'a' + i / 26 / 26};
        REP(j, 3) s[j] += now[j];
    }
    REP(i, 3) {
        cout << "? " << s[i] << endl;
        cin >> o[i];
    }
    string ans(n, 0);
    REP(i, n) {
        int now = 0;
        REP(j, 3) {
            int cur = o[j][i] - 'a';
            REP(k, j) cur *= 26;
            now += cur;
        }
        ans[now] = t[i];
    }
    cout << "! " << ans << endl;
}