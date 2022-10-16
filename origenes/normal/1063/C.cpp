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
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 123456;

int n, inc = 1 << 28, now = 0;
string s, base;

int main() {
    cin >> n;
    n--;
    cout << "1 0" << endl;
    cin >> s;
    base = s;
    while (n--) {
        cout << 1 << ' ' << now + inc << endl;
        cin >> s;
        if (s == base) now = now + inc;
        inc >>= 1;
    }
    cout << 0 << ' ' << now << ' ' << 2 << ' ' << now + 1 << endl;
    return 0;
}