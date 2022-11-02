#include <bits/stdc++.h>
using namespace std;
  
//#define _GLIBCXX_DEBUG
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) a.begin(), a.end()
#define mp make_pair
#define pb emplace_back
#define ld long double
 
mt19937 rnd;
int rand(int a) { return (rnd() % a + a) % a; }
 
const int inf = 1e9 + 2;
const int max_n = 5e5 + 3;

int n;
bitset<max_n> b[64];

int gauss() {
    int id = 60;
    for (int i = 0; i < n; ++i) {
        for (int tmp = id; tmp >= 0; --tmp) {
            if (b[tmp][i]) { swap(b[tmp], b[id]); break; }
        }

        if (b[id][i]) {
            for (int k = 0; k < 60; ++k) {
                if (k != id && b[k][i]) {
                    b[k] ^= b[id];
                }
            }
            --id;
            if (id < 0)  break;
        }
    }

    for (int i = id; i >= 0; --i) {
        if (b[i][n]) return -1;
    }
    return n - (60 - id);
}

void run() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int a1, a2;
        cin >> a1 >> a2;
        sum ^= a1;
        a1 ^= a2;
        for (int j = 0; j < 60; ++j)
            b[j][i] = (a1 >> j & 1);
    }
    for (int i = 0; i < 60; ++i)
        b[i][n] = (sum >> i & 1);

    int tmp = gauss();
    if (tmp == -1) cout << "1/1" << endl;
    else {
        int res = 1;
        for (int i = 0; i < n - tmp; ++i)
            res *= 2;
        cout << res - 1 << "/" << res << endl;
    }
} 
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while(t--) run();
}