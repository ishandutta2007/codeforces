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

int n, a1, a2;

void query(int q) {
    cout << "? " << q << endl;
}

int main() {
    cin >> n;
    query(1);
    cin >> a1;
    query(1 + n / 2);
    cin >> a2;
    int diff = a1 - a2;
    if (diff & 1) {
        cout << "! -1" << endl;
        return 0;
    }
    if (!diff) {
        cout << "! 1" << endl;
        return 0;
    }
    int L = 2, R = n / 2;
    while (L <= R) {
        int M = L + R >> 1;
        query(M);
        cin >> a1;
        query(M + n / 2);
        cin >> a2;
        if (a1 == a2) {
            cout << "! " << M << endl;
            return 0;
        }
        ll(a1 - a2) * diff > 0 ? L = M + 1 : R = M - 1;
    }
    return -1;
}