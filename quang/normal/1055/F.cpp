#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n;
long long k;
long long w[N];
pair<int, int> endPos[N];

struct Data {
    int l, r;
    Data(int l = 0, int r = 0) : l(l), r(r) {}
};

pair<Data, Data> f[2][N];
int cnt[2];

int getMaxPosZero(int id, Data u) {
    for (int i = u.l; i <= u.r; i++) {
        if ((w[i] >> id) & 1) return i - 1;
    }
    return u.r;
}

long long mul(int u, int v) {
    return (long long)u * v;
}

void add(int cur, int &cntNow, Data u, Data v) {
    if (u.l > u.r || v.l > v.r) return;
    f[cur][++cntNow] = {u, v};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p >> w[i];
        w[i] ^= w[p];
    }
    sort(w + 1, w + n + 1);
    cnt[0] = 1;
    f[0][1] = {Data(1, n), Data(1, n)};
    long long res = 0;
    for (int i = 61, cur = 0; i >= 0; i--, cur ^= 1) {
        cnt[cur ^ 1] = 0;
        long long foo = 0;
        for (int j = 1; j <= cnt[cur]; j++) {
            endPos[j].first = getMaxPosZero(i, f[cur][j].first);
            endPos[j].second = getMaxPosZero(i, f[cur][j].second);
            foo += mul(endPos[j].first - f[cur][j].first.l + 1, endPos[j].second - f[cur][j].second.l + 1);
            foo += mul(f[cur][j].first.r - endPos[j].first, f[cur][j].second.r - endPos[j].second);
        }
        if (foo >= k) {
            int &cntNow = cnt[cur ^ 1];
            for (int j = 1; j <= cnt[cur]; j++) {
                add(cur ^ 1, cntNow, Data(f[cur][j].first.l, endPos[j].first), Data(f[cur][j].second.l, endPos[j].second));
                add(cur ^ 1, cntNow, Data(endPos[j].first + 1, f[cur][j].first.r), Data(endPos[j].second + 1, f[cur][j].second.r));
            }
        } else {
            res |= (1ll << i);
            int &cntNow = cnt[cur ^ 1];
            k -= foo;
            for (int j = 1; j <= cnt[cur]; j++) {
                add(cur ^ 1, cntNow, Data(f[cur][j].first.l, endPos[j].first), Data(endPos[j].second + 1, f[cur][j].second.r));
                add(cur ^ 1, cntNow, Data(f[cur][j].second.l, endPos[j].second), Data(endPos[j].first + 1, f[cur][j].first.r));
            }
        }
    }
    cout << res << endl;
    return 0;
}