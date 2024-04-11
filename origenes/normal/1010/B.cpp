#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 35;

int m, n, tags[maxn];


int main() {
    cin >> m >> n;
    REP(i, n) {
        cout << 1 << endl;
        cin >> tags[i];
        if (!tags[i]) return 0;
        tags[i] = (tags[i] == 1);
    }
    int l = 2, r = m, p = 0;
    while(r > l) {
        int now = (r - l) / 2 + l;
        cout << now << endl;
        int res;
        cin >> res;
        if (!res) return 0;
        if (!tags[p]) res = -res;
        p = (p + 1) % n;
        if (res == 1) l = now + 1;
        else r = now - 1;
    }
    int res;
    cout << l << endl;
    cin >> res;
    return 0;
}