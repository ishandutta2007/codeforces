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

string now;

void query(int x) {
    cout << "? " << x << ' ' << 2 * x << endl;
}

void query(int b, int inc) {
    cout << "? " << b << ' ' << inc + b << endl;
}

int main() {
    while (cin >> now) {
        if (now == "end") return 0;
        if (now == "start") {
            cout << "? 0 1" << endl;
            cin >> now;
            if (now == "x") {
                cout << "! 1" << endl;
                continue;
            }
            int l = 1, r = 2;
            while (true) {
                query(l);
                cin >> now;
                if (now == "x") break;
                l <<= 1, r <<= 1;
            }
            while (l + 1 < r) {
                int m = l + r >> 1;
                query(l, m - l);
                cin >> now;
                if (now == "x") r = m;
                else l = m;
            }
            cout << "! " << r << endl;
        }
    }
}