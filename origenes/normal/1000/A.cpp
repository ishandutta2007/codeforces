#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 123;

map<string, int> cnt;
int n;

int main() {
    cin >> n;
    REP(i, n) {
        string s;
        cin >> s;
        cnt[s]++;
    }
    REP(i, n) {
        string s;
        cin >> s;
        cnt[s]--;
    }
    int ans = 0;
    for (const auto &it : cnt) {
        if (it._2 > 0) ans += it._2;
    }
    cout << ans << endl;
    return 0;
}