#include <bits/stdc++.h>
#define ld long double

using namespace std;

const int maxn = 100005;
const ld eps = 1e-9;

bool equal(ld x, ld y) {
    return abs(x-y) <= eps;
}

bool better(ld x, ld y) {
    return x-y > eps;
}

int n, d;
ld a[maxn];
int b[maxn];
int c[maxn];

ld f[maxn][10];
bool p[maxn][10];
int q[maxn][10];

int main() {

    for(int i = 0; i < maxn; ++i) {
        for(int j = 0; j < 10; ++j) {
            f[i][j] = (ld)-1e9;
        }
    }

    cin >> n >> d;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[i] = log(x);
        b[i] = x % 10;
        c[i] = x;
    }

    f[0][1] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 10; ++j) {
            if (f[i][j] < 0) continue;
            ld newer = f[i][j] + a[i];
            int newmod = (j * b[i]) % 10;


            if (better(newer, f[i+1][newmod])) {
                f[i+1][newmod] = newer;
                p[i+1][newmod] = 1;
                q[i+1][newmod] = j;
            }

            if (better(f[i][j], f[i+1][j])) {
                f[i+1][j] = f[i][j];
                p[i+1][j] = 0;
            }
        }
    }
    if (f[n][d] < 0) {
        cout << -1 << endl;
        exit(0);
    }

    vector<int> ans;
    int cur = n, v = d;

    for(int cur = n; cur > 0; --cur) {
        if (p[cur][v]) {
            ans.push_back(cur-1);
            v = q[cur][v];
        }
    }

    if (ans.size() == 0) {
        cout << -1 << endl;
        exit(0);
    }

    cout << ans.size() << endl;
    for(int x : ans) cout << c[x] << " ";
    cout << endl;

    return 0;
}