#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, ln, lm;

vector<int> now;
int ans;
bool used[7];
int rec(int rest) {
    if (!rest) {
        ll tmp = 0;
        for (int i = 0; i < ln; ++i) {
            tmp = tmp * 7 + now[i];
        }
        if (tmp >= n) {
            return 0;
        }
        tmp = 0;
        for (int i = 0; i < lm; ++i) {
            tmp = tmp * 7 + now[ln + i];
        }
        if (tmp >= m) {
            return 0;
        }
        ++ans;
        return 0;
    }
    for (int i = 0; i < 7; ++i) {
        if (!used[i]) {
            used[i] = true;
            now.puba(i);
            rec(rest - 1);
            used[i] = false;
            now.pop_back();
        }
    }
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &m);

    ln = 0;
    int tmp = n - 1;
    while (tmp) {
        ++ln;
        tmp /= 7;
    }
    ln = max(ln, 1);
    
    lm = 0;
    tmp = m - 1;
    while (tmp) {
        ++lm;
        tmp /= 7;
    }
    lm = max(lm, 1);

    //cerr << ln << " " << lm << endl;
    
    if (ln + lm > 7) {
        cout << 0 << "\n";
        return 0;
    }

    rec(ln + lm);

    cout << ans << "\n";

    return 0;
}