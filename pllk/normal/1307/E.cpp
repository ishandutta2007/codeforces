#include <iostream>

using namespace std;

typedef long long ll;
#define M 1000000007

int n, m;
int s[5555];
int f[5555], h[5555];
int l[5555], r[5555];

ll z[5555][4];

int yy;
ll rr;

void calc(int k) {
    for (int i = 1; i <= n; i++) {
        z[i][1] = z[i][2] = z[i][3] = 0;
    }
    bool ok = k == 0;
    for (int i = 1; i <= m; i++) {
        if (l[i] != 0 && l[i] == k) {
            ok = 1;
            continue;
        }
        if (l[i] != 0 && r[i] != 0 && l[i] < k && r[i] > k && f[i] != s[k]) {
            z[f[i]][1]++;
        } else if (l[i] != 0 && l[i] < k && f[i] != s[k]) {
            z[f[i]][2]++;
        } else if (r[i] != 0 && r[i] > k) {
            z[f[i]][3]++;
        }
    }
    if (!ok) return;
    int y = k == 0 ? 0 : 1;
    ll r = 1;
    for (int i = 1; i <= n; i++) {
        ll u = 0;
        u += z[i][2]*(z[i][1]+z[i][3]);
        u += z[i][3]*(z[i][1]+z[i][2]);
        u += z[i][1]*(z[i][1]-1);
        if (u > 0) {
            y += 2;
            r = r*u%M;
            continue;
        }
        u = 0;
        u += 2*z[i][1];
        u += z[i][2];
        u += z[i][3];
        if (u > 0) {
            y++;
            r = r*u%M;
        }
    }
    if (y > yy) {
        yy = y;
        rr = r;
    } else if (y == yy) {
        rr += r;
        rr %= M;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= m; i++) cin >> f[i] >> h[i];
    for (int i = 1; i <= m; i++) {
        int u = h[i];
        for (int j = 1; j <= n; j++) {
            if (s[j] == f[i]) u--;
            if (u == 0) {l[i] = j; break;}
        }
        u = h[i];
        for (int j = n; j >= 1; j--) {
            if (s[j] == f[i]) u--;
            if (u == 0) {r[i] = j; break;}
        }
    }
    for (int i = 0; i <= n; i++) {
        calc(i);
    }
    cout << yy << " " << rr << "\n";
}