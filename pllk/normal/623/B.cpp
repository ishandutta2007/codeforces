#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

int n, a, b;
int x[1010101];
int q;
set<int> s;

void lisaa(int x) {
    for (int k = 2; k*k <= x; k++) {
        if (x%k == 0) {
            s.insert(k);
            while (x%k == 0) x /= k;
        }
    }
    if (x != 1) s.insert(x);
}

ll d[1010101][3];
ll rr = -1;

void haku(int z) {
    if (z == 1) return;
    ll r = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2; j++) {
            d[i][j] = 99999999999999999LL;
            if (i == 1 && j == 1) {
                d[i][j] = 99999999999999999LL;
                continue;
            }
            int u = -1;
            ll v;
            if (j == 1) {
                ll x = d[i-1][1]+a;
                ll y = d[i-1][0]+a;
                d[i][j] = min(x,y);
                goto skip1;
            }
            if (x[i]%z == 0) u = 0;
            else if ((x[i]+1)%z == 0) u = b;
            else if ((x[i]-1)%z == 0) u = b;
            if (u == -1) continue;
            v = d[i-1][0]+u;
            if (j == 2) v = min(v,d[i-1][1]+u);
            if (j == 2) v = min(v,d[i-1][2]+u);
            d[i][j] = v;
            skip1:
            if (i == n && (r == -1 || d[i][j] < r)) r = d[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2; j++) {
            d[i][j] = 99999999999999999LL;
            if (i == n && j == 1) {
                d[i][j] = -1;
                continue;
            }
            int u = -1;
            ll v;
            if (j == 1) {
                ll x = d[i-1][1]+a;
                ll y = d[i-1][0]+a;
                d[i][j] = min(x,y);
                goto skip2;
            }
            if (x[i]%z == 0) u = 0;
            else if ((x[i]+1)%z == 0) u = b;
            else if ((x[i]-1)%z == 0) u = b;
            if (u == -1) continue;
            v = d[i-1][0]+u;
            if (j == 2) v = min(v,d[i-1][1]+u);
            if (j == 2) v = min(v,d[i-1][2]+u);
            d[i][j] = v;
            skip2:
            if (i == n && (r == -1 || d[i][j] < r)) r = d[i][j];
        }
    }
    if (rr == -1 || r < rr) rr = r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    lisaa(x[1]-1);
    lisaa(x[1]);
    lisaa(x[1]+1);
    lisaa(x[n]-1);
    lisaa(x[n]);
    lisaa(x[n]+1);
    for (auto x : s) haku(x);
    cout << rr << "\n";
}