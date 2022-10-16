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

string s;
bool ok[5][5];

int main() {
    reset(ok, 1);
    cin >> s;
    for (auto ch : s) {
        if (ch == '0') {
            if (ok[1][4]) {
                ok[3][4] ? (ok[1][4] = false) : (ok[3][4] = true);
                cout << "1 4" << '\n';
            } else {
                assert(ok[3][4]);
                ok[1][4] ? (ok[3][4] = false) : (ok[1][4] = true);
                cout << "3 4" << '\n';
            }
        } else {
            FOR(i, 1, 4) if (ok[i][1]) {
                    ok[i][1] = false;
                    cout << i << " 1" << '\n';
                    break;
                }
            bool flag = true;
            FOR(i, 1, 4) if (ok[i][1]) {
                    flag = false;
                    break;
                }
            if (flag) FOR(i, 1, 4) ok[i][1] = true;
        }
    }
}